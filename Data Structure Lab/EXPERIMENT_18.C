
#include <stdio.h>

#define MAX 20
#define INF 99999

int main() {
    int cost[MAX][MAX];
    int selected[MAX] = {0};
    int n, i, j, edges = 0;
    int x, y, min, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 for no edge):\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    selected[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;
        x = -1;
        y = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1) {
            printf("Graph is disconnected.\n");
            return 0;
        }

        printf("%d - %d : %d\n", x, y, min);

        total += min;
        selected[y] = 1;
        edges++;
    }

    printf("Total MST cost = %d\n", total);

    printf("Alok Pandey 2501920100076\n");
    return 0;
}