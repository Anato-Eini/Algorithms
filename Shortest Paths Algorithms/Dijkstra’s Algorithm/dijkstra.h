#ifndef ALGORITHMS_DIJKSTRA_H
#define ALGORITHMS_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <climits>

#include "Adjacency Matrix/AdjacencyMatrix.h"
#include "Adjacency Matrix/AdjacencyMatrix.cpp"

size_t minDistance(std::vector<size_t> &distances, std::vector<bool> &visited){
    size_t min = SIZE_MAX, minIndex, size = distances.size();

    for(int i = 0; i < size; i++)
        if(!visited[i] && distances[i] < min) {
            min = distances[i];
            minIndex = i;
        }
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

    bool isFirst = true; //For printing arrows

    for(size_t i = 0; i < numVertex - 1; i++) {
        size_t minIndex = minDistance(distances, visited);

        if(isFirst)
            isFirst = false;
        else
            std::cout << " -> ";

        std::cout << vertices[minIndex];
        visited[minIndex] = true;

        for (size_t j = 0; j < numVertex; j++)
            if (!visited[j] && graph.getEdge(vertices[minIndex], vertices[j])
                && distances[j] > distances[minIndex] + graph.getEdge(vertices[minIndex], vertices[j]))
                distances[j] = distances[minIndex] + graph.getEdge(vertices[minIndex], vertices[j]);
    }
}

#endif //ALGORITHMS_DIJKSTRA_H
