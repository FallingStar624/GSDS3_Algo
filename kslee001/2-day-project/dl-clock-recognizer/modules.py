from loadlibs import *

# =====================================================================
class ClockClassifier(torch.nn.Module):
    def __init__(self, backbone):
        super().__init__()
        self.name = 'ClockClassifier'
        
        self.backbone = timm.create_model(
            backbone,
            in_chans = 1,
            pretrained=True,
            num_classes=0, drop_rate=0.2
        )
        self.hour_classifier = torch.nn.Linear(
            # 1408, 12
            512, 12
        )
        self.mins_classifier = torch.nn.Linear(
            # 1408, 60
            512, 12
        )
        self.minute_classifier = torch.nn.Linear
    def forward(self, x):
        features = self.backbone(x)
        hour = self.hour_classifier(features)
        mins = self.mins_classifier(features)
        return hour, mins


# =====================================================================
class BaseDataset(Dataset):
    def __init__(self, X, Y1, Y2, size, mode='train'):
        self.X = X   # image paths
        self.Y1 = torch.LongTensor(Y1.astype(int)) # hour labels
        self.Y2 = torch.LongTensor(Y2.astype(int)) # minute labels
        self.size = size
        self.mode = mode
        
    def __len__(self):
        return len(self.X)
    
    def __getitem__(self, idx):
        x = self.transform(cv2.imread(self.X[idx], cv2.IMREAD_GRAYSCALE))
        
        if self.mode in ['train', 'val']:
            delta = random.randint(0, 4)
            y1 = self.Y1[idx]
            y2 = self.Y2[idx]
            
            x, delta = self.rotate(
                img=x, delta=delta, hour=y1, minute=y2
            )
            y2 = y2+delta
            
            y1 = torch.tensor(y1)
            y2 = torch.tensor(y2)
            return ToTensorV2()(image=x)['image'].float(), y1, y2
        else:
            return ToTensorV2()(image=x)['image'].float()
        
    def transform(self, x):
        tf = A.Compose([
            A.Resize(height=self.size, width=self.size),
        ])
        return tf(image=x)['image']
    

    def rotate(self, img, delta:int, hour:int, minute:int): 
        # minute MUST be in [0, 1, 2, 3, 4]

        if (hour in [9, 10, 11, 12, 1, 2]) and (15<=minute<=40):
            case = 0
        elif (hour in [3, 4, 5, 6, 7, 8]) and (45<=minute<=59 or 0<=minute<=10):
            case = 1
        else:
            return img, 0

        size = img.shape[0]

        up_delta   = -0.5*delta if case == 0 else -6*delta
        down_delta = -0.5*delta if case == 1 else -6*delta

        # up
        up_M   = cv2.getRotationMatrix2D( 
            (img.shape[0]/2.0 , img.shape[1]/2.0), 
            -0.5*delta, 
            1.1)
        up = cv2.warpAffine(
            img, 
            up_M, 
            (img.shape[1], img.shape[0]),
            borderMode=cv2.BORDER_CONSTANT,
           borderValue=(255,255)
        )[:size//2]

        # down
        down_M   = cv2.getRotationMatrix2D( 
            (img.shape[0]/2.0 , img.shape[1]/2.0), 
            -6*delta, 
            1.1)
        down = cv2.warpAffine(
            img, 
            down_M, 
            (img.shape[1], img.shape[0]),
            borderMode=cv2.BORDER_CONSTANT,
           borderValue=(255,255)
        )[size//2:]
        augmented = cv2.vconcat([up, down])

        return augmented, delta


