#ifndef _INCLUDED_GRAPH_
#define _INCLUDED_GRAPH_
#include <stdint.h>

#define MAX 20
#define TRUE 1
#define FALSE 0

// Define the node structure and graph structure
typedef struct _graph_node_ Node;
typedef struct _graph_list_ Graph;

// Define the node structure
struct _graph_node_ {
    int32_t node_id;
    Node *next;
};

// Declare the visited array (this will be defined in graph.c)
extern uint32_t visited[MAX];  

// Define the graph structure
struct _graph_list_ {
    uint32_t max_nodes;
    Node **neighbours;
};

// Function declarations
Graph graph_new(uint32_t size);
Graph *graph_adjacency_list(Graph *graph);
Graph *graph_dfs(Graph *graph, int32_t v);

// Declare _get_node_ to make it accessible outside graph.c
Node* _get_node_(int32_t data);  // This is now an external function

#endif
