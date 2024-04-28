cmake_minimum_required(VERSION 3.27.8)
project(Algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(Djisktras_Algorithm
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