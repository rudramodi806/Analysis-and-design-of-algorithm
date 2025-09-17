#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 99999

void prim(int cost[MAX][MAX], int n) {
    int selected[MAX] = {0};
    int i, j, u = 0, v = 0, min, edges = 0, total = 0;

    selected[0] = 1;

    printf("\nEdges in Prim's MST:\n");
    while (edges < n - 1) {
        min = INF;
        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, cost[u][v]);
        total += cost[u][v];
        selected[v] = 1;
        edges++;
    }
    printf("Total cost of Prim's MST: %d\n", total);
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

    prim(cost, n);

    return 0;
}