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
	struct NodeStack* newStackNode = (struct NodeStack*)malloc(sizeof(struct NodeStack));
	if (!newStackNode) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	newStackNode->treeNode = node;
	newStackNode->next = *top;
	*top = newStackNode;
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
	if (!node) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	node->data = val;
	node->left = node->right = NULL;
	return node;
}

// Non-recursive inorder traversal
void inorderNonRec(struct Node* root) {
	struct NodeStack* stack = NULL;
	struct Node* temp = root;
	while (temp != NULL || !isEmpty(stack)) {
		while (temp != NULL) {
			pushNode(&stack, temp);
			temp = temp->left;
		}
		temp = popNode(&stack);
		printf("%d ", temp->data);
		temp = temp->right;
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

	printf("Inorder traversal: ");
	inorderNonRec(root);  // Output: 4 2 5 1 3
	printf("\n");

	return 0;
}