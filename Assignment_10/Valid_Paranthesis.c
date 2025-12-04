#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push to stack
void push(char c) {
	if (top == MAX - 1) {
		printf("Stack overflow\n");
		return;
	}
	stack[++top] = c;
}

// pop from stack
char pop() {
	if (top == -1) {
		return '\0';	// indicates empty stack
	}
	return stack[top--];
}

// check if stack is empty
int isEmpty() {
	return (top == -1);
}

// check if a pair of brackets matches
int isMatching(char open, char close) {
	if (open == '(' && close == ')') return 1;
	if (open == '{' && close == '}') return 1;
	if (open == '[' && close == ']') return 1;
	return 0;
}

// function to check if parentheses are balanced
int isBalanced(char expr[]) {
	top = -1;	// reset stack

	for (int i = 0; expr[i] != '\0'; i++) {
		char c = expr[i];

		// if opening bracket, push
		if (c == '(' || c == '{' || c == '[') {
			push(c);
		}
		// if closing bracket, pop and check
		else if (c == ')' || c == '}' || c == ']') {
			if (isEmpty())		// nothing to match with
				return 0;

			char open = pop();
			if (!isMatching(open, c))
				return 0;
		}
		// else ignore other characters (if any)
	}

	// if stack empty → all matched
	return isEmpty();
}

int main() {
	char expr[MAX];

	printf("Enter expression with parentheses: ");
	scanf("%s", expr);	// reads until space/newline

	if (isBalanced(expr))
		printf("Parentheses are BALANCED\n");
	else
		printf("Parentheses are NOT BALANCED\n");

	return 0;
}