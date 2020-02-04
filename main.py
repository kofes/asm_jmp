import sys
import csv
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import math

# Read CSV
csvFileName = sys.argv[1]
csvData = []
with open(csvFileName, 'r') as csvFile:
    csvReader = csv.reader(csvFile, delimiter=' ')
    for csvRow in csvReader:
        csvData.append(csvRow)

# Get X, Y, Z
csvData = np.array(csvData)
csvData = csvData.astype(np.float)
X, Y, Z = csvData[:,0], csvData[:,1], csvData[:,2]

data = {}

def indToId(ind):
    if ind == 0:
        return "if/else"
    if ind == 1:
        return "switch"
    return "virtual"

for i in range(len(X)):
    typeid = indToId(int(X[i]))
    count = int(Y[i])
    time = Z[i]
    if not (typeid in data):
        data[typeid] = {0: [], 1: []}
    data[typeid][0].append(count)
    data[typeid][1].append(time)

legends = []
for key in data:
    plt.plot(data[key][0], data[key][1], label=key)
    legends.append(key)
plt.legend(legends)
plt.show()