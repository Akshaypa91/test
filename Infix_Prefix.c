#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// stack operations
void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

// precedence of operators
int precedence(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	return 0;
}

// function to reverse a string
void reverse(char exp[]) {
	int n = strlen(exp);
	for (int i = 0; i < n / 2; i++) {
		char temp = exp[i];
		exp[i] = exp[n - i - 1];
		exp[n - i - 1] = temp;
	}
}

// function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
	char temp[MAX], revInfix[MAX];
	int k = 0;

	strcpy(revInfix, infix);
	reverse(revInfix);

	// swap '(' with ')' while reversing
	for (int i = 0; revInfix[i] != '\0'; i++) {
		if (revInfix[i] == '(') revInfix[i] = ')';
		else if (revInfix[i] == ')') revInfix[i] = '(';
	}

	// now do infix to postfix on reversed expression
	for (int i = 0; revInfix[i] != '\0'; i++) {
		char c = revInfix[i];
		if (isalnum(c)) {
			temp[k++] = c;
		}
		else if (c == '(') {
			push(c);
		}
		else if (c == ')') {
			while (!isEmpty() && peek() != '(') {
				temp[k++] = pop();
			}
			pop();
		}
		else { // operator
			while (!isEmpty() && precedence(peek()) > precedence(c)) {
				temp[k++] = pop();
			}
			push(c);
		}
	}
	while (!isEmpty()) {
		temp[k++] = pop();
	}
	temp[k] = '\0';

	// reverse the postfix result to get prefix
	strcpy(prefix, temp);
	reverse(prefix);
}

// evaluate prefix expression
int evalPrefix(char prefix[]) {
	int s[MAX], t = -1;
	int n = strlen(prefix);

	for (int i = n - 1; i >= 0; i--) {
		char c = prefix[i];
		if (isdigit(c)) {
			s[++t] = c - '0';
		} else {
			int a = s[t--];
			int b = s[t--];
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
	char infix[MAX], prefix[MAX];

	printf("Enter infix expression: ");
	scanf("%s", infix);

	infixToPrefix(infix, prefix);
	printf("Prefix: %s\n", prefix);

	int result = evalPrefix(prefix);
	printf("Result: %d\n", result);

	return 0;
}