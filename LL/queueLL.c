#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
	int data;
	struct Node* next;
};

struct Node* front = NULL; // first element
struct Node* rear = NULL;  // last element

// Check if queue is empty
int isEmpty() {
	return front == NULL;
}

// Check if queue is full (memory allocation fails)
int isFull() {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp == NULL)
		return 1; // no memory → full
	free(temp); // free immediately (just testing)
	return 0;
}

// Enqueue (insert at rear)
void enqueue(int x) {
	if (isFull()) {
		printf("Queue Overflow (No memory)!\n");
		return;
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;

	if (rear == NULL) { // queue empty
		front = rear = newNode;
	} else {
		rear->next = newNode;
		rear = newNode;
	}
	printf("%d enqueued\n", x);
}

// Dequeue (remove from front)
void dequeue() {
	if (isEmpty()) {
		printf("Queue Underflow!\n");
	} else {
		struct Node* temp = front;
		printf("%d dequeued\n", front->data);
		front = front->next;
		if (front == NULL) // queue became empty
			rear = NULL;
		free(temp);
	}
}

// Peek (see front element without removing)
void peek() {
	if (isEmpty()) {
		printf("Queue is empty\n");
	} else {
		printf("Front element: %d\n", front->data);
	}
}

// Display queue
void display() {
	if (isEmpty()) {
		printf("Queue is empty\n");
	} else {
		printf("Queue: ");
		struct Node* temp = front;
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	enqueue(10);
	enqueue(20);
	enqueue(30);
	display();
	peek();
	dequeue();
	display();
	peek();
	return 0;
}