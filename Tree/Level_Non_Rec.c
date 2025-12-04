#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

// Queue node (linked list)
struct QueueNode {
	struct Node* treeNode;
	struct QueueNode* next;
};

// Queue with front & rear pointers
struct Queue {
	struct QueueNode *front, *rear;
};

// Create queue
struct Queue* createQueue() {
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
	struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	temp->treeNode = node;
	temp->next = NULL;

	if (q->rear == NULL) { // empty
		q->front = q->rear = temp;
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
	if (q->front == NULL)
		return NULL;

	struct QueueNode* temp = q->front;
	struct Node* node = temp->treeNode;

	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
	return node;
}

// Check if queue empty
int isQueueEmpty(struct Queue* q) {
	return q->front == NULL;
}

// Create new tree node
struct Node* newNode(int val) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = val;
	node->left = node->right = NULL;
	return node;
}

// Level order traversal (BFS)
void levelOrder(struct Node* root) {
	if (root == NULL) return;

	struct Queue* q = createQueue();
	enqueue(q, root);

	while (!isQueueEmpty(q)) {
		struct Node* node = dequeue(q);
		printf("%d ", node->data);

		if (node->left)
			enqueue(q, node->left);

		if (node->right)
			enqueue(q, node->right);
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

	printf("Level Order Traversal: ");
	levelOrder(root);   // Output: 1 2 3 4 5
	printf("\n");

	return 0;
}