cmake_minimum_required(VERSION 3.28.1)
project(Algorithms)

set(CMAKE_CXX_STANDARD 26)

add_executable(Dijkstra_Algorithm
        "Dijkstra’s Algorithm/General Graph/GraphAbstract.h"
        "Dijkstra’s Algorithm/Adjacency Matrix/AdjacencyMatrix.h"
        "Dijkstra’s Algorithm/General Graph/GraphAbstract.cpp"
        "Dijkstra’s Algorithm/Adjacency Matrix/AdjacencyMatrix.cpp"
        "Dijkstra’s Algorithm/dijkstra.h"
        "Dijkstra’s Algorithm/main.cpp"
)

add_executable(Minimum_Spanning_Trees
        "Minimum Spanning Trees/main.cpp"
)

add_executable(Prim-Jarnik_Algorithm
        "Prim-Jarnik Algorithm/main.cpp"
)

add_executable(Kruskals_Algorithm
        "Kruskal’s Algorithm/main.cpp"
)