#include <stdio.h>

#define MAX 100
#define INF 1000000000

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];
int n;

int minDistanceVertex() {
	int min = INF;
	int minIndex = -1;
	for (int v = 1; v <= n; v++) {
		if (!visited[v] && dist[v] < min) {
			min = dist[v];
			minIndex = v;
		}
	}
	return minIndex;
}

void printPath(int dest) {
	if (parent[dest] == -1) {
		printf("%d", dest);
		return;
	}
	printPath(parent[dest]);
	printf(" -> %d", dest);
}

void dijkstra(int src) {
	// initialize
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		visited[i] = 0;
		parent[i] = -1;
	}

	dist[src] = 0;

	for (int count = 0; count < n; count++) {
		int u = minDistanceVertex();
		if (u == -1) break; // remaining vertices not reachable
		visited[u] = 1;

		for (int v = 1; v <= n; v++) {
			if (!visited[v] && adj[u][v] != 0) {
				int alt = dist[u] + adj[u][v];
				if (alt < dist[v]) {
					dist[v] = alt;
					parent[v] = u;
				}
			}
		}
	}

	// print results
	printf("Vertex\tDistance\tPath\n");
	for (int v = 1; v <= n; v++) {
		if (dist[v] == INF) {
			printf("%d\tUnreachable\t-\n", v);
		} else {
			printf("%d\t%d\t\t", v, dist[v]);
			printPath(v);
			printf("\n");
		}
	}
}

int main() {
	int src;

	printf("Enter number of vertices: ");
	if (scanf("%d", &n) != 1) return 0;

	printf("Enter adjacency matrix (%d x %d). Use 0 for no edge:\n", n, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &adj[i][j]);
		}
	}

	printf("Enter source vertex: ");
	if (scanf("%d", &src) != 1) return 0;
	if (src < 1 || src > n) {
		printf("Invalid source vertex\n");
		return 0;
	}

	dijkstra(src);
	return 0;
}