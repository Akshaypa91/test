#include <stdio.h>

#define MAX 20

int adj[MAX][MAX] = {
	// index: 0 1 2 3 4 5  (0th row unused)
	{0,0,0,0,0,0},       // row 0 unused
	{0,0,1,1,0,0},       // vertex 1: edges to 2,3
	{0,1,0,0,1,0},       // vertex 2: edges to 1,4
	{0,1,0,0,1,1},       // vertex 3: edges to 1,4,5
	{0,0,1,1,0,0},       // vertex 4: edges to 2,3
	{0,0,0,1,0,0}        // vertex 5: edge to 3
};

int visited[MAX] = {0};
int queue[MAX];
int front = 0, rear = -1;

int n = 5;      // manually set
int start = 1;  // BFS starts from vertex 1

void enqueue(int v) {
	queue[++rear] = v;
}

int dequeue() {
	return queue[front++];
}

int isEmpty() {
	return front > rear;
}

//Using Queue
void BFS(int start) {
	visited[start] = 1;
	enqueue(start);

	while(!isEmpty()) {
		int i = dequeue();
		printf("%d ", i);

		for(int j = 1; j <= n; j++) {
			if(adj[i][j] == 1 && visited[j] == 0) {
				visited[j] = 1;
				enqueue(j);
			}
		}
	}
}

int main() {

	printf("BFS Traversal: ");
	BFS(start);

	return 0;
}
