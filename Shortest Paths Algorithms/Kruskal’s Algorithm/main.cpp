#include "iostream"
#include "Edge List/EdgeList.h"
#include "General Graph/GraphAbstract.h"

int main()
{
    Graph::GraphAbstract<char, int> & graph_abstract = *new Graph::EdgeList<char, int>();
    graph_abstract.addVertex('A').addVertex('B').addVertex('C').addVertex('D').addVertex('E').addVertex('F')
                .addVertex('G').addVertex('H').addVertex('I');
    graph_abstract.addEdge(7, 'F', 'A').addEdge(6, 'F', 'E').addEdge(5, 'F', 'I')
    .addEdge(2, 'A', 'B').addEdge(3, 'A', 'G').addEdge(1, 'I', 'G')
    .addEdge(2, 'I', 'E').addEdge(6, 'G', 'B').addEdge(4, 'I', 'H')
    .addEdge(1, 'E', 'D').addEdge(3, 'G', 'H').addEdge(8, 'H', 'D')
    .addEdge(4, 'B', 'C').addEdge(2, 'H', 'C').addEdge(2, 'D', 'C');

    std::cout << graph_abstract;
    return 0;
}
