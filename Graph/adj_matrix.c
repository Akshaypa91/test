#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Problem Statement (Graphs):
// Write a C Program to Create a Graph using adjacency structures and perform
// a. Insert a node into the graph
// b. Insert an edge into the graph
// c. Delete a node from the graph
// d. Delete an edge from the graph
// e. Find a node and edge in the graph

#define MAX 20
int adj[MAX][MAX];
int n;

void createGraph(int vertices) {
    n = vertices;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    printf("Undirected Graph created with %d vertices.\n", n);
}

void insertEdge(int src, int dest) {
    if (src > n || dest > n || src < 0 || dest < 0) {
        printf("Invalid node number!\n");
        return;
    }
    adj[src][dest] = 1;
    adj[dest][src] = 1;
    printf("Edge inserted between %d and %d.\n", src, dest);
}

void insertNode() {
    if (n == MAX - 1) {
        printf("Graph is full! Cannot insert more nodes.\n");
        return;
    }
    n++;
    for (int i = 0; i < n; i++) {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
    printf("Node %d added successfully.\n", n);
}

void deleteEdge(int src, int dest) {
    if (src > n || dest > n || src < 1 || dest < 1) {
        printf("Invalid node number!\n");
        return;
    }
    adj[src][dest] = 0;
    adj[dest][src] = 0;
    printf("Edge deleted between %d and %d.\n", src, dest);
}

void deleteNode(int node) {
    if (node > n || node < 0) {
        printf("Invalid node number!\n");
        return;
    }

    for (int i = node; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = adj[i + 1][j];


    for (int i = 0; i < n - 1; i++)
        for (int j = node; j < n; j++)
            adj[i][j] = adj[i][j + 1];

    n--;
    printf("Node %d deleted successfully.\n", node);
}

void findNode(int node) {
    if (node >= 1 && node <= n)
        printf("Node %d exists in the graph.\n", node);
    else
        printf("Node %d not found.\n", node);
}

void findEdge(int src, int dest) {
    if (src > n || dest > n || src < 1 || dest < 1) {
        printf("Invalid node number!\n");
        return;
    }
    if (adj[src][dest] == 1)
        printf("Edge exists between %d and %d.\n", src, dest);
    else
        printf("Edge does not exist between %d and %d.\n", src, dest);
}

void displayGraph() {
    printf("\nAdjacency Matrix of Undirected Graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

int main() {
    int vertices, edges, src, dest, node;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source & destination):\n");
    for (int i = 1; i <= edges; i++) {
        printf("Edge %d: ", i);
        scanf("%d %d", &src, &dest);
        insertEdge(src, dest);
    }

    printf("\nInitial Graph:\n");
    displayGraph();

    int x;
    printf("\nEnter how many nodes to insert: ");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
        insertNode();
    printf("\nAfter inserting nodes:\n");
    displayGraph();

    printf("\nEnter source and destination to insert edge: ");
    scanf("%d %d", &src, &dest);
    insertEdge(src, dest);
    displayGraph();

    // printf("\nEnter node to delete: ");
    // scanf("%d", &node);
    // deleteNode(node);
    // displayGraph();

    // printf("\nEnter source and destination to delete edge: ");
    // scanf("%d %d", &src, &dest);
    // deleteEdge(src, dest);
    // displayGraph();

    // printf("\nEnter node to find: ");
    // scanf("%d", &node);
    // findNode(node);

    // printf("\nEnter source and destination to find edge: ");
    // scanf("%d %d", &src, &dest);
    // findEdge(src, dest);

    return 0;
}
