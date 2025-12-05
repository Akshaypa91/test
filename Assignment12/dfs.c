#include <stdio.h>
#include <stdlib.h>
struct stack {
	int size;
	int top;
	int *arr;
};
typedef struct stack stack;
int isFull(stack *s) {
	if (s->top == s->size - 1) {
		return 1;
	} else {
		return 0;
	}
}
int isEmpty(stack *s) {
	if (s->top == -1) {
		return 1;
	} else {
		return 0;
	}
}
void push(stack *s, int data) {
	if (isFull(s)) {
		printf("Stack is Full\n");
	} else {
		s->top++;
		s->arr[s->top] = data;
	}
}
int pop(stack *s) {
	if (isEmpty(s)) {
		printf("Stack is Empty\n");
	} else {
		int temp = s->arr[s->top];
		s->top--;
		return temp;
	}
    return 0;
}
int main() {
	stack s;
	s.top = -1;
	s.size = 400;
	s.arr = (int *) malloc (s.size * sizeof(int));
	int node;
	int root = 0;
	int visited[7] = {0,0,0,0,0,0,0};
	int a[7][7] = {
		{0,1,1,1,0,0,0},
		{1,0,0,1,1,0,0},
		{1,0,0,1,0,1,0},
		{1,1,1,0,1,1,1},
		{0,1,0,1,0,0,1},
		{0,0,1,1,0,0,1},
		{0,0,0,1,1,1,0}
	};
	push(&s, root);
	while (!isEmpty(&s)) {
		node = pop(&s); 
		if (visited[node] == 0) {
			visited[node] = 1;
			printf("%d ", node);
		} 
		for (int j = 0; j < 7; j++)
			if (a[node][j] == 1 && visited[j] == 0)
				push(&s, j);
		}
	printf("\n");
	return 0;
}