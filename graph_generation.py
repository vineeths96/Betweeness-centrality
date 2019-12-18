import os
import networkx as nx 
#import matplotlib.pyplot as plt

for i in [500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]:

	fhand = open(os.path.join('/home/vineeth/Work/dsa/Asgn 3/graphs/density_005/list_' +str(i)+ '.txt'), "w+")

	G= nx.erdos_renyi_graph(i,0.005) 
	Gc = max(nx.connected_component_subgraphs(G), key=len)

	#nx.draw(Gc, with_labels=True)
	#plt.show()

	print(len(Gc))
	nx.write_weighted_edgelist(Gc, os.path.join('/home/vineeth/Work/dsa/Asgn 3//graphs/density_005/list_'+str(i)+'.txt'))

