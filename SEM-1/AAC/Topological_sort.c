//topological sort

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void topologicalSortUtil(int v, int adj[MAX_VERTICES][MAX_VERTICES], int visited[], int stack[], int *top, int numVertices) {
    visited[v] = 1;

    for (int i = 0; i < numVertices; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            topologicalSortUtil(i, adj, visited, stack, top, numVertices);
        }
    }

    stack[(*top)++] = v;
}

void topologicalSort(int adj[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int top = 0;

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, stack, &top, numVertices);
        }
    }

    printf("Topological sorting of the graph: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int adj[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1; 
    }

    topologicalSort(adj, numVertices);

    return 0;
}