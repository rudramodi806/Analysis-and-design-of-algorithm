#include <stdio.h>
#define MAX 100
#define INF 999999

int adjMatrix[MAX][MAX];
int visited[MAX];

// Prim's Algorithm
int primMST(int startVertex, int numVertices) {
    int minCost = 0;
    visited[startVertex] = 1;

    for (int count = 0; count < numVertices - 1; count++) {
        int minEdgeCost = INF;
        int src = -1, dest = -1;

        // Find the minimum edge from visited → unvisited
        for (int i = 0; i < numVertices; i++) {
            if (visited[i]) {
                for (int j = 0; j < numVertices; j++) {
                    if (!visited[j] && adjMatrix[i][j] > 0 && adjMatrix[i][j] < minEdgeCost) {
                        minEdgeCost = adjMatrix[i][j];
                        src = i;
                        dest = j;
                    }
                }
            }
        }

        if (src == -1 || dest == -1) {
            printf("Graph is disconnected. MST not possible.\n");
            return -1;
        }

        visited[dest] = 1;
        minCost += minEdgeCost;
        printf("Edge selected: (%d -> %d) with cost %d\n", src + 1, dest + 1, minEdgeCost);
    }

    return minCost;
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Initialize adjacency matrix
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the edges (src dest weight) [Vertices numbered from 1 to %d]:\n", numVertices);
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        src--; dest--; // convert to 0-based
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }

    printf("\n--------------- Prim's Algorithm ---------------\n");
    int totalPrimCost = primMST(0, numVertices);
    if (totalPrimCost != -1)
        printf("Total cost using Prim's algorithm: %d\n", totalPrimCost);

    return 0;
}
