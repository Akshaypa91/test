#include <stdio.h>

#define MAX 20

int adj[MAX][MAX] = {
	// 0th row unused (1-based indexing)
	{0,0,0,0,0,0},
	{0,0,1,1,0,0},   // vertex 1 → 2,3
	{0,1,0,0,1,0},   // vertex 2 → 1,4
	{0,1,0,0,1,1},   // vertex 3 → 1,4,5
	{0,0,1,1,0,0},   // vertex 4 → 2,3
	{0,0,0,1,0,0}    // vertex 5 → 3
};

int visited[MAX] = {0};
int stack[MAX];
int top = -1;

int n = 5;      // number of vertices (manual input)
int start = 1;  // DFS starts from vertex 1 (manual)

void push(int v) {
	stack[++top] = v;
}

int pop() {
	return stack[top--];
}

int isEmpty() {
	return (top == -1);
}

//Using Stack
void DFS_Stack(int start) {
	visited[start] = 1;
	push(start);

	printf("DFS Traversal: ");

	while(!isEmpty()) {
		int v = pop();
		printf("%d ", v);

		for(int j = 1; j <= n; j++) {
			if(adj[v][j] == 1 && visited[j] == 0) {
				visited[j] = 1;
				push(j);
			}
		}
	}
}

int main() {
	DFS_Stack(start);
	return 0;
}
