#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], n, visited[MAX], stack[MAX], top = -1;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i);
    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);
    while (top >= 0)
        printf("%d ", stack[top--]);
}

int main() {
    int edges, u, v;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);
   
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    printf("Topological Order: ");
    topologicalSort();
    return 0;
}