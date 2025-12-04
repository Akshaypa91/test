#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int dest;
    int distance;
    struct Node *next;
};

struct AdjList {
    struct Node *head;
};

struct Graph {
    int total;
    struct AdjList *list;
    char **places;
};

struct Node *createNode(int dest, int distance) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->distance = distance;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int total) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->total = total;
    graph->list = (struct AdjList *)malloc(total * sizeof(struct AdjList));
    graph->places = (char **)malloc(total * sizeof(char *));

    for (int i = 0; i < total; i++) {
        graph->list[i].head = NULL;
        graph->places[i] = (char *)malloc(50 * sizeof(char));
    }
    return graph;
}

void setPlaceName(struct Graph *graph, int index, const char *name) {
    if (index < graph->total) {
        strncpy(graph->places[index], name, 49);
        graph->places[index][49] = '\0';
    }
}

void addConnection(struct Graph *graph, int src, int dest, int distance) {
    struct Node *newNode = createNode(dest, distance);
    newNode->next = graph->list[src].head;
    graph->list[src].head = newNode;

    newNode = createNode(src, distance);
    newNode->next = graph->list[dest].head;
    graph->list[dest].head = newNode;
}

void displayGraph(struct Graph *graph) {
    printf("\n--- City Landmarks and Distances (Adjacency List) ---\n");
    for (int i = 0; i < graph->total; i++) {
        struct Node *temp = graph->list[i].head;
        printf("\n%s (Node %d):", graph->places[i], i);
        while (temp) {
            printf(" -> %s (%dkm)", graph->places[temp->dest], temp->distance);
            temp = temp->next;
        }
        printf("\n");
    }
}

void deleteGraph(struct Graph *graph) {
    for (int i = 0; i < graph->total; i++) {
        struct Node *current = graph->list[i].head;
        while (current) {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
        free(graph->places[i]);
    }
    free(graph->list);
    free(graph->places);
    free(graph);
}

int main() {
    int V = 5;
    struct Graph *city = createGraph(V);

    setPlaceName(city, 0, "Airport");
    setPlaceName(city, 1, "Bus Stand");
    setPlaceName(city, 2, "Museum");
    setPlaceName(city, 3, "Library");
    setPlaceName(city, 4, "Market");

    addConnection(city, 0, 1, 8);
    addConnection(city, 0, 3, 5);
    addConnection(city, 1, 2, 3);
    addConnection(city, 2, 3, 6);
    addConnection(city, 2, 4, 4);
    addConnection(city, 3, 4, 7);

    displayGraph(city);
    deleteGraph(city);

    return 0;
}
