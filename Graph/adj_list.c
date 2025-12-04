#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
struct Node{
    int vertex;
    struct Node* next;
};

struct Node* Adjlist[MAX];
int size = 0;

struct Node* createnode(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = data;
    temp->next = NULL;
    return temp;
}

void create_graph(int vertices){
    int n = vertices;
    struct Node* temp = NULL;
    for(int i = 0; i < n; i++){
        temp = createnode(i);
        Adjlist[i] = temp;
        size++;
    }
    printf("Graph Created with %d nodes\n",n);
}

void insert_node(){
    if(size >= MAX) {
        printf("Graph full");
        return;
    }
    else{
        struct Node *temp = createnode(size);
        Adjlist[size] = temp;
        size++;
    }
    printf("Node inserted...\n");
}

void delete_edge(int u, int v){
    if(u < 0 || v < 0 || u >= size || v >= size){
        printf("Invalid edge ");
        return;
    }

    // delete v from u’s list
    struct Node* temp = Adjlist[u];
    struct Node* prev = NULL;

    while(temp != NULL && temp->vertex != v){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Edge not found ");
        return;
    }

    if(prev == NULL)  // first node after head
        Adjlist[u] = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    // delete u from v’s list
    temp = Adjlist[v];
    prev = NULL;

    while(temp != NULL && temp->vertex != u){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Edge not found ");
        return;
    }

    if(prev == NULL)
        Adjlist[v] = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

void delete_node(){
    if(size == 0) {
        printf("Graph Empty");
        return;
    }

    int node = size - 1;

    // remove edges pointing to this node
    for(int i = 0; i < size; i++){
        if(i != node)
            delete_edge(i, node);
    }

    // free the adjacency list of the node itself
    struct Node* temp = Adjlist[node];
    while(temp){
        struct Node* t = temp;
        temp = temp->next;
        free(t);
    }

    size--;
    printf("Node deleted...\n");
}

void insert_edge(int u, int v){
    if(u < 0 || v < 0 || u >= size || v >= size){
        printf("Invalid edge");
        return;
    }
    struct Node* temp = Adjlist[u];
    while(temp->next != NULL){
        temp = temp->next;
    }
    struct Node* x = createnode(v);
    temp->next = x;

    temp = Adjlist[v];
    while(temp->next != NULL){
        temp = temp->next;
    }
    x = createnode(u);
    temp->next = x;
}

void print_list(){
    for(int i = 0; i < size; i++){
        printf("%d -> ",i);
        struct Node* temp = Adjlist[i]->next;
        while(temp != NULL){
            printf("%d ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main(){
    int x;
    int u, v;
    printf("Enter number of nodes : ");
    scanf("%d",&x);
    create_graph(x);

    printf("Enter no of nodes do you want to insert : ");
    scanf("%d",&x);
    for(int i = 1; i <= x; i++) insert_node();
    print_list();

    // printf("Enter no of nodes do you want to delete : ");
    // scanf("%d",&x);
    // for(int i = 1; i <= x; i++) delete_node();
    // print_list();

    // printf("Enter no of edges do you want to insert : ");
    // scanf("%d",&x);
    // for(int i = 1; i <= x; i++){
    //     printf("Enter source and destination : ");
    //     scanf("%d %d",&u,&v);
    //     insert_edge(u,v);
    // }
    // print_list();

    // printf("Enter no of edges do you want to delete : ");
    // scanf("%d",&x);
    // for(int i = 1; i <= x; i++){
    //     printf("Enter source and destination : ");
    //     scanf("%d %d",&u,&v);
    //     delete_edge(u,v);
    // }
    // print_list();

    return 0;
}
