# basic utils
import os
import warnings
import random
from datetime import datetime
warnings.filterwarnings('ignore')
import glob
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import argparse
# from rich.traceback import install
# install(show_locals=False, suppress=["torch", "timm", "pytorch_lightning"])
from tqdm import tqdm as tq

# image processing
from PIL  import Image
import cv2

# sklearn
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.metrics import f1_score

# torch
import torch
from torch.utils.data import DataLoader, Dataset
from torchmetrics.classification import MultilabelAccuracy
from torchvision import transforms as T

# timm
import timm
from timm.optim import create_optimizer_v2

# # pytorch lightning
# import pytorch_lightning as pl
# from pytorch_lightning.loggers import WandbLogger
# from pytorch_lightning.callbacks import (
#     LearningRateMonitor,
#     ModelCheckpoint,
#     RichProgressBar,
# )

# # logging
# from loguru import logger

# albumentations
import albumentations as A
from albumentations.pytorch.transforms import ToTensorV2
from albumentations.augmentations.geometric.transforms import Affine as AF

