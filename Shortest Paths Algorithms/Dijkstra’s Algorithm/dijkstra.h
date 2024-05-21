#ifndef ALGORITHMS_DIJKSTRA_H
#define ALGORITHMS_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <climits>

#include "Adjacency Matrix/AdjacencyMatrix.h"
#include "Adjacency Matrix/AdjacencyMatrix.cpp"

template <typename V, typename E>
size_t minDistance(std::vector<size_t> &distances, std::vector<bool> &visited){
    size_t min = SIZE_MAX, minIndex, size = distances.size();

    for(minIndex = 0; minIndex < size; minIndex++)
        if(!visited[minIndex] && distances[minIndex] < min)
            min = distances[minIndex];
    return minIndex;
}

template <typename V, typename E>
void dijkstra(Graph::GraphAbstract<V, E>& graph, V vertex) {
    size_t numVertex = graph.numVertices(), indexOf;

    std::vector<V> vertices = graph.vertices();

    std::vector<size_t> distances(numVertex - 1, SIZE_MAX);
    std::vector<bool> visited(numVertex - 1, false);

    for(indexOf = 0; indexOf < numVertex; indexOf++)
        if(vertices[indexOf] == vertex)
            break;

    distances[indexOf] = 0;

    for(size_t i = 0; i < numVertex - 1; i++) {
        size_t minIndex = minDistance<V, E>(distances, visited);

        std::cout << " -> " << vertices[minIndex];
        visited[minIndex] = true;

        for (size_t j = 0; j < numVertex; j++)
            if (!visited[j] && graph.getEdge(vertices[minIndex], vertices[j])
                && distances[j] < distances[minIndex] + graph.getEdge(distances[minIndex], distances[j]))
                distances[j] = distances[minIndex] + graph.getEdge(distances[minIndex], distances[j]);
    }
}

#endif //ALGORITHMS_DIJKSTRA_H
