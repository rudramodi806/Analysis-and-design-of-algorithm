#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int src, dest, weight;
} Edge;

Edge edgeList[MAX];
int parent[MAX], treeRank[MAX];

// DSU Find with Path Compression
int findSet(int vertex) {
    if (parent[vertex] != vertex)
        parent[vertex] = findSet(parent[vertex]);
    return parent[vertex];
}

// DSU Union by Rank
void unionSets(int setA, int setB) {
    int rootA = findSet(setA);
    int rootB = findSet(setB);

    if (rootA != rootB) {
        if (treeRank[rootA] > treeRank[rootB]) {
            parent[rootB] = rootA;
        } else if (treeRank[rootA] < treeRank[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootB] = rootA;
            treeRank[rootA]++;
        }
    }
}

// Comparator for qsort
int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Kruskal's Algorithm
int kruskalMST(int numVertices, int numEdges) {
    // Initialize DSU
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
        treeRank[i] = 0;
    }

    // Sort edges by weight
    qsort(edgeList, numEdges, sizeof(Edge), compareEdges);

    int minCost = 0, edgesUsed = 0;

    for (int i = 0; i < numEdges && edgesUsed < numVertices - 1; i++) {
        int src = edgeList[i].src;
        int dest = edgeList[i].dest;
        int weight = edgeList[i].weight;

        if (findSet(src) != findSet(dest)) {
            unionSets(src, dest);
            minCost += weight;
            edgesUsed++;
            printf("Edge selected: (%d -> %d) with cost %d\n", src + 1, dest + 1, weight);
        }
    }

    if (edgesUsed != numVertices - 1) {
        printf("Graph is disconnected. MST not possible.\n");
        return -1;
    }

    return minCost;
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (src dest weight) [Vertices numbered from 1 to %d]:\n", numVertices);
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        src--; dest--; // convert to 0-based
        edgeList[i].src = src;
        edgeList[i].dest = dest;
        edgeList[i].weight = weight;
    }

    printf("\n-------------- Kruskal's Algorithm --------------\n");
    int totalKruskalCost = kruskalMST(numVertices, numEdges);
    if (totalKruskalCost != -1)
        printf("Total cost using Kruskal's algorithm: %d\n", totalKruskalCost);

    return 0;
}
