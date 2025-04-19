//Prims's and Kruskal's Algorithm

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX], parent[MAX], key[MAX], visited[MAX];
int numVertices;

void prims() {
    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    key[0] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int minKey = INF, u;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge\tWeight\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[parent[i]][i]);
    }
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskals() {
    int edges[MAX][3], edgeCount = 0;

    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (graph[i][j]) {
                edges[edgeCount][0] = i;
                edges[edgeCount][1] = j;
                edges[edgeCount][2] = graph[i][j];
                edgeCount++;
            }
        }
    }

    for (int i = 0; i < edgeCount; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp[3];
                for (int k = 0; k < 3; k++) {
                    temp[k] = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp[k];
                }
            }
        }
    }

    for (int i = 0; i < numVertices; i++) {
        parent[i] = -1;
    }

    printf("Edge\tWeight\n");
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (find(parent, u) != find(parent, v)) {
            printf("%d - %d\t%d\n", u, v, w);
            unionSet(parent, u, v);
        }
    }
}

int main() {
    int choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Prim's Algorithm\n");
        printf("2. Kruskal's Algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Minimum Cost Spanning Tree using Prim's Algorithm:\n");
                prims();
                break;
            case 2:
                printf("Minimum Cost Spanning Tree using Kruskal's Algorithm:\n");
                kruskals();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}