from loadlibs import *
from modules import *
from cfg import *


def prepare_data():
    train_folder = './data/train'
    train_data = []
    for name in os.listdir(train_folder):
        cur_hour = name.split("-")[0]
        cur_min  = name.split("-")[1]
        cur_files = glob.glob(f"{train_folder}/{name}/*.jpg")
        for file in cur_files:
            train_data.append([file, cur_hour, cur_min])

    train = pd.DataFrame(train_data)
    train.columns = ['path', 'hour', 'min']
    train['path'] = train['path'].str.replace("\\", "/", regex=False)

    test1_folder = './data/test1'
    test1_data = []
    for name in os.listdir(test1_folder):
        cur_hour = name.split("-")[0]
        cur_min  = name.split("-")[1]
        cur_files = glob.glob(f"{test1_folder}/{name}/*.jpg")
        for file in cur_files:
            test1_data.append([file, cur_hour, cur_min])

    test1 = pd.DataFrame(test1_data)
    test1.columns = ['path', 'hour', 'min']
    test1['path'] = test1['path'].str.replace("\\", "/", regex=False)


    test2_folder = './data/test2'
    test2_data = []
    for name in os.listdir(test2_folder):
        cur_hour = name.split("-")[0]
        cur_min  = name.split("-")[1]
        cur_files = glob.glob(f"{test2_folder}/{name}/*.jpg")
        for file in cur_files:
            test2_data.append([file, cur_hour, cur_min])

    test2 = pd.DataFrame(test2_data)
    test2.columns = ['path', 'hour', 'min']
    test2['path'] = test2['path'].str.replace("\\", "/", regex=False)

    return train, test1, test2


def train_fn(configs, model, criterion, optimizer, scheduler, train_loader, val_loader):
    def forward_step(batch):
        x, y1, y2 = batch
        x = x.to(configs['DEVICE'])
        y1 = y1.unsqueeze(1).to(configs['DEVICE'])
        y2 = y2.unsqueeze(1).to(configs['DEVICE'])

        hours, mins = model(x)
        loss1 = criterion(hours, y1)
        loss2 = criterion(mins, y2)
        loss = loss1+loss2
        return loss, hours, mins 

    best_loss = 999999
    best_acc  = 0.0
    best_model = None

    model = model.to(configs['DEVICE'])
    criterion = criterion.to(configs['DEVICE'])

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
        with torch.no_grad():
            for batch in val_loader:
                loss, hours, mins = forward_step(batch)
                val_loss.append(loss.item())
                
                # labels
                hours = batch[1].detach.cpu().numpy().astype(str).tolist()
                mins  = batch[2].detach.cpu().numpy().astype(str).tolist()
                label = [ h_gt + m_gt for h_gt, m_gt in zip(hours, mins) ]
                labels.extend(label)
                
                # preds
                hours_pred = hours.argmax(1).detach().cpu().numpy().astype(str).tolist()
                mins_pred  = mins .argmax(1).detach().cpu().numpy().astype(str).tolist()
                pred  = [ h_pr + m_pr for h_pr, m_pr in zip(hours_pred, mins_pred) ]
                preds.extend(pred)

        # accuracy
        acc = accuracy_score(label, pred)
        if acc > best_acc:
            best_acc = acc
            best_model = model
            
        print(f"-- EPOCH {epoch} --")
        print(f"training   loss : {round(np.mean(train_loss), 4)}")
        print(f"validation loss : {round(np.mean(val_loss)  , 4)}")
        print(f"validatoin acc  : {acc}")
        print(f"best acc until now: {best_acc}")
    
    return best_model
                
                

def main():
    # get data
    train, test1, test2 = prepare_data()
    train, val = train_test_split(train, test_size=configs['TEST_SIZE'], random_state=configs['SEED'])
    
    # get data loaders
    train_loader = DataLoader(
        BaseDataset(train['path'].values, train['hour'].values, train['min'].values, configs['SIZE'], mode='train'),
        batch_size = configs['BATCH_SIZE'],
        num_workers = 8,
        pin_memory=True,
        persistent_workers=True,
        shuffle=True,
    )
    val_loader = DataLoader(
        BaseDataset(val['path'].values, val['hour'].values, val['min'].values, configs['SIZE'], mode='val'),
        batch_size = configs['BATCH_SIZE'],
        num_workers = 8,
        shuffle=False,
    )
    test1_loader = DataLoader(
        BaseDataset(test1['path'].values, test1['hour'].values, test1['min'].values, configs['SIZE'], mode='test'),
        batch_size = configs['BATCH_SIZE'],
        num_workers = 8,
        pin_memory=True,
        persistent_workers=True,
        shuffle=False,
    )
    test2_loader = DataLoader(
        BaseDataset(test2['path'].values, test2['hour'].values, test2['min'].values, configs['SIZE'], mode='test'),
        batch_size = configs['BATCH_SIZE'],
        num_workers = 8,
        pin_memory=True,
        persistent_workers=True,
        shuffle=False,
    )
    
    # set training environment
    model = ClockClassifier(model_name) # backbone
    optimizer = torch.optim.Adam(model.parameters(), lr = configs['LEARNING_RATE'])
    criterion = torch.nn.CrossEntropyLoss()
    scheduler = None

    best_model = train_fn(configs, model, criterion, optimizer, scheduler, train_loader, val_loader)    
    
    return best_model


if __name__ == '__main__':
    best_model = main()