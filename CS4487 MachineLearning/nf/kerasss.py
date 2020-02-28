# This Python 3 environment comes with many helpful analytics libraries installed
# It is defined by the kaggle/python docker image: https://github.com/kaggle/docker-python
# For example, here's several helpful packages to load in 

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

from keras.models import Sequential
from keras.layers import Dense, Conv2D, Flatten, Dropout, MaxPooling2D, BatchNormalization,Activation
from keras.preprocessing.image import ImageDataGenerator
from keras import backend
from keras.optimizers import RMSprop, Adam
from keras import regularizers
from keras.callbacks import LearningRateScheduler
from keras.models import load_model

from keras.utils import to_categorical

def unpickle(file, train=True):
    import pickle
    with open('./cifar-10-batches-py/'+(('data_batch_'+str(file)) if train else 'test_batch'), 'rb') as fo:
        dict_d = pickle.load(fo)
    return np.reshape(dict_d['data'],(10000,3,32,32)).transpose(0, 2, 3, 1), dict_d['labels']
# def normalization(x):
#     return x/255

training_set = []
training_label = []
for i in range(1,5):
    x,y = unpickle(i)
    training_set.extend(x) 
    training_label.extend(y)

test_data,test_label = unpickle(5)

test_data_norm = np.array(test_data) / 255
test_label_one_hot_encoded = to_categorical(test_label)

training_set_norm = np.array(training_set) / 255
training_label_one_hot_encode = to_categorical(training_label)

batch_size = 128
epochs = 10
IMG_HEIGHT = 32
IMG_WIDTH = 32

labels_name = [
"airplane",
"automobile",
"bird",
"cat",
"deer",
"dog",
"frog",
"horse",
"ship",
"truck"
]

# def plotImages(images_arr,lab):
#     from matplotlib import pyplot as plt
#     fig, axes = plt.subplots(1, 5, figsize=(10,10))
#     axes = axes.flatten()
#     for img, ax in zip( images_arr, axes):
#         ax.imshow(img)
#         ax.axis('off')
#     plt.tight_layout()
#     plt.show()
#     for i in lab[:5]:
#         print(labels_name[i], end=' ')

# for i in range(0,20,5):
#     plotImages(training_set_norm[i:i+5],training_label[i:i+5])

weight_decay = 1e-4
num_classes=10
datagen2 = ImageDataGenerator(
    rotation_range=15,
    width_shift_range=0.1,
    height_shift_range=0.1,
    horizontal_flip=True,
    )
datagen2.fit(training_set_norm)
def lr_schedule(epoch):
    print(epoch)
    lrate = 0.001
    if epoch > 300:
        lrate = 0.000005
        model.save('./model2.h5')
    if epoch > 400:
        lrate = 0.000003
        model.save('./model2.h5')
    if epoch > 500:
        lrate = 0.000001
        model.save('./model2.h5')
    return lrate
model = load_model('./model.h5')
history2 = model.fit_generator(
    datagen2.flow(training_set_norm, training_label_one_hot_encode, batch_size=32),\
        steps_per_epoch=training_set_norm.shape[0] // 32,epochs=600,\
        verbose=0,
    validation_data=(test_data_norm,test_label_one_hot_encoded),
    callbacks=[LearningRateScheduler(lr_schedule)],
    initial_epoch=300
)
accuracy2 = model.evaluate(x=test_data_norm,y=test_label_one_hot_encoded,batch_size=32)
print("Accuracy: ",accuracy2[1])
model.save('./model2.h5')

pp = np.load('./y_test.npy')
pp_norm = pp/255
test_res = []
for i in model4.predict(pp_norm):
    test_res.append(np.argmax(i))
# plotImages(pp,test_res)
# plotImages(pp[2400:],test_res[2400:])
# plotImages(pp[2400*2:],test_res[2400*2:])
# plotImages(pp[2400*3:],test_res[2400*3:])
# summarize_diagnostics(history41)
# summarize_diagnostics(history42)
# summarize_diagnostics(history43)

df = pd.DataFrame({'Category':test_res})
df['Index'] = df.index
df = df[['Index','Category']]
df.to_csv('./test_res5.csv',index=False)
