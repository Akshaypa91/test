#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push and pop for char stack
void push(char c) {
	stack[++top] = c;
}
char pop() {
	return stack[top--];
}
char peek() {
	return stack[top];
}
int isEmpty() {
	return top == -1;
}

// precedence function
int precedence(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	return 0;
}

// convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
	int k = 0;
	for (int i = 0; infix[i] != '\0'; i++) {
		char c = infix[i];
		if (isalnum(c)) {
			postfix[k++] = c;   // operand
		}
		else if (c == '(') {
			push(c);
		}
		else if (c == ')') {
			while (!isEmpty() && peek() != '(') {
				postfix[k++] = pop();
			}
			pop(); // remove '('
		}
		else { // operator
			while (!isEmpty() && precedence(peek()) >= precedence(c)) {
				postfix[k++] = pop();
			}
			push(c);
		}
	}
	while (!isEmpty()) {
		postfix[k++] = pop();
	}
	postfix[k] = '\0';
}

// evaluate postfix
int evalPostfix(char postfix[]) {
	int s[MAX], t = -1;
	for (int i = 0; postfix[i] != '\0'; i++) {
		char c = postfix[i];
		if (isdigit(c)) {
			s[++t] = c - '0';  // push number
		}
		else { // operator
			int b = s[t--];
			int a = s[t--];
			switch (c) {
				case '+': s[++t] = a + b; break;
				case '-': s[++t] = a - b; break;
				case '*': s[++t] = a * b; break;
				case '/': s[++t] = a / b; break;
			}
		}
	}
	return s[t];
}

int main() {
	char infix[MAX], postfix[MAX];
	
	printf("Enter infix expression: ");
	scanf("%s", infix);
	
	infixToPostfix(infix, postfix);
	printf("Postfix: %s\n", postfix);
	
	int result = evalPostfix(postfix);
	printf("Result: %d\n", result);
	
	return 0;
}