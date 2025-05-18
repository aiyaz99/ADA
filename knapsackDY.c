#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int M, int w[], int p[]) {
    int v[n + 1][M + 1];
    int x[n + 1];
    int i, j;

    // Build table v[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
        }
    }

    // Initialize selection array
    for (i = 1; i <= n; i++)
        x[i] = 0;

    // Traceback to find selected items
    i = n;
    j = M;
    while (i != 0 && j != 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i] = 1;
            j = j - w[i];
        }
        i--;
    }

    // Print selected objects and max profit
    printf("\nSelected objects:\n");
    for (i = 1; i <= n; i++) {
        if (x[i])
            printf("Object %d selected\n", i);
        else
            printf("Object %d not selected\n", i);
    }

    printf("Maximum profit: %d\n", v[n][M]);
}

int main() {
    int n, M, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);

    int w[n + 1], p[n + 1];

    printf("Enter weights of %d items:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter profits of %d items:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    knapsack(n, M, w, p);

    return 0;
}