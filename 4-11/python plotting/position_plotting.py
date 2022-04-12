
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


rawData = pd.read_csv("../build/output.csv")
rawData = rawData.to_numpy()

plt.ion()

for i in range(len(rawData)):
    plt.xlim(rawData[i,0]-1e10, rawData[i,0]+1e10)
    plt.ylim(rawData[i,1]-1e10, rawData[i,1]+1e10)
    # plt.xlim(-2.5e11, 2.5e11)
    # plt.ylim(-2.5e11, 2.5e11)
    plt.scatter(rawData[i,0], rawData[i,1], c='blue', s=1)
    plt.scatter(rawData[i,3], rawData[i,4], c='red', s=1)
    plt.pause(0.001)
    plt.clf()

