#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

int main()
{
	int vertices;
	char fname[FNAME_SIZE];
	double time_FW, time_BFS;

	printf("Enter number of vertices\n");
	scanf("%d", &vertices);	
	getchar();

	printf("Enter the file name from which graph name has to be extracted\n");
	fgets(fname, FNAME_SIZE, stdin);

	Graph* graph = initGraph(vertices);
	if(!graph)
	{
		printf("Memory allocation error");
		exit(1);
	}

	if(readFile(fname, graph))	printf("Sucessfully extracted\n");
	else				
	{
		printf("Extraction failed\n");
		exit(1);
	}

	//Uncomment the following line to print the adjacency list representation of graph
//	printGraph(graph);


	// Betweenness centrality calculation
	float* BC_mat_FW = (float*) malloc((graph->V)*sizeof(float));
	float* BC_mat_BFS = (float*) malloc((graph->V)*sizeof(float));

	time_FW = BC_Floyd_Warshall(graph, BC_mat_FW);
	if(time_FW<0)	exit(1);
	printf("Time taken by Floyd Warshall is %lf seconds\n", time_FW);

	time_BFS = BC_BFS(graph, BC_mat_BFS);
	if(time_BFS<0)	exit(1);
	printf("Time taken by n-BFS is %lf seconds\n", time_BFS);
	
	// Uncomment the following line to print the betweenness centrality values of the vertices
//	printf("\nFrom Floyd Warshall algorithm\n");	print_BC(graph, BC_mat_FW);
//	printf("\nFrom n-BFS algorithm\n");	print_BC(graph, BC_mat_BFS);

	save_BC(graph, BC_mat_FW, "BC_FW");
	save_BC(graph, BC_mat_BFS, "BC_BFS");

	deleteGraph(graph);
	free(graph);
	printf("\nGraph deleted\n");


// Block of code for time calculation for graphs in a particular folder. Just for reference on how Problem 3 was done.
/*
	char fname[FNAME_SIZE];
	printf("Enter the file name to which time has to be saved\n");
	fgets(fname, FNAME_SIZE, stdin);
	time_for_graphs(fname);
*/

	return 0; 

}
