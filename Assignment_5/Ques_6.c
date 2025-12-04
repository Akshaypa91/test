//Reverse Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* reverseLL(struct Node* head) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (temp != NULL){
        next = temp->next;
        temp->next = prev;

        prev = temp;
        temp = next;
    }
    return prev;
}

// Print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    printf("Original Linked List:\n");
    printList(head);

    printf("Reverse Linked List:\n");
    head = reverseLL(head);
    printList(head);
    return 0;
}