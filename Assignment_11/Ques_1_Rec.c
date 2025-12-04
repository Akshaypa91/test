#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;
} Node;

// Stack for nodes
typedef struct Stack {
	Node* node;
	struct Stack* next;
} Stack;

// Function to create a new tree node
Node* newNode(char data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Push node onto stack
void push(Stack** top, Node* node) {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->node = node;
	temp->next = *top;
	*top = temp;
}

// Pop node from stack
Node* pop(Stack** top) {
	if (*top == NULL) return NULL;
	Stack* temp = *top;
	Node* node = temp->node;
	*top = (*top)->next;
	free(temp);
	return node;
}

// Check if character is operator
int isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Construct expression tree from postfix
Node* constructTree(char* postfix) {
	Stack* stack = NULL;
	int i;
	for (i = 0; postfix[i] != '\0'; i++) {
		char c = postfix[i];
		if (isspace(c)) continue; // skip spaces
		Node* node = newNode(c);
		if (isOperator(c)) {
			node->right = pop(&stack);
			node->left = pop(&stack);
		}
		push(&stack, node);
	}
	return pop(&stack);
}

// Recursive Traversals
void inorderRec(Node* root) {
	if (root) {
		inorderRec(root->left);
		printf("%c ", root->data);
		inorderRec(root->right);
	}
}

void preorderRec(Node* root) {
	if (root) {
		printf("%c ", root->data);
		preorderRec(root->left);
		preorderRec(root->right);
	}
}

void postorderRec(Node* root) {
	if (root) {
		postorderRec(root->left);
		postorderRec(root->right);
		printf("%c ", root->data);
	}
}

int main() {
	char postfix[100];
	printf("Enter postfix expression: ");
	scanf("%[^\n]", postfix);

	Node* root = constructTree(postfix);

	printf("\nRecursive Traversals:\n");
	printf("Inorder: "); inorderRec(root); printf("\n");
	printf("Preorder: "); preorderRec(root); printf("\n");
	printf("Postorder: "); postorderRec(root); printf("\n");

	return 0;
}