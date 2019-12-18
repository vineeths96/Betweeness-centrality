import matplotlib.pyplot as plt
import matplotlib.axes as Axes

plt.figure()

plt.subplot(221)
plt.plot([2500, 5000, 7500, 10000, 12500, 15000], [149.000000, 1218.000000, 4646.000000, 9829.000000, 18384.000000, 34152.000000], label='Floyd Warshall')
plt.plot([2500, 5000, 7500, 10000, 12500, 15000], [99.000000, 844.000000, 3452.000000, 7086.000000, 12826.000000, 23770.000000], label='n-BFS')
plt.title("p = 0.01")
axes = plt.gca()
axes.set_xlim(0, 16000)
plt.ylabel('Time (in seconds)')
plt.xlabel('Number of vertices')
plt.legend(title = 'Legend')

plt.subplot(222)
plt.plot([2500, 5000, 7500, 10000, 12500, 15000], [150.000000, 1205.000000, 4544.000000, 9442.000000, 20120.000000, 45748.000000], label='Floyd Warshall')
plt.plot([2500, 5000, 7500, 10000, 12500, 15000], [137.000000, 1138.000000, 4396.000000, 9706.000000, 19928.000000, 44351.000000], label='n-BFS')
plt.title("p = 0.05")
axes = plt.gca()
axes.set_xlim(0, 16000)
plt.ylabel('Time (in seconds)')
plt.xlabel('Number of vertices')
plt.legend(title = 'Legend')

plt.subplot(223)
plt.plot([2500, 5000, 7500, 10000, 12500, 15000], [154.000000, 1219.000000, 4607.000000, 9902.000000, 22698.000000, 54602.000000], label='Floyd Warshall')
plt.plot([2500, 5000, 7500, 10000, 12500, 15000], [193.000000, 1525.000000, 5847.000000, 12580.000000, 28976.000000, 70121.000000], label='n-BFS')
plt.title("p = 0.1")
axes = plt.gca()
axes.set_xlim(0, 16000)
plt.ylabel('Time (in seconds)')
plt.xlabel('Number of vertices')
plt.legend(title = 'Legend')

plt.subplot(224)
plt.plot([2500, 5000, 7500, 10000, 12500, 15000], [160.000000, 1257.000000, 4798.000000, 10326.000000, 21972.000000, 40462.000000], label='Floyd Warshall')
plt.plot([2500, 5000, 7500, 10000, 12500, 15000], [288.000000, 2338.000000, 8733.000000, 18771.000000, 37085.000000, 73646.000000], label='n-BFS')
plt.title("p = 0.2")
axes = plt.gca()
axes.set_xlim(0, 16000)
plt.ylabel('Time (in seconds)')
plt.xlabel('Number of vertices')
plt.legend(title = 'Legend')

#plt.subplots_adjust(left=-0.05)
plt.tight_layout()

plt.show()


