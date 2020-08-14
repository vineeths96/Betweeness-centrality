FILES INCLUDES WITH THIS PROJECT:
================================================================

	client.c	header.h	implement.c
	readme.txt	makefile	graph_generation.py
	plot.py

	'graphs' directory - Contains few test graphs
	'results' directory - To store the results


PROGRAM
================================================================

INTRODUCTION
-------------

	This program performs the betweeness centrality calculation in networks represented as undirected graphs. 
Betweenness centrality is a measure of the importance of a particular node in a network. The entire program
is written in three files. Comments have been added frequently to help in understanding the logic behind 
implementation. The program expects the user to save all the graphs to be processed in the 'graphs' 
directory in edge list format and to input the filename during execution. The user is provided with the option
of either displaying the betweenness centrality on screen or to save it in a file in 'results' directory 
(by calling appropriate function). The execution time vs number of vertices of random graphs for different 
probablities is stored in 'results' directory. Refer problem statement file for detailed information.


OPERATING SYSTEM AND SOFTWARE REQUIRMENTS
------------------------------------------

	The entire program was developed in Ubuntu operating system using C language. It is highly recommeneded 
to use the Ubuntu system to execute the program. The program requires gcc compiler to compile, build and 
execute the program. The OS and compiler version used for developing the code are :
		Operating system 	: Ubuntu 18.04.1 
		gcc compiler verison	: gcc version 7.4.0


FUNCTIONS IN THE PROGRAM
------------------------

initGraph()		- Initializes a graph with the specified number of vertices and returns its address

readFile()		- Reads edge list from the file spectified and adds it in the graph

addEdge()		- Adds an undirected edge in the graph between source and edge

printGraph()		- Prints the adjecency list representation of the graph

deleteGraph() 		- Deletes the graph specified

BC_Floyd_Warshall() 	- Betweenness centralilty calculation using Floyd Warshall algorithm. Returns the time taken by the function

BC_BFS()		- Betweenness centralilty calculation using n BFS algorithm. Returns the time taken by the function

print_BC()		- Prints the betweeness centrality of every vertex once calculated

save_BC()		- Saves the betweeness centrality of vertices into the file specified

time_for_graphs() 	- Executes algorithms for the graphs (represented in edge lists) stored in 'graphs' folder. 
			  The time taken is stored in the file specified

	There are other internal functions that support the execution of the program.


PROGRAM EXECUTION
-----------------

	The program when run requests the user to input the number of vertices and the name of file from which graph
 has to be extracted. The graph has to be stored in 'graphs' folder and has to be stored in edge list format. On successfull
 extraction, an undirected graph with the specified number of vertices and edges will be created. This program calculates
 the betweenness centrality values using Floyd Warshall algorithm as well as n-BFS algorithm. The BC_mat_FW and BC_mat_BFS
 arrays are updated woth the betweenness centrality values of vertices after BC_Floyd_Warshall() and BC_BFS() calls 
respectively. Both the functions return the time taken for execution of the algorithm. The user is given the option to 
either print the betweeness centrality values on screen or store it to a file in 'results' directory.


TEST GRAPHS
-----------

	The 'graphs' directory contains few test graphs including the one provided with the assignment. 


INSTRUCTIONS TO RUN
--------------------

	Open the terminal, make the program and run it. Enter the file name of the graph to be processed as requested 
during exectuion of the program.


CONTACT
========
Developed by
Name	 : Vineeth S
