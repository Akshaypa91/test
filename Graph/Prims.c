#include <stdio.h>

#define MAX 100
#define INF 1000000000

int adj[MAX][MAX];
int parent[MAX];
int key[MAX];
int inMST[MAX];
int n;

int minKeyVertex() {
	int min = INF;
	int minIndex = -1;
	for (int v = 1; v <= n; v++) {
		if (!inMST[v] && key[v] < min) {
			min = key[v];
			minIndex = v;
		}
	}
	return minIndex;
}

void prim() {
	// initialize
	for (int i = 1; i <= n; i++) {
		key[i] = INF;
		parent[i] = -1;
		inMST[i] = 0;
	}

	// start from vertex 1
	key[1] = 0;

	for (int count = 0; count < n; count++) {
		int u = minKeyVertex();
		// if no reachable vertex found => disconnected component
		if (u == -1) break;

		inMST[u] = 1;

		// update keys of adjacent vertices
		for (int v = 1; v <= n; v++) {
			if (!inMST[v] && adj[u][v] != 0 && adj[u][v] < key[v]) {
				key[v] = adj[u][v];
				parent[v] = u;
			}
		}
	}

	// check if spanning tree exists and print MST
	int totalWeight = 0;
	int edgesCount = 0;
	for (int v = 2; v <= n; v++) {
		if (parent[v] == -1) {
			// vertex v (other than root) has no parent -> disconnected
			printf("No spanning tree\n");
			return;
		}
		edgesCount++;
		totalWeight += adj[v][parent[v]];
	}

	printf("Edges in MST (u v w):\n");
	for (int v = 2; v <= n; v++) {
		printf("%d %d %d\n", parent[v], v, adj[v][parent[v]]);
	}
	printf("Total weight = %d\n", totalWeight);
}

int main() {
	printf("Enter number of vertices: ");
	if (scanf("%d", &n) != 1) return 0;

	printf("Enter adjacency matrix (%d x %d). Use 0 for no edge:\n", n, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &adj[i][j]);
		}
	}

	prim();
	return 0;
}