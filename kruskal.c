#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 99999

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int cost[MAX][MAX], int n) {
    int i, j, u, v, a, b, min, edges = 0, total = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Kruskal's MST:\n");
    while (edges < n - 1) {
        min = INF;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && i != j) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (u != v) {
            union_set(u, v);
            printf("%d - %d : %d\n", a, b, min);
            total += min;
            edges++;
        }

        cost[a][b] = cost[b][a] = INF; // Mark edge as used
    }
    printf("Total cost of Kruskal's MST: %d\n", total);
}

int main() {
    int n, i, j;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (Use %d for no edge):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n);

    return 0;
}