#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// Insert in BST
Node* insert(Node* root, int data) {
	if (root == NULL) return newNode(data);
	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	return root;
}

// Find minimum node in BST (used in delete)
Node* minValueNode(Node* node) {
	Node* temp = node;
	while (temp && temp->left != NULL)
		temp = temp->left;
	return temp;
}

// Delete a node
Node* deleteNode(Node* root, int key) {
	if (!root) return root;
	if (key < root->data)
		root->left = deleteNode(root->left, key);
	else if (key > root->data)
		root->right = deleteNode(root->right, key);
	else {
		// Node with only one child or no child
		if (!root->left) {
			Node* temp = root->right;
			free(root);
			return temp;
		} else if (!root->right) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		// Node with two children
		Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

// Search in BST
Node* search(Node* root, int key) {
	if (!root || root->data == key) return root;
	if (key < root->data) return search(root->left, key);
	return search(root->right, key);
}

//Traversals
void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(Node* root) {
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

//Depth of Tree
int depth(Node* root) {
	if (!root) return 0;
	int lDepth = depth(root->left);
	int rDepth = depth(root->right);
	return (lDepth > rDepth ? lDepth : rDepth) + 1;
}

//Display Parent-Child
void displayParents(Node* root) {
	if (!root) return;
	if (root->left || root->right) {
		printf("Parent: %d, ", root->data);
		if (root->left) printf("Left Child: %d, ", root->left->data);
		if (root->right) printf("Right Child: %d", root->right->data);
		printf("\n");
	}
	displayParents(root->left);
	displayParents(root->right);
}

//Display Leaf Nodes
void displayLeaves(Node* root) {
	if (!root) return;
	if (!root->left && !root->right) {
		printf("%d ", root->data);
	}
	displayLeaves(root->left);
	displayLeaves(root->right);
}

//Level-wise Display
typedef struct QueueNode {
	Node* node;
	struct QueueNode* next;
} QueueNode;

typedef struct Queue {
	QueueNode* front;
	QueueNode* rear;
} Queue;

Queue* createQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = q->rear = NULL;
	return q;
}

void enqueue(Queue* q, Node* node) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->node = node;
	temp->next = NULL;
	if (!q->rear) {
		q->front = q->rear = temp;
	} else {
		q->rear->next = temp;
		q->rear = temp;
	}
}

Node* dequeue(Queue* q) {
	if (!q->front) return NULL;
	QueueNode* temp = q->front;
	Node* node = temp->node;
	q->front = q->front->next;
	if (!q->front) q->rear = NULL;
	free(temp);
	return node;
}

int isQueueEmpty(Queue* q) {
	return q->front == NULL;
}

void levelOrder(Node* root) {
	if (!root) return;
	Queue* q = createQueue();
	enqueue(q, root);
	while (!isQueueEmpty(q)) {
		Node* node = dequeue(q);
		printf("%d ", node->data);
		if (node->left) enqueue(q, node->left);
		if (node->right) enqueue(q, node->right);
	}
	free(q);
}

int main() {
	Node* root = NULL;
	int choice, val;
	while (1) {
		printf("\n--- BST Menu ---\n");
		printf("1. Insert\n2. Delete\n3. Search\n4. Display Traversals\n");
		printf("5. Depth of Tree\n6. Display Parent Nodes\n7. Display Leaf Nodes\n8. Level-wise Display\n9. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter value to insert: ");
				scanf("%d", &val);
				root = insert(root, val);
				break;
			case 2:
				printf("Enter value to delete: ");
				scanf("%d", &val);
				root = deleteNode(root, val);
				break;
			case 3:
				printf("Enter value to search: ");
				scanf("%d", &val);
				if (search(root, val))
					printf("%d found in BST.\n", val);
				else
					printf("%d not found.\n", val);
				break;
			case 4:
				printf("Inorder: "); inorder(root); printf("\n");
				printf("Preorder: "); preorder(root); printf("\n");
				printf("Postorder: "); postorder(root); printf("\n");
				break;
			case 5:
				printf("Depth of tree: %d\n", depth(root));
				break;
			case 6:
				printf("Parent Nodes with children:\n");
				displayParents(root);
				break;
			case 7:
				printf("Leaf Nodes: ");
				displayLeaves(root);
				printf("\n");
				break;
			case 8:
				printf("Level-wise Display: ");
				levelOrder(root);
				printf("\n");
				break;
			case 9:
				exit(0);
			default:
				printf("Invalid choice!\n");
		}
	}
	return 0;
}