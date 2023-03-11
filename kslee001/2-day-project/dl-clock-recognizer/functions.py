from loadlibs import *
import modules

def folder_to_dataframe(directory):
    data = []
    for name in os.listdir(directory):
        cur_hour = name.split("-")[0]
        cur_min  = name.split("-")[1]
        cur_files = glob.glob(f"{directory}/{name}/*.jpg")
        for file in cur_files:
            data.append([file, cur_hour, cur_min])
    
    dataframe = pd.DataFrame(data)
    dataframe.columns = ['path', 'hour', 'min']
    dataframe['path'] = dataframe['path'].str.replace("\\", "/", regex=False)
    
    return dataframe


def prepare_data(configs):
    train_folder = configs['TRAIN_FOLDER']
    test1_folder = configs['TEST1_FOLDER']
    test2_folder = configs['TEST2_FOLDER']
    train = folder_to_dataframe(train_folder)
    test1 = folder_to_dataframe(test1_folder)
    test2 = folder_to_dataframe(test2_folder)
    
    return train, test1, test2

def prepare_loaders(configs, train, test1, test2):
    # get data
    train, val = train_test_split(train, test_size=configs['TEST_SIZE'], random_state=configs['SEED'])

    # get data loaders
    if configs['AUGMENTATION'] == False:
        train_loader = DataLoader(
            modules.BaseDataset(train, configs['SIZE'], mode='train'),
            batch_size = configs['BATCH_SIZE'],
        #     num_workers = configs['NUM_WORKERS'],
            shuffle=True,
        )
    else:
        # concat dataset
        train_dataset = torch.utils.data.ConcatDataset(
            [modules.BaseDataset(train, configs['SIZE'], mode='train', aug=angle*90) for angle in range(4)]
        )
        train_loader = DataLoader(
            train_dataset,
            batch_size = configs['BATCH_SIZE'],
        #     num_workers = configs['NUM_WORKERS'],
            shuffle=True,
        )

    val_loader = DataLoader(
        modules.BaseDataset(val, configs['SIZE'], mode='val'),
        batch_size = configs['BATCH_SIZE'],
    #     num_workers = configs['NUM_WORKERS'],
        shuffle=False,
    )
    test1_loader = DataLoader(
        modules.BaseDataset(test1, configs['SIZE'], mode='test'),
        batch_size = configs['BATCH_SIZE'],
    #     num_workers = configs['NUM_WORKERS'],
        shuffle=False,
    )
    test2_loader = DataLoader(
        modules.BaseDataset(test2, configs['SIZE'], mode='test'),
        batch_size = configs['BATCH_SIZE'],
    #     num_workers = configs['NUM_WORKERS'],
        shuffle=False,
    )
    return train_loader, val_loader, test1_loader, test2_loader





def train_fn(configs, model, criterion1, criterion2, optimizer, scheduler, train_loader, val_loader):
    def forward_step(batch):
        x, y1, y2 = batch
        x = x.to(configs['DEVICE'])
        y1 = y1.to(configs['DEVICE'])
        y2 = y2.to(configs['DEVICE'])

        hours, mins = model(x)
        loss1 = criterion1(hours, y1)
        loss2 = criterion2(mins, y2)
        loss = loss1+loss2
        return loss, hours, mins 


    train_loss_tracker = []
    valid_loss_tracker = []
    valid_acc_tracker  = []

    best_loss = 999999
    best_acc  = 0.0
    best_model = None

    model = model.to(configs['DEVICE'])
    # parallel train check
    if configs['NUM_GPUS']>=1:
        print("--current device : CUDA")
    if configs['NUM_GPUS'] >1:
        model = torch.nn.DataParallel(model)
        print(f"--distributed training : {['cuda:'+str(i) for i in range(torch.cuda.device_count())]}")
    
    criterion1 = criterion1.to(configs['DEVICE'])
    criterion2 = criterion2.to(configs['DEVICE'])

    for epoch in range(1, configs['EPOCHS']+1):
        # train stage
        model.train()
        train_loss = []
        train_iterator = tq(train_loader) if configs['TQDM'] else train_loader
        for batch in train_iterator:
            optimizer.zero_grad()
            loss, _, _ = forward_step(batch)
            loss.backward()
            optimizer.step()
            train_loss.append(loss.item())
            
        if scheduler is not None:
            scheduler.step()
            
        # validation stage
        model.eval()
        val_loss = []
        labels = []
        preds  = []
        val_iterator =  tq(val_loader) if configs['TQDM'] else val_loader
        val_n = 0
        with torch.no_grad():
            for batch in val_iterator:
                loss, hours, mins = forward_step(batch)
                val_n += hours.shape[0]
                val_loss.append(loss.item())
                
                
                # labels
                y1 = batch[1].detach().cpu().numpy().astype(str).tolist()
                y2 = batch[2].detach().cpu().numpy().astype(str).tolist()
                label = [ h_gt.zfill(2) + m_gt.zfill(2) for h_gt, m_gt in zip(y1, y2) ]
                labels.extend(label)
                
                # preds
                hours_pred = hours.argmax(1)
                # hours_pred.add_(1) # validation 에서는 +1 해줄 필요 없음 
                hours_pred = hours_pred.detach().cpu().numpy().astype(str).tolist()
                mins_pred  = mins .argmax(1).detach().cpu().numpy().astype(str).tolist()
                pred  = [ h_pr.zfill(2) + m_pr.zfill(2) for h_pr, m_pr in zip(hours_pred, mins_pred) ]
                preds.extend(pred)

        # accuracy
        acc = accuracy_score(label, pred)
        
        if acc > best_acc:
            best_acc = acc
            best_model = model
            
        train_loss = round(np.mean(train_loss), 4)
        val_loss   = round(np.mean(val_loss)  , 4)
        val_acc    = round(acc, 4)
        print(f"-- EPOCH {epoch} --")
        print(f"training   loss : {train_loss}")
        print(f"validation loss : {val_loss}")
        print(f"validation size : {val_n}")
        print(f"current val acc  : {val_acc}")
        print(f"best val acc     : {round(best_acc, 4)}")
        print(f"labels (first 5 items)  : {labels[:5]}")
        print(f"preds  (first 5 items)  : {preds[:5]}")
        train_loss_tracker.append(train_loss)
        valid_loss_tracker.append(val_loss)
        valid_acc_tracker.append(val_acc)
        
    
    return best_model, train_loss_tracker, valid_loss_tracker, valid_acc_tracker


def inference(configs, model, test_loader):
    def forward_step(batch):
        x, y1, y2 = batch
        x = x.to(configs['DEVICE'])
        hours, mins = model(x)
        return hours, mins 
    
    model = model.to(configs['DEVICE'])
    test_iterator = tq(test_loader) if configs['TQDM'] else test_loader

    hours_preds  = []
    mins_preds   = []
    with torch.no_grad():
        for batch in test_iterator:
            hours, mins = forward_step(batch) # predictions
            
            # store predictions
            hours_pred = hours.argmax(1)
            hours_pred.add_(1) #[0, 11] range to [1,12] range
            hours_pred = hours_pred.detach().cpu().numpy().astype(str).tolist()
            hours_pred = [h_pr.zfill(2) for h_pr in hours_pred]
            hours_preds.extend(hours_pred)
            
            mins_pred  = mins .argmax(1).detach().cpu().numpy().astype(str).tolist()
            mins_pred  = [m_pr.zfill(2) for m_pr in mins_pred]
            mins_preds.extend(mins_pred)

        
    return hours_preds, mins_preds
