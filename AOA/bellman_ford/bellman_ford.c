#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int V, E;
    struct Edge *edge;
};

struct Graph *createGraph(int V, int E) {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edeg *) malloc(graph->E * sizeof(struct Edge));

    return graph;
}

void FinalSolution(int dist[], int n) {
    printf("\nVetex\tDistance from source vertex\n");
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void BellmanFord(struct Graph *graph, int source) {
    int V = graph->V;
    int E = graph->E;
    int StoreDistance[V];

    int i, j;

    for (i = 0; i < V; i++) {
        for (j = 0; j < E; j++) {
            int u = graph->edge[j].source;

            int v = graph->edge[j].destination;

            int weight = graph->edge[j].weight;

            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }

    }

    for (i = 0; i < E; i++) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;

        if (StoreDistance[u] + weight < StoreDistance[v])
            printf("This graph contains negative edge cycle\n");
    }

    FinalSolution(StoreDistance, V);

    return;
}

int main() {
    int V, E,S;

    printf("Enter number of vertices in graph\n");
    scanf("%d", &V);

    printf("Enter number of edges in graph\n");
    scanf("%d", &E);

    printf("Enter your source vertex number\n");
    scanf("%d", &S);

    struct Graph *graph = createGraph(V,E);

    int i;
    for (i=0; i < E; i++) {
        printf("\nEnter edge %d properties Source, destination, weight respectively\n", i +1);
        scanf("%d", &graph-> edge[i].source);
        scanf("%d", &graph->edge[i].destination);
        scanf("%d", &graph->edge[i].weight);
    }

    BellmanFord(graph,S);

    return 0;
}

/*
 * Enter number of vertices in graph
5
Enter number of edges in graph
10
Enter your source vertex number
0

Enter edge 1 properties Source, destination, weight respectively
0 1 6

Enter edge 2 properties Source, destination, weight respectively
0 2 7

Enter edge 3 properties Source, destination, weight respectively
1 2 8

Enter edge 4 properties Source, destination, weight respectively
1 4 -4

Enter edge 5 properties Source, destination, weight respectively
1 3 5

Enter edge 6 properties Source, destination, weight respectively
3 1 -2

Enter edge 7 properties Source, destination, weight respectively
2 3 -3

Enter edge 8 properties Source, destination, weight respectively
2 4 9

Enter edge 9 properties Source, destination, weight respectively
4 0 2

Enter edge 10 properties Source, destination, weight respectively
3 2 1
This graph contains negative edge cycle
This graph contains negative edge cycle
This graph contains negative edge cycle

Vetex   Distance from source vertex
0                12
1                12
2                13
3                12
4                10

Process finished with exit code 0
 */