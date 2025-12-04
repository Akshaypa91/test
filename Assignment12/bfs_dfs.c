#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

struct AdjNode {
    int dest;
    struct AdjNode *next;
};

struct Graph {
    int vertices;
    struct AdjNode **list;
};

struct AdjNode *createAdjNode(int dest) {
    struct AdjNode *node = (struct AdjNode *)malloc(sizeof(struct AdjNode));
    node->dest = dest;
    node->next = NULL;
    return node;
}

struct Graph *createGraph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->list = (struct AdjNode **)malloc(vertices * sizeof(struct AdjNode *));
    for (int i = 0; i < vertices; i++)
        graph->list[i] = NULL;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    struct AdjNode *node = createAdjNode(dest);
    node->next = graph->list[src];
    graph->list[src] = node;

    node = createAdjNode(src);
    node->next = graph->list[dest];
    graph->list[dest] = node;
}

void BFS(struct Graph *graph, int start) {
    int *visited = calloc(graph->vertices, sizeof(int));
    int queue[MAX_SIZE], front = 0, rear = 0;

    printf("\nBreadth First Search starting from vertex %d:\n", start);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct AdjNode *temp = graph->list[current];
        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = 1;
                queue[rear++] = temp->dest;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
}

void DFS_recursiveUtil(struct Graph *graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct AdjNode *temp = graph->list[vertex];
    while (temp) {
        if (!visited[temp->dest])
            DFS_recursiveUtil(graph, temp->dest, visited);
        temp = temp->next;
    }
}

void DFS_recursive(struct Graph *graph, int start) {
    int *visited = calloc(graph->vertices, sizeof(int));
    printf("\nDepth First Search (Recursive) starting from vertex %d:\n", start);
    DFS_recursiveUtil(graph, start, visited);
    printf("\n");
    free(visited);
}

void DFS_nonRecursive(struct Graph *graph, int start) {
    int *visited = calloc(graph->vertices, sizeof(int));
    int stack[MAX_SIZE], top = -1;

    printf("\nDepth First Search (Non-Recursive) starting from vertex %d:\n", start);
    stack[++top] = start;

    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
        }

        struct AdjNode *temp = graph->list[v];
        while (temp) {
            if (!visited[temp->dest])
                stack[++top] = temp->dest;
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
}

int main() {
    int vertices = 6;   // Vertices: A, B, C, D, E, F
    struct Graph *graph = createGraph(vertices);

    // Hardcoded edges between landmarks (A–F)
    addEdge(graph, 0, 1);  // A-B
    addEdge(graph, 0, 2);  // A-C
    addEdge(graph, 1, 3);  // B-D
    addEdge(graph, 1, 4);  // B-E
    addEdge(graph, 2, 5);  // C-F

    printf("Graph created with vertices: A, B, C, D, E, F\n\n");

    printf("Breadth First Search starting from A (vertex 0):\n");
    BFS(graph, 0);

    printf("\nDepth First Search (Recursive) starting from A:\n");
    DFS_recursive(graph, 0);

    printf("\nDepth First Search (Non-Recursive) starting from A:\n");
    DFS_nonRecursive(graph, 0);

    return 0;
}