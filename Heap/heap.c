#include <stdio.h>

#define MAX_HEAP_CAPACITY 100   /* maximum number of elements the heap can hold */

/* element stored in heap; .key is used for comparison (priority) */
typedef struct {
	int key;
	/* you can add more fields here, e.g. payload, id, etc. */
} element;

/* 1-indexed heap: valid indices are 1..MAX_HEAP_CAPACITY
   we keep index 0 unused to simplify parent/child math */
element heap[MAX_HEAP_CAPACITY + 1];

/* helper macro to check full (n is current size) */
#define HEAP_FULL(n) ((n) >= MAX_HEAP_CAPACITY)

/* insert into a 1-indexed max-heap
   item : element to insert (passed by value)
   n    : pointer to current heap size (will be incremented)
   returns 0 on success, -1 if heap is full */
int insert_max_heap_1indexed(element item, int *n)
{
	if (HEAP_FULL(*n)) {
		/* heap full */
		return -1;
	}

	/* increment heap size and get insertion index */
	int i = ++(*n);

	/* bubble-up: while not at root and parent's key is smaller than item.key */
	while (i > 1 && item.key > heap[i/2].key) {
		heap[i] = heap[i/2];   /* move parent down */
		i /= 2;                /* move index up to parent */
	}

	heap[i] = item;           /* place item at final position */
	return 0;
}

/* utility to print heap keys from 1..n */
void print_heap_keys(int n)
{
	if (n == 0) {
		printf("(heap is empty)\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", heap[i].key);
	}
	printf("\n");
}

int main(void)
{
	int n = 0; /* current size of heap (initially empty) */

	/* demo elements */
	element e1 = {40};
	element e2 = {30};
	element e3 = {50};
	element e4 = {45};
	element e5 = {60};

	/* insert elements and check for errors */
	if (insert_max_heap_1indexed(e1, &n) != 0) {
		printf("Insert failed: heap full\n");
	}
	if (insert_max_heap_1indexed(e2, &n) != 0) {
		printf("Insert failed: heap full\n");
	}
	if (insert_max_heap_1indexed(e3, &n) != 0) {
		printf("Insert failed: heap full\n");
	}
	if (insert_max_heap_1indexed(e4, &n) != 0) {
		printf("Insert failed: heap full\n");
	}
	if (insert_max_heap_1indexed(e5, &n) != 0) {
		printf("Insert failed: heap full\n");
	}

	printf("Heap keys (level order, indices 1..%d):\n", n);
	print_heap_keys(n);

	/* expected max-heap root = 60, then next level with 50, etc. */
	return 0;
}
