//Linked using Array
#include <stdio.h>

#define SIZE 100 

int data[SIZE];   
int next[SIZE];   
int head = -1;
int free_index = 0; 

int get_newnode(int value) {
    if (free_index >= SIZE) {
        printf("List w!\n");
        return -1;
    }
    int idx = free_index++;
    data[idx] = value;
    next[idx] = -1;
    return idx;
}

void insert_beginning(int value) {
    int newnode = get_newnode(value);
    if (newnode == -1) return;

    next[newnode] = head;
    head = newnode;
}

void insert_after(int position, int value) {
    if (head == -1) return;

    int temp = head;
    for (int i = 1; i < position && temp != -1; i++) {
        temp = next[temp];
    }
    if (temp == -1) {
        printf("Position out of range\n");
        return;
    }

    int newnode = get_newnode(value);
    if (newnode == -1) return;

    next[newnode] = next[temp];
    next[temp] = newnode;
}

void delete_beginning() {
    if (head == -1) return;
    head = next[head];
}

void delete_after(int position) {
	if (head == -1) return;

	int temp = head;
	for (int i = 1; i < position && temp != -1; i++) {
		temp = next[temp];
	}
	if (temp == -1 || next[temp] == -1) {
		printf("Position out of range\n");
		return;
	}

	int del = next[temp];
	next[temp] = next[del];
}

void print_list() {
    int temp = head;
    while (temp != -1) {
        printf("%d ", data[temp]);
        temp = next[temp];
    }
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data: ");
        scanf("%d", &val);

        int newnode = get_newnode(val);
        if (head == -1) {
            head = newnode;
        } else {
            int t = head;
            while (next[t] != -1) t = next[t];
            next[t] = newnode;
        }
    }

    printf("Original list: ");
    print_list();

    insert_beginning(6);
    printf("List after inserting 6 at beginning: ");
    print_list();

    insert_after(3, 7);
    printf("List after inserting 7 after 3rd node: ");
    print_list();

    delete_beginning();
    printf("List after deleting element at beginning: ");
    print_list();

    delete_after(4);
    printf("List after deleting element after 4th node: ");
    print_list();

    return 0;
}