#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

// Check if stack is full
int isFull() {
	return top == MAX - 1;
}

// Check if stack is empty
int isEmpty() {
	return top == -1;
}

// Push (Add element)
void push(int x) {
	if (isFull()) {
		printf("Stack Overflow!\n");
	} else {
		stack[++top] = x;
		printf("%d pushed\n", x);
	}
}

// Pop (Delete element)
void pop() {
	if (isEmpty()) {
		printf("Stack Underflow!\n");
	} else {
		printf("%d popped\n", stack[top--]);
	}
}

// Traverse stack
void display() {
	if (isEmpty()) {
		printf("Stack is empty\n");
	} else {
		printf("Stack: ");
		for (int i = 0; i <= top; i++)
			printf("%d ", stack[i]);
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