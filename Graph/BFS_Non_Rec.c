#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

// enqueue
void enqueue(int v) {
	rear++;
	queue[rear] = v;
}

// dequeue
int dequeue() {
	int v = queue[front];
	front++;
	return v;
}

int isEmpty() {
	return front > rear;
}

void BFS(int start) {
	// mark start visited and enqueue
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

// traversal that ensures full graph is covered (disconnected graphs too)
void bfs_traverse() {
	// reset queue pointers for safety
	front = 0;
	rear  = -1;

	// start BFS from vertex 1 (as algorithm suggests)
	BFS(1);

	// if some vertices are still unvisited, run BFS from them
	for(int v = 1; v <= n; v++) {
		if(visited[v] == 0) {
			BFS(v);
		}
	}
}

int main() {
	printf("Enter number of vertices: ");
	if(scanf("%d", &n) != 1) return 0;

	printf("Enter adjacency matrix (%d x %d):\n", n, n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &adj[i][j]);

	// mark all vertices unvisited
	for(int i = 1; i <= n; i++)
		visited[i] = 0;

	printf("BFS Traversal: ");
	bfs_traverse();
	printf("\n");

	return 0;
}