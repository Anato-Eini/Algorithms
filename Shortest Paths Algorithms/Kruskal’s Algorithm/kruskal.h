#ifndef ALGORITHMS_KRUSKAL_H
#define ALGORITHMS_KRUSKAL_H

#include "Edge List/EdgeList.h"

//This function will only work if edges are integers

template <typename V, typename E>
int kruskal(Graph::EdgeList<V, E>& graph){
    std::vector<E> * edges = graph.edges();
    std::sort(edges.begin(), edges.end());
    std::vector<V> * vertices = graph.vertices();
    std::vector<std::vector<V>> sets;

    std::transform(vertices.begin(), vertices.end(), std::back_inserter(sets),
        [](const V & vertex) -> V { return {vertex}; }
    );

    int mstCount = 0;

    size_t & verticesSize = sets.size();

    while(verticesSize != 1)
    {

    }

    return mstCount;
}


#endif //ALGORITHMS_KRUSKAL_H