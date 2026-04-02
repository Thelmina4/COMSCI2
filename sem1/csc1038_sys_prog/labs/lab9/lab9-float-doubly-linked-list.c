/*
Author: Thelma Clarke
SID: 19746069

lab9-float-doubly-linked-list.c
arguments from the command line.
 first argument is the number of floating elements n
next n arguments refer to the input floating numbers.
 input:
./lab9-float-doubly-linked-list 5 8 9 21 12 4

 output:displays all numbers line by line in reversed order.
4.00
12.00
21.00
9.00
8.00

Plan:
Make the struct dbl
function to confirm allocation
function for output

*/

// Libraries
#include<stdio.h>
#include<stdlib.h>

typedef struct Dbl Dbl;

struct Dbl
{
    /* data */
    float data;
    Dbl *next;
    Dbl *prev;
};

// prototyoe functions
// check that the memory is allocated
void allocate(Dbl *input);
// take in the data, type float into struct type dbl
Dbl *get_float(int n, char *argv[]);
// print it out in reverse
void revPrint(Dbl *input);

// main function
int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    Dbl *start = NULL;

    start = get_float(n, argv);
    revPrint(start);
    return 0;
}

// implementation of Functions
void allocate(Dbl *input)
{
    // printf("This fucntion does not work\n");
    if (!input) {
        printf("The memory was not allocated\n");
    }
}

Dbl *get_float(int n, char *argv[])
{
    Dbl *current, *first, *prev;
    first = (Dbl*)calloc(1, sizeof(Dbl));
    allocate(first);
    current = first;

    int index = 2;
    current->data = atof(argv[index++]);
    current->prev = NULL;
    n--;

    // current = first means that the current node is the first node
    while (n) {
        current->next = (Dbl*)calloc(1, sizeof(Dbl));
        allocate(first);
        prev = current;
        current = current->next;
        current->data = atof(argv[index++]);
        current->prev = prev;
        n--;
    }
    current->next = NULL;
    // return the address of the last node
    return current;
}
// print out the list in reverse
void revPrint(Dbl *input)
{
	Dbl* p = NULL;
	for(p = input; p != NULL; p = p->prev)
	{
		printf("%.2f\n", p->data);
	}
}