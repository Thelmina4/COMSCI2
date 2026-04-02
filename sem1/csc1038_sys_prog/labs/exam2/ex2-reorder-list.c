/*
Name: Thelma Clarke
SID: 19746069
Date 27.28.2025

file: 
ex2-reorder-list.c

Task: given a sequence of integers representing customer IDs in a waiting list
reorder this list so that all customers with even IDs are served before customers with odd IDs, 
while keeping the original relative order within each group (even and odd).
Original order: 5 → 2 → 7 → 8 → 4 → 9

Reordered: 2 → 8 → 4 → 5 → 7 → 9

All nodes with even values appear before all nodes with odd values.

The original relative order of even nodes is preserved.

The original relative order of odd nodes is preserved.

Prints the final reordered list, one ID per line.

Input:
Accepts a list of integers (customer IDs) as command-line arguments.
Stores them in a linked list using a struct and dynamic memory allocation.



Output:

Plan:

Put the first n digits into a linked list

think of the bounds - MAKE A LIST OF EVENS AND A LIST OF ODDS & JOIN
make functions for 
 - allocated
 - freeList


*/

// libraries
#include<stdio.h>
#include<stdlib.h>

// structs
typedef struct Sll Sll;

struct Sll {
    int data;
    Sll *next;
};

// prototype Functions
// to confirm that the memory has been allocated for the Sll
void allocated(Sll *input);
// free the linked list
void freeList(struct Sll *head);
// print out the linked list
void printInts(Sll *start);

// create the linked list
Sll *link(Sll *start, int value);

// Funtion so sort the list to even 1st, odd last
Sll *reorder(Sll *start);

// ###################################################
// main Function
int main(int argc, char *argv[]) {

    int n = argc -1;
    if (n < 1) {
        return 0;
    }
    Sll *start = NULL;
    for (int i = 0; i<n ; i++) {
        start = link(start, atoi(argv[i+1]));
        // printf("%d\n", atoi(argv[i+1]));
    }
    start = reorder(start);
    printInts(start);
    freeList(start);
    return 0;
}

// #####################################################
// implemented Functions
// Function to sort the task
Sll *reorder(Sll *start)
{
    // initialise them to null
    Sll *evenH = NULL, *evenT = NULL;
    Sll *oddH = NULL, *oddT = NULL;

    Sll *curr = start;
    while (curr) {
        // think of the 2 cases
        // if even and its the first even
        // if odd, & first odd
        if (curr->data % 2 == 0) {
            // then its even, is it the 1st even?
            if (evenH == NULL) {
                evenH = evenT = curr;
            } else {
                evenT->next = curr;
                // make it move alone the links
                evenT = curr;
            }
        } else {
            // then it's odd
            if (oddH == NULL) {
                oddH = oddT = curr;
            } else {
                oddT->next = curr;
                oddT = curr;                 
            }
        }
        curr = curr->next;
    }
    // printf("%d %d %d %d\n", evenH->data, evenT->data, oddH->data, oddT->data);
    // now what do I return?
    // combine them and finish them off
    if (oddT) oddT->next = NULL;
    if (evenT) evenT->next = oddH;

    // if there is no evens then
    if (evenH) return evenH;
    return oddH;
}

// Helper Functions
void allocated(Sll *input)
{
    if (!input) {
        printf("The Memory was not allocated\n");
    }
}

void freeList(Sll *head) {
    while (head) {
        struct Sll *t = head;
        head = head->next;
        free(t);
    }
}

void printInts(Sll *start)
{
    while (start) {
        printf("%d\n", start->data);
        start = start->next;
    }
}

Sll *link(Sll *start, int value)
{
    Sll *new = (Sll*)malloc(1*sizeof(Sll));
    // check that the memory was allocated
    allocated(new);
    // put the daata into the new link in the chain
    new->data = value;
    new->next = NULL;
    // printf("new : %d \n", new->data);

    // check if it is the head or the tail
    if (start == NULL) {
        return new;
    }

    // else the new node needs to go on to the tail of the input node
    Sll *curr = start;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    // now I'm definitely at the tail
    curr->next = new;
    // return the head of the list
    return start;   
}
