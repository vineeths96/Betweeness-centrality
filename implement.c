#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "header.h"

// Queue structure definition
typedef struct Queue
{
	node* front;
	node* rear;
} Queue;

// Add a new node with vertex value v and return its address
node* addNode(int v)
{
	node* newnode = (node*) malloc(sizeof(node));
	newnode->vertex = v;

	return newnode;
}

// Initializes a queue and returns its address
Queue* initQueue()
{
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

// Checks whether the queue in argument is empty or not
bool isEmpty(Queue* queue)
{
	if(!queue)	
	{
		printf("Queue does not exist\n");
		return true;
	}

	if(queue->front == NULL) return true;
	else 			return false;
}

// Adds a new element to the rear of the queue, if queue exists
bool enqueue(Queue* queue, int v)
{
	if(!queue)	
	{
		printf("Queue does not exist\n");
		return false;
	}

	node* newnode = addNode(v);
	if(newnode == NULL)	return false;
	newnode->next = NULL;

	if(queue->front == NULL)
	{
		queue->front = newnode;
		queue->rear = newnode;
	}
	else
	{
		queue->rear->next = newnode;
		queue->rear = newnode;
	}

	return true;
}

// Deletes the element from the front of the queue and returns it, if queue exists and it is not empty
// Returns -1 as an indication of failing to dequeue
int dequeue(Queue* queue)
{
	if(!queue)	
	{
		printf("Queue does not exist\n");
		return -1;
	}

	if(queue->front == NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	{
		int v;
		node* dnode = (node*) malloc(sizeof(node));

		dnode = queue->front;
		v = queue->front->vertex;
		queue->front = queue->front->next;

		// If front of queue becomes NULL, queue is empty and hence rear of queue is NULL 
		if(queue->front == NULL)	queue->rear = NULL;

		free(dnode);
		return v; 
	}
		
}

// Reads edge list from the file spectified and adds it in the graph
bool readFile(char fname[], Graph* graph)
{
	FILE *fptr;
	char str[STR_SIZE];
	char fname_path[FNAME_SIZE];
	int src, dest, weight, edge_num = 0;
	
	sscanf(fname, "%s", fname);

	if(!graph)	
	{
		printf("Graph does not exist\n");
		return false;
	}

	// Graphs are stored in 'graph' directory and hence the address path is added to it
	sprintf(fname_path, "./graphs/%s", fname);
	fptr = fopen(fname_path, "r");

	if(!fptr)
	{
		printf("Error in opening the file\n");
		return false;
	}

	// Reading from the file till EOF
	while(fgets(str, STR_SIZE, fptr))
	{
		edge_num++;
		sscanf(str, "%d %d", &src, &dest);		
//		addEdge(graph, src, dest);

		if(addEdge(graph, (src-1), (dest-1)))	printf("Edge addition successful\n");		// Use this for Cornell's (given) graph
//		if(addEdge(graph, src, dest))	printf("Edge %d addition successful\n", edge_num);	// Use this for displaying whether the addition of edge was sucessfull or not
//		else				printf("Edge %d addition failure\n", edge_num);		

	}

	fclose(fptr);
	return true;
}

// Initializes a graph with the specified number of vertices and returns its address
Graph* initGraph(int v)
{
	Graph* graph = (Graph*) malloc(sizeof(Graph));

	if(v<=0)
	{
		printf("Vertices in graph should be positve\n");
		return NULL;
	}

	if(!graph)
	{
		printf("Error in graph creation\n");
		return NULL;
	}

	graph->V = v;
	graph->adjList = (list*) malloc(v * sizeof(list));

	// Initializing adjacency list headers to NULL
	for(int i=0; i<v; i++)
	{
		graph->adjList[i].head = NULL;		
	}

	return graph;
	
}

// Adds an undirected edge in the graph between source and edge
bool addEdge(Graph* graph, int src, int dest)
{
	if(!graph)	
	{
		printf("Graph does not exist\n");
		return false;
	}
	
	node* newnode;

	newnode = addNode(dest);
	if(!newnode)	return false;
	newnode->next = graph->adjList[src].head;
	graph->adjList[src].head = newnode;

	newnode = addNode(src);
	if(!newnode)	return false;
	newnode->next = graph->adjList[dest].head;
	graph->adjList[dest].head = newnode;

	return true;
}

// Returns the index in 1D array corresponding to 2D array
int matIndex(int i, int j)
{
   if (i >= j)
      return i*(i+1)/2 + j;
   else
      return j*(j+1)/2 + i;
}

// Creates an V*V matrix and initializes its values with that of adjancency matrix and returns its base address  
int* initAdjmat(const Graph* graph)
{
	if(!graph)
	{
		printf("Graph does not exist\n");
		return NULL;
	}

	// Dynamic allocation of matrix
	int num_el = (graph->V)*(graph->V+1)/2;
	int* mat = (int*) malloc (num_el*sizeof(int));

	// Setting matrix values to 0
	for(int i = 0; i<num_el; i++)
	{
			*(mat+ i) = 0;
	}

	node* pCrawl = (node*) malloc(sizeof(node));

	for(int i=0; i< graph->V; i++)
	{
		pCrawl = graph->adjList[i].head;
		while(pCrawl)
		{
			*(mat+ matIndex(i, pCrawl->vertex)) = 1;
			pCrawl = pCrawl->next;
		}
	}

	return mat;
}

// Calculates the betweeness centrality values from shortest distance matrix and number of shortest path matrix
void BC_Calculate(const Graph* graph, int* distMat, int* num_SP, float* BC)
{
	if(!graph)
	{
		printf("Graph does not exist\n");
		return;
	}

	if(!distMat || !num_SP || !BC)
	{
		printf("Input argument does not exist\n");
		return;
	}

	// Initializing betweenness centrality matrix to 0
	for(int i=0; i<graph->V; i++)	BC[i] = 0;

	for(int i=0; i<graph->V; i++)
	{
		for(int j=0; j<i; j++)
		{
			for(int k=0; k<graph->V; k++)
			{
				if(k==i || k==j)	continue;

				if( ((*(distMat+ matIndex(i,j))) == ((*(distMat+ matIndex(i,k))) + (*(distMat+ matIndex(k,j))))))
				{
					// Each time a shortest path between i and j passes through k, it contributues 1/(number of SP bewteen i and j) to betwenness centrality of k
					BC[k] = BC[k] + (float)1/(*(num_SP+ matIndex(i,j)));
				}
			}
		}
			
	}

}

// Betweenness centralilty calculation using Floyd Warshall algorithm. Returns the time taken by the function
double BC_Floyd_Warshall(const Graph* graph, float* BC_mat_FW)
{
	// Starting the time measurement
	clock_t start, end;
	start = clock();

	if(!graph)
	{
		printf("Graph does not exist\n");
		end = clock();
		return -1;
	}

	if(!BC_mat_FW)
	{
		printf("Matrix in the function argument does not exist\n");
		end = clock();
		return -1;
	}

	// Initializes adjMat with adjacency matrix of graph
	int* adjMat = initAdjmat(graph);

	// Setiing distances between vertices without an edge to INT_MAX
	int num_el = (graph->V)*(graph->V +1)/2;
	for(int i = 0; i<graph->V; i++)
	{
		for(int j=0; j<=i; j++)
		{ 
			if(i==j)					*(adjMat+ matIndex(i,j)) = 0; 
			else if( *(adjMat+ matIndex(i,j)) == 0)		*(adjMat+ matIndex(i,j)) = INT_MAX;
		}	
	}

	// Initializes num_SP_FW (number of shortest path) with adjacency matrix of graph
	int* num_SP_FW = initAdjmat(graph);

	for(int k=0; k<graph->V; k++)
	{
		for(int i=0; i<graph->V; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(k==i || k==j)	continue;

				if( (*(adjMat+ matIndex(i,j))) == ((*(adjMat+ matIndex(i,k))) + (*(adjMat+ matIndex(k,j)))))
				{
					// If current distance = shortest distance, then number of shortest path (SP) becomes the sum of existing SP and the product of number of SP from i to k and k to j
					*(num_SP_FW+ matIndex(i,j)) = *(num_SP_FW+ matIndex(i,j)) + *(num_SP_FW+ matIndex(i,k)) * *(num_SP_FW+ matIndex(k,j));
				}
				else if( (*(adjMat+ matIndex(i,j))) > ((*(adjMat+ matIndex(i,k))) + (*(adjMat+ matIndex(k,j)))))
				{
					// If current distance < shortest distance, then the shortest distance between i and jare updated with the current distance
					*(adjMat+ matIndex(i,j)) = ((*(adjMat+ matIndex(i,k))) + (*(adjMat+ matIndex(k,j))));

					//The number of shortest path between i and j becomes the product of number of shortest path from i to k and k to j
					*(num_SP_FW+ matIndex(i,j)) = *(num_SP_FW+ matIndex(i,k)) * *(num_SP_FW+ matIndex(k,j));
				}
			}
		}

	}

	BC_Calculate(graph, adjMat, num_SP_FW, BC_mat_FW);

	// Freeing up space
	free(adjMat);
	free(num_SP_FW);

	// Ending clock
	end = clock();

	// Time calculation
	double time = (end - start)/CLOCKS_PER_SEC;
	return time;
}

// Betweenness centralilty calculation using n BFS algorithm. Returns the time taken by the function
double BC_BFS(const Graph* graph, float* BC_mat_BFS)
{
	// Starting the time measurement
	clock_t start, end;
	start = clock();

	if(!graph)
	{
		printf("Graph does not exist\n");
		end = clock();
		return -1;
	}

	if(!BC_mat_BFS)
	{
		printf("Matrix in the function argument does not exist\n");
		end = clock();
		return -1;
	}

	// A boolean array of size V*V to mark the visiting of nodes
	int num_el = (graph->V)*(graph->V);
	bool* visited = (bool*) malloc(num_el*sizeof(bool));

	// Setting th V*V matrix entries to false
	for(int i = 0; i<num_el; i++)
	{
			*(visited + i) =false;
	}

	// Initializes distMat with adjacency matrix of graph
	int* distMat = initAdjmat(graph);	

	// Initializes num_SP_BFS (number of shortest path) with adjacency matrix of graph
	int* num_SP_BFS = initAdjmat(graph);

	// n BFS algorithm
	Queue* queue = initQueue();

	for(int i=0; i<graph->V; i++)
	{
		if(!enqueue(queue, i))	
		{
			printf("Memory allocation error");
			return -1;
		}

		*(visited + (i*graph->V) +i) = true;

		while(!isEmpty(queue))
		{
			int v = dequeue(queue);

			if(v == -1)
			{
				printf("Memory allocation error\n");
				return 0;
			}

			node* lCrawl = (node*) malloc(sizeof(node));

			for(lCrawl = graph->adjList[v].head; lCrawl != NULL; lCrawl = lCrawl->next)
			{
				// If lCrawl->vertex is already visited in the BFS from i-th vertex
				if(*(visited + (i*graph->V) + lCrawl->vertex) == true)
				{
					if(*(distMat +matIndex(i, lCrawl->vertex)) == *(distMat +matIndex(i, v)) +1)
					{
						// If current distance = shortest distance, then number of shortest path (SP) becomes the sum of existing number of SP and the number of SP to v
						*(num_SP_BFS+ matIndex(i, lCrawl->vertex))	= *(num_SP_BFS+ matIndex(i, lCrawl->vertex)) + *(num_SP_BFS+ matIndex(i, v));	
					}
				}

				// If lCrawl->vertex is not visited in the BFS from i-th vertex
				if(*(visited +(i*graph->V) + lCrawl->vertex) == false)
				{
					// The new vertex is enqueued and marked visited
					if(!enqueue(queue, lCrawl->vertex))
					{
						printf("Memory allocation error");
						return -1;
					}

					*(visited +(i*graph->V) + lCrawl->vertex) = true;

					// Distance of the new vertex is 1 more than the distance of its predeccessor in BFS and number of shortest path (SP) is equal to number of SP of its predecessor
					*(distMat +matIndex(i, lCrawl->vertex)) = *(distMat +matIndex(i, v)) +1;

					if(*(num_SP_BFS+ matIndex(i, v)) == 0)	*(num_SP_BFS+ matIndex(i, lCrawl->vertex))	= 1;
					else					*(num_SP_BFS+ matIndex(i, lCrawl->vertex))	= *(num_SP_BFS+ matIndex(i, v));
				}
			}
			
			
		}
	}

	BC_Calculate(graph, distMat, num_SP_BFS, BC_mat_BFS);

	// Freeing up space
	free(distMat);
	free(num_SP_BFS);
	free(visited);

	// Ending clock
	end = clock();

	// Time calculation
	double time = (end - start)/CLOCKS_PER_SEC;
	return time; 
}

// Prints the betweeness centrality of every vertex once calculated
void print_BC(const Graph* graph, const float* BC)
{
	if(!graph)
	{
		printf("Graph does not exist\n");
		return;
	}
	
	if(!BC)
	{
		printf("Matrix in the function argument does not exist\n");
		return;
	}

	for(int i=0; i<graph->V; i++)	printf("Betweenness centrality of vertex %d is %f\n", i, BC[i]);
}

// Prints an linked list
void printList(const list* ls, int i)
{
	if(!ls)
	{
		printf("List does not exist\n");
		return;
	}

	printf("Adjacency list of node %d\n", i+1);

	node* pCrawl = (node*) malloc(sizeof(node));

	if(!pCrawl)	
	{
		printf("Memory allocation error");
		return;
	}

	for(pCrawl = ls->head; pCrawl != NULL; pCrawl = pCrawl->next)
	{
		printf("%d->", pCrawl->vertex);
//		printf("%d->", (pCrawl->vertex + 1));		// Use this for Cornell's (given) graph
	}

	printf("NULL\n");
}

// Prints the adjancency list representation of graph
void printGraph(const Graph* graph)
{
	if(!graph)
	{
		printf("Graph does not exist\n");
		return;
	}
	
	for(int i = 0; i<graph->V; i++)
	{
		printList(&graph->adjList[i], i);
	}
}

// Deletes an linked list
void deleteList(list* ls)
{
	node* prev = ls->head;

	// Delete the nodes of the list
	while (ls->head != NULL)
	{
		ls->head = ls->head->next;
		free(prev);
		prev = ls->head;
	}

}

// Delete the graph
void deleteGraph(Graph* graph)
{
	if(!graph)
	{
		printf("Graph does not exist\n");
		return;
	}
	
	for(int i=0; i<graph->V; i++)
	{
		deleteList(&graph->adjList[i]);
	}

	free(graph->adjList);
}

// Saves the betweeness centrality of vertices into the file specified
void save_BC(const Graph* graph, float* BC, char fname[])
{
	FILE *fptr;
	char str[STR_SIZE];
	char fname_path[FNAME_SIZE];

	if(!BC)
	{
		printf("Matrix in the function argument does not exist\n");
		return;
	}

	// The file is stored in 'results' directory and hence the address path is added to it
	sprintf(fname_path, "./results/%s", fname);

	// The file is created/opened
	fptr = fopen(fname_path, "w");

	if(!fptr)
	{
		printf("Error in opening the file to which betweeness centrality has to be saved\n");
		return;
	}

	for(int i = 0; i<graph->V; i++)
	{
		sprintf(str, "%d, %f\n", i, BC[i]);
		fputs(str, fptr);
	}

	fclose(fptr);
}

// Function to executes both the Floyd Warshall and n-BFS algorithm for the graphs (represented as edge lists) stored in 'graphs/density_xx' folder. The time taken for each graph is stored in the file specified
// This function is exclusive for the graphs in the 'graphs' folder. Suitable modifications has to be done with the code for other graphs. 
void time_for_graphs(char fname[])
{
	// Declarations
	char lname[FNAME_SIZE];
	char str[STR_SIZE];
	char fname_path[FNAME_SIZE];
	double time_FW, time_BFS;

	// Storing the vertices of each graphs in the folder
	int vertices[] = {500, 1000, 2000, 3000, 4000, 5000, 6000};

	// The file is stored in 'results' directory and hence the address path is added to it
	sscanf(fname, "%s", fname);
	sprintf(fname_path, "./results/%s", fname);
	
	FILE *tptr;

	// The file is created/opened
	tptr = fopen(fname_path, "a");

	if(!tptr)
	{
		printf("Error in opening the file for saving the time taken\n");
		return;
	}

	// Executing both algorithm for each graph (file)
	for(int i=0; i<(sizeof(vertices)/sizeof(int)); i++)
	{
		printf("\nFor graph with vertices %d\n", vertices[i]);

		sprintf(lname, "density_20/list_%d.txt", vertices[i]);

		// Initializes a graph with the specified number of vertices and returns its address
		Graph* graph = initGraph(vertices[i]);

		// Reading the file
		if(readFile(lname, graph))	printf("Sucessfully extracted\n");
		else				exit(1);

		float* BC_mat_FW = (float*) malloc((graph->V)*sizeof(float));
		float* BC_mat_BFS = (float*) malloc((graph->V)*sizeof(float));

		time_FW = BC_Floyd_Warshall(graph, BC_mat_FW);
		printf("Time taken by Floyd Warshall is %lf seconds\n", time_FW);

		time_BFS = BC_BFS(graph, BC_mat_BFS);
		printf("Time taken by n-BFS is %lf seconds\n", time_BFS);

		// Saving the time to the file
		sprintf(str, "%d, %lf, %lf\n",vertices[i], time_FW, time_BFS);
		fputs(str, tptr);
	
		deleteGraph(graph);
		free(graph);
		printf("Graph deleted\n");
	}

	fclose(tptr);

}
