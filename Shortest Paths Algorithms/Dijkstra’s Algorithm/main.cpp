#include "dijkstra.h"

int main() {
    Graph::AdjacencyMatrix<char, int> g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addVertex('F');
    g.addVertex('G');

    g.addEdge(4, 'D', 'A');
    g.addEdge(2, 'D', 'E');
    g.addEdge(3, 'A', 'C');
    g.addEdge(4, 'A', 'E');
    g.addEdge(4, 'E', 'C');
    g.addEdge(5, 'E', 'G');
    g.addEdge(5, 'C', 'F');
    g.addEdge(2, 'B', 'C');
    g.addEdge(2, 'B', 'F');
    g.addEdge(5, 'G', 'F');

//    add_edge(g, 3, 0, 4); // D -> A, weight 4
//    add_edge(g, 3, 4, 2); // D -> E, weight 2
//    add_edge(g, 0, 2, 3); // A -> C, weight 3
//    add_edge(g, 0, 4, 4); // A -> E, weight 4
//    add_edge(g, 4, 2, 4); // E -> C, weight 4
//    add_edge(g, 4, 6, 5); // E -> G, weight 5
//    add_edge(g, 2, 5, 5); // C -> F, weight 5
//    add_edge(g, 1, 2, 2); // B -> C, weight 2
//    add_edge(g, 1, 5, 2); // B -> F, weight 2
//    add_edge(g, 6, 5, 5); // G -> F, weight 5

    printf("Dijkstra's Algorithm starting from vertex D:\n\n");
    dijkstra<char, int>(g, 'D');
    return 0;
}