#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
};

// Create new node
struct CNode* createNode(int data) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = data;
    newNode->next = newNode; // points to itself (circular)
    return newNode;
}

/* ---------------- INSERT OPERATIONS ---------------- */

// Insert at Beginning
struct CNode* insAtBeg(struct CNode* head, int data) {
    struct CNode* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct CNode* temp = head;
    while (temp->next != head)  // go to last node
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    return newNode; // new head
}

// Insert at End
struct CNode* insAtEnd(struct CNode* head, int data) {
    struct CNode* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Insert at Position (1-based)
struct CNode* insAtPos(struct CNode* head, int data, int pos) {
    if (pos < 1) return head;

    if (pos == 1) return insAtBeg(head, data);

    struct CNode* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    struct CNode* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

/* ---------------- DELETE OPERATIONS ---------------- */

// Delete at Beginning
struct CNode* delAtBeg(struct CNode* head) {
    if (head == NULL) return NULL;

    if (head->next == head) { // only one node
        free(head);
        return NULL;
    }

    struct CNode* temp = head;
    struct CNode* last = head;

    while (last->next != head) // find last node
        last = last->next;

    head = head->next;
    free(temp);
    last->next = head;
    return head;
}

// Delete at End
struct CNode* delAtEnd(struct CNode* head) {
    if (head == NULL) return NULL;

    if (head->next == head) { // only one node
        free(head);
        return NULL;
    }

    struct CNode* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    struct CNode* last = temp->next;
    temp->next = head;
    free(last);
    return head;
}

// Delete at Position
struct CNode* delAtPos(struct CNode* head, int pos) {
    if (head == NULL || pos < 1) return head;

    if (pos == 1) return delAtBeg(head);

    struct CNode* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) return head; // position out of range

    struct CNode* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

    return head;
}

// Traverse
void printList(struct CNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CNode* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Count and print elements of circular linked list
void countLL(struct CNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int cnt = 0;
    struct CNode* temp = head;

    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        cnt++;
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
    printf("Count = %d\n", cnt);
}

int main() {
    struct CNode* head = NULL;

    // Insertions
    head = insAtBeg(head, 10);
    head = insAtBeg(head, 20);
    head = insAtEnd(head, 30);
    head = insAtPos(head, 25, 3);

    printf("After Insertions: ");
    printList(head);

    // Deletions
    head = delAtBeg(head);
    printf("After Deleting Beginning: ");
    printList(head);

    head = delAtEnd(head);
    printf("After Deleting End: ");
    printList(head);

    head = delAtPos(head, 2);
    printf("After Deleting Position 2: ");
    printList(head);

    countLL(head);

    return 0;
}
