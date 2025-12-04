#include <stdio.h>

#define MAX 20

int visited[MAX];
int adj[MAX][MAX];
int n;   // number of vertices

void DepthFirstSearch(int i) {
	visited[i] = 1;
	printf("%d ", i);

	for(int j = 1; j <= n; j++) {
		if(adj[i][j] == 1 && visited[j] == 0) {
			DepthFirstSearch(j);
		}
	}
}

// Traversal function (handles disconnected graph also)
void traverse() {
	// Start DFS from vertex 1 (as per algorithm)
	DepthFirstSearch(1);

	// If graph has disconnected components
	for(int k = 1; k <= n; k++) {
		if(visited[k] == 0)
			DepthFirstSearch(k);
	}
}

int main() {
	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &adj[i][j]);

	// Mark all vertices as unvisited
	for(int v = 1; v <= n; v++)
		visited[v] = 0;

	printf("DFS Traversal: ");
	traverse();

	return 0;
}