#include <stdio.h>

#define MAX 20

int visited[MAX];
int adj[MAX][MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

// enqueue
void add(int v) {
	queue[++rear] = v;
}

// dequeue
int removeQ() {
	return queue[front++];
}

// check empty
int isEmpty() {
	return front > rear;
}

// Recursive BFS function
void BreadthFirstSearch() {
	if(isEmpty())
		return;   // base case

	int i = removeQ();
	printf("%d ", i);

	for(int j = 1; j <= n; j++) {
		if(adj[i][j] == 1 && visited[j] == 0) {
			visited[j] = 1;
			add(j);
		}
	}

	BreadthFirstSearch();  // recursive call
}

// Traversal function (similar to DFS version)
void traverse() {
	// Start BFS from vertex 1
	visited[1] = 1;
	add(1);

	BreadthFirstSearch();

	// handle disconnected graph
	for(int k = 1; k <= n; k++) {
		if(visited[k] == 0) {
			visited[k] = 1;
			add(k);
			BreadthFirstSearch();
		}
	}
}

int main() {
	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &adj[i][j]);

	// mark all vertices unvisited
	for(int i = 1; i <= n; i++)
		visited[i] = 0;

	printf("BFS Traversal: ");
	traverse();

	return 0;
}