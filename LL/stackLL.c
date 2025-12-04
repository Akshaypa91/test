#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
	int data;
	struct Node* next;
};

struct Node* top = NULL; // top of stack

// Check if stack is empty
int isEmpty() {
	return top == NULL;
}

// Push (Add element)
void push(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Stack Overflow (No memory)!\n");
		return;
	}
	newNode->data = x;
	newNode->next = top;
	top = newNode;
	printf("%d pushed\n", x);
}

// Pop (Delete element)
void pop() {
	if (isEmpty()) {
		printf("Stack Underflow!\n");
	} else {
		struct Node* temp = top;
		printf("%d popped\n", top->data);
		top = top->next;
		free(temp);
	}
}

// Display stack
void display() {
	if (isEmpty()) {
		printf("Stack is empty\n");
	} else {
		printf("Stack: ");
		struct Node* temp = top;
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	push(10);
	push(20);
	push(30);
	display();
	pop();
	display();
	return 0;
}