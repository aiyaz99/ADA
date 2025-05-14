#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int x[MAX], n, count = 0;

int place(int k) {
    for (int i = 1; i < k; i++)
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))
            return 0;
    return 1;
}

void printSolution() {
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf(x[i] == j ? " Q " : " . ");
        printf("\n");
    }
    printf("\n");
}

void nQueen() {
    int k = 1;
    x[k] = 0;
    printf("Solutions to %d-Queens problem:\n", n);
    while (k > 0) {
        x[k]++;
        while (x[k] <= n && !place(k)) x[k]++;
        if (x[k] <= n) {
            if (k == n) {
                count++;
                printSolution();
            } else {
                x[++k] = 0;
            }
        } else {
            k--;
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid input (1 - %d allowed)\n", MAX);
        return 1;
    }
    nQueen();
    printf("Total number of solutions: %d\n", count);
    return 0;
}
