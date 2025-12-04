// Non-Recursive Traversals
#include <stdio.h>
#include <stdlib.h>

// Node for binary tree
struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};

// Stack for non-recursive traversal
struct NodeStack {
	struct Node* node;
	struct NodeStack* next;
};

// Utility: create new node
struct Node* newNode(char data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Stack operations
void pushNode(struct NodeStack** top, struct Node* node) {
	struct NodeStack* temp = (struct NodeStack*)malloc(sizeof(struct NodeStack));
	temp->node = node;
	temp->next = *top;
	*top = temp;
}

struct Node* popNode(struct NodeStack** top) {
	if (!*top) return NULL;
	struct NodeStack* temp = *top;
	struct Node* node = temp->node;
	*top = (*top)->next;
	free(temp);
	return node;
}

int isEmpty(struct NodeStack* top) {
	return top == NULL;
}

// Non-recursive inorder traversal
void inorderNonRec(struct Node* root) {
	struct NodeStack* stack = NULL;
	struct Node* curr = root;
	while (curr != NULL || !isEmpty(stack)) {
		while (curr != NULL) {
			pushNode(&stack, curr);
			curr = curr->left;
		}
		curr = popNode(&stack);
		printf("%c ", curr->data);
		curr = curr->right;
	}
}

// Non-recursive preorder traversal
void preorderNonRec(struct Node* root) {
	if (!root) return;
	struct NodeStack* stack = NULL;
	pushNode(&stack, root);
	while (!isEmpty(stack)) {
		struct Node* node = popNode(&stack);
		printf("%c ", node->data);
		if (node->right) pushNode(&stack, node->right);
		if (node->left) pushNode(&stack, node->left);
	}
}

// Non-recursive postorder traversal
void postorderNonRec(struct Node* root) {
	if (!root) return;
	struct NodeStack* stack1 = NULL;
	struct NodeStack* stack2 = NULL;
	pushNode(&stack1, root);
	while (!isEmpty(stack1)) {
		struct Node* node = popNode(&stack1);
		pushNode(&stack2, node);
		if (node->left) pushNode(&stack1, node->left);
		if (node->right) pushNode(&stack1, node->right);
	}
	while (!isEmpty(stack2)) {
		struct Node* node = popNode(&stack2);
		printf("%c ", node->data);
	}
}

// Example main
int main() {
	/*
			A
		   / \
		  B   C
		 / \   \
		D   E   F
	*/
	struct Node* root = newNode('A');
	root->left = newNode('B');
	root->right = newNode('C');
	root->left->left = newNode('D');
	root->left->right = newNode('E');
	root->right->right = newNode('F');

	printf("Non-Recursive Traversals:\n");
	printf("Inorder: "); inorderNonRec(root); printf("\n");
	printf("Preorder: "); preorderNonRec(root); printf("\n");
	printf("Postorder: "); postorderNonRec(root); printf("\n");

	return 0;
}