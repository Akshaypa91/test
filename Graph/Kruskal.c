#include <stdio.h>
#include <stdlib.h>

#define MAXE 1000
#define MAXV 100

typedef struct {
	int u, v;
	int w;
} Edge;

Edge edges[MAXE];
int parent[MAXV + 1];
int rankArr[MAXV + 1];
int n, m; // n = vertices, m = edges

// Disjoint Set (Union-Find)
void make_set(int x) {
	parent[x] = x;
	rankArr[x] = 0;
}

int find_set(int x) {
	if(parent[x] != x)
		parent[x] = find_set(parent[x]); // path compression
	return parent[x];
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if(a == b) return;
	if(rankArr[a] < rankArr[b]) {
		parent[a] = b;
	} else if(rankArr[b] < rankArr[a]) {
		parent[b] = a;
	} else {
		parent[b] = a;
		rankArr[a]++;
	}
}

// comparator for qsort: increasing weight
int cmpEdge(const void *p1, const void *p2) {
	Edge *a = (Edge*)p1;
	Edge *b = (Edge*)p2;
	return a->w - b->w;
}

void kruskal() {
	// initialize disjoint sets
	for(int i = 1; i <= n; i++)
		make_set(i);

	// sort edges by weight
	qsort(edges, m, sizeof(Edge), cmpEdge);

	int count = 0;
	int mst_weight = 0;

	printf("Edges in MST (u v w):\n");
	for(int i = 0; i < m && count < n - 1; i++) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;

		if(find_set(u) != find_set(v)) {
			union_set(u, v);
			printf("%d %d %d\n", u, v, w);
			mst_weight += w;
			count++;
		}
	}

	if(count != n - 1) {
		printf("MST not possible (graph is disconnected).\n");
	} else {
		printf("Total weight of MST = %d\n", mst_weight);
	}
}

int main() {
	printf("Enter number of vertices: ");
	if(scanf("%d", &n) != 1) return 0;

	printf("Enter number of edges: ");
	if(scanf("%d", &m) != 1) return 0;
	if(m > MAXE) {
		printf("Too many edges (max %d).\n", MAXE);
		return 0;
	}

	printf("Enter edges (u v w) one per line:\n");
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	}

	printf("\nKruskal's MST:\n");
	kruskal();

	return 0;
}