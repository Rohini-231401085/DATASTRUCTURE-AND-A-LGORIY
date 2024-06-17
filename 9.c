Write a function to perform Depth-First Search on the graph. Start the search from a specified source vertex. Print the visited vertices in DFS order.

Aim:

  To implement a function in C to perform Depth-First Search (DFS) on a graph represented using an adjacency list. The DFS function will start from a specified source vertex and print the visited vertices in DFS order.


Algorithm:

Depth-First Search (DFS)
1.	Initialize:
•	Create a boolean array visited to keep track of visited vertices.
2.	Start DFS from the source vertex:
•	Mark the source vertex as visited and print it.
•	Recursively visit all adjacent vertices of the current vertex that have not been visited.
Program:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent an adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Structure to represent an adjacency list
typedef struct AdjList {
    struct AdjListNode *head;
} AdjList;





Department of Computer Science and Engineering, Rajalakshmi Engineering College



	 // Structure to represent a graph
typedef struct Graph {
    int V;
    struct AdjList* array;
} Graph;


// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform DFS from a given vertex
void DFSUtil(Graph* graph, int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    printf("%d ", v);
   // Recur for all the vertices adjacent to this vertex
    AdjListNode* adjList = graph->array[v].head;
    while (adjList != NULL) {
        int adjVertex = adjList->dest;
        if (!visited[adjVertex])
            DFSUtil(graph, adjVertex, visited);
        adjList = adjList->next;
    }
}



Department of Computer Science and Engineering, Rajalakshmi Engineering College





// Function to perform DFS starting from a given vertex
void DFS(Graph* graph, int startVertex) {
    // Initialize visited array
    bool *visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    // Call the recursive helper function to perform DFS
    DFSUtil(graph, startVertex, visited);

    free(visited);
}

// Function to print the adjacency list representation of the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
/

int main() {
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph adjacency list:\n");
    printGraph(graph);

    printf("\nDepth First Traversal starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}


