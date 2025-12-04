#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

// Create new node
struct DNode* createNode(int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at Beginning
struct DNode* insAtBeg(struct DNode* head, int data) {
    struct DNode* newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;  // new head
}

// Insert at End
struct DNode* insAtEnd(struct DNode* head, int data) {
    struct DNode* newNode = createNode(data);
    if (head == NULL) return newNode;

    struct DNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert at Position (1-based)
struct DNode* insAtPos(struct DNode* head, int data, int pos) {
    if (pos < 1) return head;

    if (pos == 1) return insAtBeg(head, data);

    struct DNode* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) return head; // out of range

    struct DNode* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

// Delete at Beginning
struct DNode* delAtBeg(struct DNode* head) {
    if (head == NULL) return NULL;

    struct DNode* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

// Delete at End
struct DNode* delAtEnd(struct DNode* head) {
    if (head == NULL) return NULL;

    struct DNode* temp = head;
    if (temp->next == NULL) { // only one node
        free(temp);
        return NULL;
    }
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Delete at Position (1-based)
struct DNode* delAtPos(struct DNode* head, int pos) {
    if (head == NULL || pos < 1) return head;

    if (pos == 1) return delAtBeg(head);

    struct DNode* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) return head; // invalid position

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}

// Traverse
void printList(struct DNode* head) {
    struct DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count the number of elements in a doubly linked list
void count(struct DNode* head) {
	int cnt = 0;
	struct DNode* temp = head;

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	printf("List: ");
	while (temp != NULL) {
		printf("%d <-> ", temp->data);
		cnt++;
		temp = temp->next;
	}

	printf("NULL\n");
	printf("Count = %d\n", cnt);
}

// Search an element in a doubly linked list
void searchLL(struct DNode* head, int key) {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct DNode* temp = head;
	int pos = 1;

	while (temp != NULL) {
		if (temp->data == key) {
			printf("Element %d found at position %d\n", key, pos);
			return;
		}
		temp = temp->next;
		pos++;
	}

	printf("Element %d not found in the list\n", key);
}

// Traverse doubly linked list in reverse order
void reverseTraverse(struct DNode* head) {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	// Go to last node
	struct DNode* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	// Now traverse backward
	printf("Reverse: ");
	while (temp != NULL) {
		printf("%d <-> ", temp->data);
		temp = temp->prev;
	}
	printf("NULL\n");
}

int main() {
    struct DNode* head = NULL;

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

    head = insAtBeg(head, 50);
    head = insAtEnd(head, 70);

    count(head);

    searchLL(head, 70);
    searchLL(head, 100);

    reverseTraverse(head);

    return 0;
}