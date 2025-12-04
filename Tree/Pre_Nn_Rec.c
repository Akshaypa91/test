#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

// Stack structure for non-recursive traversal
struct NodeStack {
	struct Node* treeNode;
	struct NodeStack* next;
};

// Push operation
void pushNode(struct NodeStack** top, struct Node* node) {
	struct NodeStack* newNode = (struct NodeStack*)malloc(sizeof(struct NodeStack));
	newNode->treeNode = node;
	newNode->next = *top;
	*top = newNode;
}

// Check empty
int isEmpty(struct NodeStack* top) {
	return top == NULL;
}

// Pop operation
struct Node* popNode(struct NodeStack** top) {
	if (*top == NULL) return NULL;
	struct NodeStack* temp = *top;
	*top = (*top)->next;
	struct Node* node = temp->treeNode;
	free(temp);
	return node;
}

// Create new tree node
struct Node* newNode(int val) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = val;
	node->left = node->right = NULL;
	return node;
}

// Non-recursive preorder traversal
void preorderNonRec(struct Node* root) {
	if (!root) return;
	struct NodeStack* stack = NULL;
	pushNode(&stack, root);

	while (!isEmpty(stack)) {
		struct Node* node = popNode(&stack);
		printf("%d ", node->data);

		if (node->right) pushNode(&stack, node->right);
		if (node->left) pushNode(&stack, node->left);
	}
}

int main() {
	/*
	        1
	       / \
	      2   3
	     / \
	    4   5
	*/

	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Preorder traversal: ");
	preorderNonRec(root);  
	// Output: 1 2 4 5 3

	return 0;
}