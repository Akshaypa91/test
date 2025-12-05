#include <stdio.h>
#include <stdlib.h>
struct queue {
	int size;
	int f;
	int r;
	int *arr;
};
typedef struct queue queue;

int isEmpty(queue *q) {
	if (q->r == q->f) {
		return 1;
	} else {
		return 0;
	}  
}


int isFull(queue *q) {
	if (q->r == q->size - 1) {
		return 1;
	} else {
		return 0;
	}
}
void enqueue(queue *q, int data) {
	if (isFull(q)) {
		printf("Queue is full\n");
		return;
	} else {
		q->r++;
		q->arr[q->r] = data;
	}
}
int dequeue(queue *q) {
	if (isEmpty(q)) {
		printf("Queue is Empty\n");
	} else {
		int t = q->arr[q->r];
		q->r--;
		return t;
	}
    return 0;
}
int main() {
	queue q;
	q.size = 400;
	q.f = 0;
	q.r = 0;
	q.arr = (int *) malloc (q.size * sizeof(int));
	
	//BFS algo
	int node;
	int root = 1;
	int visited[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int a[8][8] = {
		{0,1,0,1,0,0,0,0},
		{1,0,1,1,1,0,0,0},
		{1,0,0,0,1,0,0,0},
		{1,1,0,0,0,1,1,0},
		{0,1,1,0,0,0,1,1},
		{0,0,0,1,0,0,1,0},
		{0,0,0,1,1,1,0,1},
		{0,0,0,0,1,0,1,0}
	};
	printf("%d ", root);
	visited[root] = 1;
	enqueue(&q, root);
	while (!isEmpty(&q)) {
		node = dequeue(&q);
		for (int j = 0; j < 8; j++) {
			if (a[node][j] == 1 && visited[j] == 0) {
				printf("%d ", j);
				visited[j] = 1;
				enqueue(&q, j);
			}
		}
	}
	printf("\n");
	return 0;
}


