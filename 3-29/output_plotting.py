


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


rawData = pd.read_csv("particle_output.csv")
#rawData = rawData.astype(float)
rawData = rawData.to_numpy()

numb_of_particles = 5000
n = numb_of_particles
plt.ion()

for i in range(0,1000,1):
    plt.xlim([0, 100])
    plt.ylim([0, 100])
    plt.scatter(rawData[n*i:i*n+n,0], rawData[n*i:i*n+n,1], c='blue', s=1)
    #print(rawData[5000*i:i*5000+5000][0])
    plt.pause(0.1)
    plt.clf()

plt.show()