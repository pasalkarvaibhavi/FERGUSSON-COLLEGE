//Dijkstra's Alogorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    int distances[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int minDistance = INT_MAX;
        int minIndex;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && distances[v] <= minDistance) {
                minDistance = distances[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[minIndex][v] && distances[minIndex] != INT_MAX && 
                distances[minIndex] + graph[minIndex][v] < distances[v]) {
                distances[v] = distances[minIndex] + graph[minIndex][v];
            }
        }
    }

    printf("Vertex\tDistance from Source (%d)\n", startVertex);
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\n", i, distances[i]);
    }
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (src dest weight):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }

    int startVertex;
    printf("Enter the source vertex: ");
    scanf("%d", &startVertex);

    dijkstra(graph, numVertices, startVertex);

    return 0;
}