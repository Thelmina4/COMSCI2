/*
Author: Thelma Clarke
SID: 19746069

lab9-integer-singly-linked-list.c
following arguments from the command line.
- first argument is the number of integer elements n.
- The next n arguments refer to the input integers.

required to implement a singly linked list to store all integers
 - use dynamic memory allocation

 input:
 ./la9-integer-singly-linked-list 5 8 9 21 12 4

 output:
 8
9
21
12
4

Plan:
function to take in the input
function to check allocation
function to print the output

*/

// Libraries
#include<stdio.h>
#include<stdlib.h>

// Structure SinglyLinkedList
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedList {
    int integer;
    SinglyLinkedList *next;
};

// prototype functions
void allocated(SinglyLinkedList *input);
SinglyLinkedList *getInt(int n, char *argv[]);
void printInts(SinglyLinkedList *start);

// main function
int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    // printf("%d\n", n);

    SinglyLinkedList *start = NULL;

    // start = inputData();

    start = getInt(n, argv);
    printInts(start);

    return 0;
}


// implementation of Functions

void allocated(SinglyLinkedList *input) {
    // printf("Test that allocation function works: \n");
    if (!input) {
        printf("The memory was not allocated: \n");
    }
}

/* This mean that the function will return a pointer that points to the structure Student */
SinglyLinkedList *getInt(int n, char *argv[])
{
    // take in the first integer
    SinglyLinkedList *current, *first;
    int index = 2;
    first = (SinglyLinkedList*)calloc(1, sizeof(SinglyLinkedList));
    allocated(first);
    current = first;
    current->integer = atoi(argv[index++]);
    n--;
    // now a loop for the rest of them
    while (n) {
        current->next = (SinglyLinkedList*)calloc(1, sizeof(SinglyLinkedList));
        allocated(current->next);
        current = current->next;
        current->integer = atoi(argv[index++]);
        n--;
    }
    current->next = NULL;
    return first;
}

void printInts(SinglyLinkedList *start) {
   	int count = 0;
	SinglyLinkedList* p = NULL;
	for(p = start; p != NULL; p = p->next)
	{
		printf("%d\n", p->integer);
	}
}
