# model_name = 'repvgg_a2'
model_name = 'resnet18'


project_name = 'clock'

configs = dict()
configs['BATCH_SIZE'] = 8
configs['LEARNING_RATE'] = 0.0001
configs['EPOCHS'] = 20
configs['TEST_SIZE'] = 0.25
configs['SEED'] = 1203
configs['WEIGHT_DECAY'] = 0.001
configs['DEVICE'] = 'cuda'
configs['NUM_GPUS'] = 1
configs['TQDM'] = True

configs['SIZE'] = 224

folder_name = f"./checkpoints/{model_name}_{configs['SEED']}"