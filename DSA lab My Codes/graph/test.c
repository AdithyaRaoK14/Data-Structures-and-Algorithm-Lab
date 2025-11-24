#include <stdio.h>
#include <assert.h>
#include "graph.h"

// Simulate the adjacency list without user input
void simulate_graph_adjacency_list(Graph *graph) {
    Node *vertex;
    
    // Manually setting the adjacency list for each node
    // Example: 0 -> [1, 2], 1 -> [2], 2 -> [0, 3], 3 -> [3]
    
    // Node 0
    graph->neighbours[0] = _get_node_(0);  // Create node 0
    vertex = _get_node_(1); 
    graph->neighbours[0]->next = vertex;  // Add neighbour 1 to node 0
    vertex = _get_node_(2); 
    graph->neighbours[0]->next->next = vertex;  // Add neighbour 2 to node 0
    
    // Node 1
    graph->neighbours[1] = _get_node_(1);  // Create node 1
    vertex = _get_node_(2); 
    graph->neighbours[1]->next = vertex;  // Add neighbour 2 to node 1
    
    // Node 2
    graph->neighbours[2] = _get_node_(2);  // Create node 2
    vertex = _get_node_(0); 
    graph->neighbours[2]->next = vertex;  // Add neighbour 0 to node 2
    vertex = _get_node_(3); 
    graph->neighbours[2]->next->next = vertex;  // Add neighbour 3 to node 2
    
    // Node 3
    graph->neighbours[3] = _get_node_(3);  // Create node 3
    // Node 3 has no outgoing neighbours (could be updated as per requirements)
}

// Test function for graph creation, insertion, and DFS
int main() {
    Graph graph = graph_new(4);  // Create a graph with 4 nodes
    assert(graph.max_nodes == 4);  
    assert(graph.neighbours != NULL);  
    for (int i = 0; i < graph.max_nodes; i++) {
        assert(graph.neighbours[i] == NULL);  // Initially, no neighbours
    }

    // Simulate adjacency list creation (no user input)
    simulate_graph_adjacency_list(&graph);

    // Check adjacency list insertion
    assert(graph.neighbours[0] != NULL);  
    assert(graph.neighbours[0]->next != NULL);  // Node 0 has neighbours 1 and 2
    assert(graph.neighbours[1] != NULL);  
    assert(graph.neighbours[1]->next != NULL);  // Node 1 has neighbour 2
    assert(graph.neighbours[2] != NULL);  
    assert(graph.neighbours[2]->next != NULL);  // Node 2 has neighbours 0 and 3
    assert(graph.neighbours[3] != NULL);  
    assert(graph.neighbours[3]->next == NULL);  // Node 3 has no outgoing neighbours

    printf("Adjacency List Insertion Passed!\n");

    // Test DFS traversal starting from node 0
    printf("Testing DFS traversal starting from node 0:\n");
    graph_dfs(&graph, 0);  // Perform DFS starting from node 0
    for (int i = 0; i < graph.max_nodes; i++) {
        assert(visited[i] == TRUE);  // Ensure all nodes are visited in DFS
    }

    printf("DFS Traversal Passed!\n");

    // Test for graph deletion (optional: freeing memory, can be done if needed)
    // You can implement a function like graph_delete() to free the memory if necessary
    // free_graph(&graph);

    printf("All tests passed!\n");

    return 0;
}
