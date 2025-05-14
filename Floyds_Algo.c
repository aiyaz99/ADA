#include <stdio.h>
#define INF 999
#define MAX 10

void floyd(int a[MAX][MAX], int n) {
    int d[MAX][MAX];

    // Step 1: Initialize the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = a[i][j];
        }
    }

    // Step 2: Floyd-Warshall main loop
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // Step 3: Print the final shortest distance matrix
    printf("Shortest Distance Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", d[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int a[MAX][MAX];

    printf("Enter the cost adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    floyd(a, n);

    return 0;
}
