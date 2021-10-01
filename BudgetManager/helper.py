import os
import sys
import keras
from keras.layers import load_model

x = {"abc": 1, "cd": "5534"}
y = 67


def fun():
  model = load_model("model_weights.h5")
  model.summary()
  
