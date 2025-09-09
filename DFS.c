#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array

// Function to add an edge (undirected)
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Depth First Search (DFS)
void DFS(int v, int n) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, e, u, v, start, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    // Reset visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal:\n");
    DFS(start, n);

    return 0;
}
