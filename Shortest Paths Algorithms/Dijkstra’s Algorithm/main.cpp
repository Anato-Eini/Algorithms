#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int **adj_matrix;
    char *vertex_data;
    int size;
} Graph;

Graph* create_graph(int size) {
    Graph *g = new Graph{};
    g->size = size;
    g->adj_matrix = new int*[size];
    for (int i = 0; i < size; i++)
        g->adj_matrix[i] = (int*) calloc(size, sizeof (int));

    g->vertex_data = new char[size];
    return g;
}

void add_edge(Graph *g, int u, int v, int weight) {
    if (u >= 0 && u < g->size && v >= 0 && v < g->size) {
        g->adj_matrix[u][v] = weight;
    }
}

void add_vertex_data(Graph *g, int vertex, char data) {
    if (vertex >= 0 && vertex < g->size) {
        g->vertex_data[vertex] = data;
    }
}

int min_distance(int distances[], bool visited[], int size) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < size; v++) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(Graph *g, char start_vertex_data) {
    int start_vertex = -1;
    for (int i = 0; i < g->size; i++) {
        if (g->vertex_data[i] == start_vertex_data) {
            start_vertex = i;
            break;
        }
    }

    int distances[g->size];
    bool visited[g->size];

    for (int i = 0; i < g->size; i++) {
        distances[i] = INT_MAX, visited[i] = false;
    }

    distances[start_vertex] = 0;

    for (int count = 0; count < g->size - 1; count++) {
        int u = min_distance(distances, visited, g->size);
        visited[u] = true;

        for (int v = 0; v < g->size; v++) {
            if (!visited[v] && g->adj_matrix[u][v] && distances[u] != INT_MAX
                && distances[u] + g->adj_matrix[u][v] < distances[v]) {
                distances[v] = distances[u] + g->adj_matrix[u][v];
            }
        }
    }

    for (int i = 0; i < g->size; i++) {
        printf("Shortest distance from %c to %c: %d\n", start_vertex_data, g->vertex_data[i], distances[i]);
    }
}

void free_graph(Graph *g) {
    for (int i = 0; i < g->size; i++) {
        free(g->adj_matrix[i]);
    }
    free(g->adj_matrix);
    free(g->vertex_data);
    free(g);
}

int main() {
    Graph *g = create_graph(7);

    add_vertex_data(g, 0, 'A');
    add_vertex_data(g, 1, 'B');
    add_vertex_data(g, 2, 'C');
    add_vertex_data(g, 3, 'D');
    add_vertex_data(g, 4, 'E');
    add_vertex_data(g, 5, 'F');
    add_vertex_data(g, 6, 'G');

    add_edge(g, 3, 0, 4); // D -> A, weight 4
    add_edge(g, 3, 4, 2); // D -> E, weight 2
    add_edge(g, 0, 2, 3); // A -> C, weight 3
    add_edge(g, 0, 4, 4); // A -> E, weight 4
    add_edge(g, 4, 2, 4); // E -> C, weight 4
    add_edge(g, 4, 6, 5); // E -> G, weight 5
    add_edge(g, 2, 5, 5); // C -> F, weight 5
    add_edge(g, 1, 2, 2); // B -> C, weight 2
    add_edge(g, 1, 5, 2); // B -> F, weight 2
    add_edge(g, 6, 5, 5); // G -> F, weight 5

    printf("Dijkstra's Algorithm starting from vertex D:\n\n");
    dijkstra(g, 'D');

    free_graph(g);
    return 0;
}

//C