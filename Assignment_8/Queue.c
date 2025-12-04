#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;

// Check if empty
int isEmpty() {
	return (front > rear);
}

// Check if full
int isFull() {
	return (rear == MAX - 1);
}

// Insert
void enqueue(int x) {
	if (isFull()) {
		printf("Queue Overflow!\n");
		return;
	}
	queue[++rear] = x;
	printf("%d enqueued\n", x);
}

// Delete
void dequeue() {
	if (isEmpty()) {
		printf("Queue Underflow!\n");
		return;
	}
	printf("%d dequeued\n", queue[front]);
	front++;
}

// Peek
void peek() {
	if (isEmpty()) {
		printf("Queue is empty\n");
		return;
	}
	printf("Front element: %d\n", queue[front]);
}

// Display
void display() {
	if (isEmpty()) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue: ");
	for (int i = front; i <= rear; i++) {
		printf("%d ", queue[i]);
	}
	printf("\n");
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