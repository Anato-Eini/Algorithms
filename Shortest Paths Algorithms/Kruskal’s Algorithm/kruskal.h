#ifndef ALGORITHMS_KRUSKAL_H
#define ALGORITHMS_KRUSKAL_H

#include <set>

#include "Edge List/EdgeList.h"

//This function will only work if edges are integers

template <typename V, typename E>
int kruskal(Graph::EdgeList<V, E>& graph){
    std::vector<E> edges = graph.edges();
    std::set<std::pair<E, std::pair<V, V>>> MST;

    for(E edge : edges){
        MST.insert({edge, graph.endVertices(edge)});
    }


    int mstCount = 0;



    return 0;
}


#endif //ALGORITHMS_KRUSKAL_H
