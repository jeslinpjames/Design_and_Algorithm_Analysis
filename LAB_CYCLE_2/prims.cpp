#include <iostream>
#include <climits>

const int MAX = 100;

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V) {
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

void backtrack(int graph[MAX][MAX], int V, int u, bool visited[MAX]) {
    visited[u] = true;

    for (int v = 0; v < V; v++) {
        if (graph[u][v] && !visited[v]) {
            std::cout << "Backtrack: " << u << " -> " << v << "\n";
            backtrack(graph, V, v, visited);
        }
    }
}

int main() {
    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;

    int graph[MAX][MAX];
    std::cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            std::cin >> graph[i][j];

    primMST(graph, V);

    bool visited[MAX] = {false};
    std::cout << "\nBacktracking:\n";
    backtrack(graph, V, 0, visited);

    return 0;
}