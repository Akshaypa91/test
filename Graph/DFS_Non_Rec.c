#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// Push operation
void push(int v) {
	stack[++top] = v;
}

// Pop operation
int pop() {
	return stack[top--];
}

int isEmpty() {
	return (top == -1);
}

void DFS_Stack(int start) {
	// Mark start vertex visited and push it
	visited[start] = 1;
	push(start);

	printf("DFS Traversal: ");

	while(!isEmpty()) {
		int v = pop();
		printf("%d ", v);

		// Visit all adjacent unvisited vertices
		for(int j = 1; j <= n; j++) {
			if(adj[v][j] == 1 && visited[j] == 0) {
				visited[j] = 1;
				push(j);
			}
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

	// Initialize visited array
	for(int i = 1; i <= n; i++)
		visited[i] = 0;

	int start = 1;

	DFS_Stack(start);

	return 0;
}