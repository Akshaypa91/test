//Insert an Element

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

//Create new Node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Insert at Beginning
struct ListNode* insAtBeg(struct ListNode* head, int data) {
    struct ListNode* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

//Insert at End
struct ListNode* insAtEnd(struct ListNode* head, int data) {
    struct ListNode* newNode = createNode(data);
    if(head == NULL) return newNode;

    struct ListNode* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//Insert at position
struct ListNode* insAtPos(struct ListNode* head, int data, int pos) {
    if (pos < 1)
        return head;

    if (pos == 1) {
        struct ListNode* newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }

    struct ListNode* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return head;

    struct ListNode* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

//Print List
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = NULL;

    head = insAtBeg(head, 10);
    head = insAtBeg(head, 20);

    head = insAtEnd(head, 30);

    head = insAtPos(head, 25, 3);

    printList(head);
    return 0;
}