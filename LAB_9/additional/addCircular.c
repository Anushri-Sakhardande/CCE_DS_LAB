#include <stdio.h>
#include <stdlib.h>

typedef struct pnode* pptr;
typedef struct pnode
{
    int coefficient;
    int exponent;
    pptr next;
    pptr prev;
} pnode;

pptr createHeaderNode() {
    pptr header = (pptr)malloc(sizeof(pnode));
    header->coefficient = 0;
    header->exponent = -1;
    header->prev = header;
    header->next = header;
    return header;
}

// Function to insert a term into the polynomial as a doubly linked node
void attach(pptr header, int coefficient, int exponent) {
    pptr newNode = (pptr)malloc(sizeof(pnode));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;

    pptr current = header->next;
    while (current->exponent > exponent) {
        current = current->next;
    }

    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
}

// Function to add two polynomials and return the result
pptr addPolynomials(pptr poly1, pptr poly2) {
    pptr result = createHeaderNode();

    pptr term1 = poly1->next;
    pptr term2 = poly2->next;

    while (term1->exponent >= 0 || term2->exponent >= 0) {
        if (term1->exponent == term2->exponent) {
            int coefficient = term1->coefficient + term2->coefficient;
            attach(result, coefficient, term1->exponent);
            term1 = term1->next;
            term2 = term2->next;
        } else if (term1->exponent > term2->exponent) {
            attach(result, term1->coefficient, term1->exponent);
            term1 = term1->next;
        } else {
            attach(result, term2->coefficient, term2->exponent);
            term2 = term2->next;
        }
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(pptr header) {
    pptr current = header->next;
    while (current->exponent >= 0) {
        if (current != header->next) {
            printf(" + ");
        }
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create header nodes for two polynomials
    pptr poly1 = createHeaderNode();
    pptr poly2 = createHeaderNode();

    // Insert terms into the first polynomial
    attach(poly1, 3, 2);
    attach(poly1, 4, 1);
    attach(poly1, 5, 0);

    // Insert terms into the second polynomial
    attach(poly2, 2, 2);
    attach(poly2, 1, 1);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    pptr result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}