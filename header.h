#ifndef HEADER_H 
#define HEADER_H

#define INT_MAX 99999
#define FNAME_SIZE 50
#define STR_SIZE 50

//Data structures
typedef struct node
{
	int vertex;
	struct node* next;
} node;

typedef struct list
{
	struct node* head;
} list;

typedef struct Graph
{
	int V;
	list* adjList; 
} Graph;

//Functions
Graph* initGraph(int v);					// Initializes a graph with the specified number of vertices and returns its address

bool readFile(char fname[], Graph* graph);			// Reads edge list from the file spectified and adds it in the graph

bool addEdge(Graph* graph, int src, int dest);			// Adds an undirected edge in the graph between source and edge

void printGraph(const Graph* graph);				// Prints the adjecency list representation of the graph

void deleteGraph(Graph* graph);					// Deletes the graph

double BC_Floyd_Warshall(const Graph* graph, float* BC_mat_FW);	// Betweenness centralilty calculation using Floyd Warshall algorithm. Returns the time taken by the function

double BC_BFS(const Graph* graph, float* BC_mat_BFS);		// Betweenness centralilty calculation using n BFS algorithm. Returns the time taken by the function

void print_BC(const Graph* graph, const float* BC);		// Prints the betweeness centrality of every vertex once calculated

void save_BC(const Graph* graph, float* BC, char fname[]);	// Saves the betweeness centrality of vertices into the file specified

void time_for_graphs(char fname[]);				// Executes algorithms for the graphs (represented in edge lists) stored in 'graphs' folder. The time taken is stored in the file specified

#endif
