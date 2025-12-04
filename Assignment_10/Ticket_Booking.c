#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 50
#define MAX_NAME_LENGTH 50

struct Queue {
    char customers[MAX_QUEUE_SIZE][MAX_NAME_LENGTH];
    int front;
    int rear;
};

void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// 1. Add Customer (Enqueue)
void addCustomer(struct Queue *q, char name[]) {
    if (isFull(q)) {
        printf("Sorry, the queue is full. Cannot add more customers.\n");
        return;
    }
    
    // If it's the first customer, set the front pointer
    if (isEmpty(q)) {
        q->front = 0;
    }
    
    // Increment rear and add the new customer
    q->rear++;
    strcpy(q->customers[q->rear], name);
    printf("Customer %s has joined the queue.\n", name);
}

// 2. Process Booking (Dequeue)
void processBooking(struct Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty. No customers to process.\n");
        return;
    }

    printf("Booking processed for customer: %s\n", q->customers[q->front]);

    // If this was the last customer in the queue, reset it
    if (q->front == q->rear) {
        initializeQueue(q);
    } else {
        // Move the front pointer to the next customer
        q->front++;
    }
}

// 3. View Queue (Display)
void viewQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is currently empty.\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s", q->customers[i]);
        if (i < q->rear) {
            printf(" -> ");
        }
    }
    printf("\n");
}

// Helper function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Queue ticketQueue;
    initializeQueue(&ticketQueue);
    int choice;
    char customerName[MAX_NAME_LENGTH];

    printf("--- Welcome to ABC Ticket Booking System ---\n");

    while (1) {
        printf("\n");
        printf("1. Add Customer\n");
        printf("2. Process Booking\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        printf("Enter Your Choice (1 - 4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer(); // Clear the buffer on invalid input
            continue;
        }
        clearInputBuffer(); // Clear the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter Customer Name: ");
                // Use fgets to safely read names with spaces
                fgets(customerName, MAX_NAME_LENGTH, stdin);
                // Remove the newline character that fgets reads
                customerName[strcspn(customerName, "\n")] = 0;
                addCustomer(&ticketQueue, customerName);
                break;

            case 2:
                processBooking(&ticketQueue);
                break;

            case 3:
                viewQueue(&ticketQueue);
                break;

            case 4:
                printf("Thank you for using the system. Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }
    return 0;
}