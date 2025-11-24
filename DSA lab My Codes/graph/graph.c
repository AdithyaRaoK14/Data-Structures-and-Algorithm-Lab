#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

// Define the visited array
uint32_t visited[MAX] = {0};

// Function to create a new graph
Graph graph_new(uint32_t max) {
    Graph graph;
    int i;
    graph.max_nodes = max;
    graph.neighbours = (Node**)malloc(graph.max_nodes * sizeof(Node*));  
    for (i = 0; i < graph.max_nodes; i++) {
        graph.neighbours[i] = NULL;
    }
    return graph;
}

// Define _get_node_ function (non-static now so it can be accessed elsewhere)
Node* _get_node_(int32_t data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->node_id = data;
    node->next = NULL;
    return node;
}

// Function to simulate adding neighbours to the graph (for testing)
static int32_t _get_neighbour_(int32_t vertex) {
    int32_t node_id;
    printf("Enter neighbouring node of %d, if none enter 9999\n", vertex);
    scanf("%d", &node_id);
    return node_id;
}

// Function to create adjacency list for the graph
Graph *graph_adjacency_list(Graph *graph) {
    Node *vertex, *last_vertex;
    int32_t i, neighbour_id;
    for (i = 0; i < graph->max_nodes; ++i) {
        graph->neighbours[i] = _get_node_(i);  // Create a node for the vertex itself
        neighbour_id = _get_neighbour_(i);
        while (neighbour_id != 9999) {
            vertex = _get_node_(neighbour_id);
            if (graph->neighbours[i]->next == NULL) {
                graph->neighbours[i]->next = vertex;  // First neighbour
            } else {
                last_vertex->next = vertex;  // Add to the linked list
            }
            last_vertex = vertex;
            neighbour_id = _get_neighbour_(i);  // Ask for another neighbour
        }
    }
    return graph;
}

// Helper function for DFS
static void _dfs_(Graph *graph, int32_t v) {
    Node *vertex;
    visited[v] = TRUE;
    printf("%d\t", v);  // Print the visited node

    // Traverse the adjacency list for node `v`
    for (vertex = graph->neighbours[v]; vertex != NULL; vertex = vertex->next) {
        if (!visited[vertex->node_id]) {
            _dfs_(graph, vertex->node_id);  // Recurse if the node is not visited
        }
    }
}

// Function to perform DFS on the graph
Graph *graph_dfs(Graph *graph, int32_t v) {
    int i;
    // Mark all nodes as unvisited
    for (i = 0; i < graph->max_nodes; i++) {
        visited[i] = FALSE;
    }

    // Perform DFS starting from vertex v
    _dfs_(graph, v);
    return graph;
}
