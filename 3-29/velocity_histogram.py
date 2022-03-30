

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

rawData = pd.read_csv("particle_final_velocity.csv")
#rawData = rawData.astype(float)
rawData = rawData.to_numpy()

numb_of_particles = 5000

n_bins = 30
fig,axs = plt.subplots()
axs.hist(rawData[:], bins=n_bins)
plt.scatter(1,1)
plt.show()