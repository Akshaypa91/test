//Polynomial
#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff;              // coefficient
    int pow;                // power
    struct PolyNode* next;
};

// Create a new polynomial node
struct PolyNode* createNode(int coeff, int pow) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert term at end (for building polynomial)
struct PolyNode* insertEnd(struct PolyNode* head, int coeff, int pow) {
    struct PolyNode* newNode = createNode(coeff, pow);
    if (head == NULL) return newNode;

    struct PolyNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print polynomial
void display(struct PolyNode* head) {
	struct PolyNode* temp = head;

	while (temp != NULL) {
		printf("%dx^%d", temp->coeff, temp->pow);

		if (temp->next != NULL)
			printf(" + ");

		temp = temp->next;
	}
	printf("\n");
}

// Add two polynomials
struct PolyNode* addPoly(struct PolyNode* p1, struct PolyNode* p2) {
    struct PolyNode* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            result = insertEnd(result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            result = insertEnd(result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            result = insertEnd(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertEnd(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertEnd(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

// Subtract polynomials (p1 - p2)
struct PolyNode* subPoly(struct PolyNode* p1, struct PolyNode* p2) {
    struct PolyNode* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            result = insertEnd(result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            result = insertEnd(result, -p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            result = insertEnd(result, p1->coeff - p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertEnd(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertEnd(result, -p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

int main() {
    struct PolyNode* poly1 = NULL;
    struct PolyNode* poly2 = NULL;
    struct PolyNode* sum = NULL;
    struct PolyNode* diff = NULL;

    // Polynomial 1: 3x^3 + 2x^2 + 1
    poly1 = insertEnd(poly1, 3, 3);
    poly1 = insertEnd(poly1, 2, 2);
    poly1 = insertEnd(poly1, 1, 0);

    // Polynomial 2: 4x^3 + 2x + 5
    poly2 = insertEnd(poly2, 4, 3);
    poly2 = insertEnd(poly2, 2, 1);
    poly2 = insertEnd(poly2, 5, 0);

    printf("Polynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    // Addition
    sum = addPoly(poly1, poly2);
    printf("Sum: ");
    printPoly(sum);

    // Subtraction
    diff = subPoly(poly1, poly2);
    printf("Difference (Poly1 - Poly2): ");
    printPoly(diff);

    return 0;
}