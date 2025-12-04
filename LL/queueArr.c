#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
	return (front == -1);
}

// Check if queue is full
int isFull() {
	return ((rear + 1) % MAX == front);
}

// Enqueue (insert at rear)
void enqueue(int x) {
	if (isFull()) {
		printf("Queue Overflow!\n");
		return;
	}
	if (isEmpty()) {
		front = rear = 0;
	} else {
		rear = (rear + 1) % MAX;
	}
	queue[rear] = x;
	printf("%d enqueued\n", x);
}

// Dequeue (remove from front)
void dequeue() {
	if (isEmpty()) {
		printf("Queue Underflow!\n");
		return;
	}
	printf("%d dequeued\n", queue[front]);
	if (front == rear) {
		front = rear = -1; // queue becomes empty
	} else {
		front = (front + 1) % MAX;
	}
}

// Peek (see front element without removing)
void peek() {
	if (isEmpty()) {
		printf("Queue is empty\n");
	} else {
		printf("Front element: %d\n", queue[front]);
	}
}

// Display queue
void display() {
	if (isEmpty()) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue: ");
	while (1) {
		printf("%d ", queue[front]);
		if (front == rear) break;
		front = (front + 1) % MAX;
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