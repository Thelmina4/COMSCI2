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

think of the bounds - 
make functions for 
 - allocated
 - freeList


*/
// THIS DOESN'T WORK!!!!!!

// libraries
#include<stdio.h>
#include<stdlib.h>

// structs
typedef struct Dll Dll;

struct Dll {
    int data;
    Dll *next;
    Dll *prev;
};

// prototype Functions
// to confirm that the memory has been allocated for the Sll
void allocated(Dll *input);
// free the linked list
void freeList(struct Dll *head);
// print out the linked list
void printInts(Dll *start);
// print in reverse
void printRev(Dll *start);
// count the linked list
int count(Dll * start);
// create the linked list
Dll *linked(int n, char *input[]);
// Find the last consecutive even
Dll *even(Dll *start);
// Find the last consecutive odd
Dll *odd(Dll *start);
// find the position of the node
int pos(Dll *node, Dll *start){
    int c = 0;
    Dll *tmp;
    tmp = start;
    while (tmp->data % 2 != 1 && tmp->next != NULL) {
        tmp = tmp->next;
        c++;
    }
    return c;
}
// Funtion so sort the list to even 1st, odd last
Dll *sorted(Dll *start, Dll *lastOdd)
{
    // there are 3 possibilities
    // 1. there is only one link - already dealt with in main
    Dll *firstOdd, *tmp, *lastEven, *previous;
    firstOdd = lastOdd;
    previous = firstOdd->prev;
    while (firstOdd->prev != NULL && previous->data % 2 != 0) {
        firstOdd = firstOdd->prev;
        previous = firstOdd->prev;

    }

    printf("First odd : %d \n last odd %d \n", firstOdd->data, lastOdd->data);
    // Now I have both the odd ends
    while (lastOdd->data %2 != 0 && lastOdd->next != NULL) {
        tmp = lastOdd->next;
        lastOdd->next = tmp->next;
        if (tmp->data %2 == 0) {
            if (lastOdd->prev == NULL) {
                tmp->prev = NULL;
                tmp->next = firstOdd;
                lastEven = tmp;
            } else {
                lastEven->next = tmp;
                firstOdd->prev = tmp;
            }
        }
        lastOdd = lastOdd->next;
    }
    
    return lastOdd;
}

// Find the last consecutive even
Dll *even(Dll *start);
// Find the last consecutive odd

Dll *odd(Dll *start);


// ###################################################
// main Function
int main(int argc, char *argv[]) {

    int n = argc -1;
    Dll *start = NULL;
    start = linked(n, argv);
    // printInts(start);
    // printRev(start);
    // count(start);
    if (count(start) == 1) {
        printf("%d\n", start->data);
        return 0;
    }
    // is the first odd or even
    Dll *first_even, *first_odd;
    first_even = even(start);
    first_odd = odd(start);
    // printf("first odd here %d\n", first_odd->data);
    if (first_even->next == NULL || first_odd->next == NULL) {
        printInts(start);
        return 0;
    }
    start = sorted(start, first_odd);

    printInts(start);
    freeList(start);
    // printf("%dN", 44%2);
    return 0;
}

// #####################################################
// implemented Functions
// Function to sort the task

// Helper Functions
void allocated(Dll *input)
{
    if (!input) {
        printf("The Memory was not allocated\n");
    }
}

void freeList(struct Dll *head) {
    while (head) {
        struct Dll *t = head;
        head = head->next;
        free(t);
    }
}


void printInts(Dll *start)
{
    Dll *tmp;
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    } 
    for (tmp = start; tmp->next != NULL; tmp = tmp->next) {
        printf("%d\n", tmp->data);
    }
}

void printRev(Dll *start)
{
    Dll *tmp;
    tmp = start;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        // printf("%d\n", tmp->data);
    }
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
        printf("%d\n", tmp->data);
    }  
}

int count(Dll *start) {
    int t = 1;
    Dll *tmp;
    for (tmp = start; tmp->next != NULL; tmp = tmp->next) {
        t++;
    }
    return t;
}


Dll *linked(int n, char *input[])
{
    Dll *start = (Dll*)malloc(1*sizeof(Dll));
    Dll *current, *previous;
    current = start;
    current->prev = NULL;
    allocated(start);

    for (int i = 0; i < n; i++) {

        current->data = atoi(input[i+1]);
        current->next = (Dll*)malloc(1*sizeof(Dll));
        allocated(current->next);
        previous = current;
        current = current->next;
        current->prev = previous;
    }
    current->next = NULL;
    return start;

}

Dll *even(Dll *start)
{
    Dll *tmp;
    tmp = start;    
    while (tmp->data % 2 == 0 && tmp->next != NULL) {
        tmp = tmp->next;
    }
    return tmp;
}

//  Find the last consecutive odd
Dll *odd(Dll *start)
{
    Dll *tmp;
    tmp = start;
    while (tmp->data % 2 != 1 && tmp->next != NULL) {
        tmp = tmp->next;
    }
    return tmp;
}