/*
Author: Thelma Clarke
SID: 19746069

lab9-push-pop.c
demostrate the push and pop operations from a list
 arguments from the command line
 first argument is the number of integers n
 next n arguments refer to the integers.

 The last argument is the new integer we want to add to the list.
  remove the last two elements (so pop twice),
  add the last two arguments into the end (so push twice).
  Then the program displays all elements line by line.

 input:
./lab9-push-pop 7 6 3 6 4 0 2 4 5 9
 output:
6
3
6
4
0
5
9

Plan:
Use Dbl Linked List. 
mke a dbl link list. 
creat a variable of the return (last)
get it's prev. and make it's prev, current-next = Null
- do that twice
should I free or realloc, once I have popped?

and then add on 2 more to the list

print the list in forward - I will be at the last, do go all the way to the front

*/

// Libraries
#include<stdio.h>
#include<stdlib.h>

// Struct
typedef struct Dble Dble;

struct Dble {
    /* Data */
    int data;
    Dble *next;
    Dble *prev;
};

// prototyoe functions
void allocate(Dble *input);
Dble *get_int(int n, char *argv[]);
void *pop(Dble *input);
void *push(Dble *input, int n);

// print out the list in reverse
void revPrint(Dble *input);

// print out the list from start
void forwadPrint(Dble *input);

// clean up the noded
void cleanup(Dble *input);


// main function
int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    Dble *start = NULL;

    start = get_int(n, argv);
    // revPrint(start);

    start = pop(start);
    start = pop(start);

    int push1 = atoi(argv[2+n]);
    int push2 = atoi(argv[3+n]);
    // printf("%d, %d\n", push1, push2);

    start = push(start, push1);
    // revPrint(start);
    start = push(start, push2);
    // revPrint(start);

    // printf("popped\n");
    forwadPrint(start);
    // clean up any nodes
    cleanup(start);
    return 0;
}

// implementation of Functions

// print out the list in reverse
void revPrint(Dble *input)
{
	Dble* p = NULL;
	for(p = input; p != NULL; p = p->prev)
	{
		printf("%d\n", p->data);
	}
}

Dble *get_int(int n, char *argv[])
{
    // declare my variables
    int index = 2;
    Dble *curr, *first, *prev = NULL;
    // make the first link
    first = (Dble*)calloc(1, sizeof(Dble));
    allocate(first);

    // initiate the current to the first link
    curr = first;
    curr->prev = NULL;
    curr->data = atoi(argv[index++]);
    n--;

    // add the rest
    while (n) {
        curr->next = (Dble*)calloc(1, sizeof(Dble));
        allocate(curr->next);
        prev = curr;
        curr = curr->next;
        curr->data = atoi(argv[index++]);
        curr->prev = prev;
        n--;
    }
    curr->next = NULL;
    return curr;
}

void allocate(Dble *input)
{
    // printf("This Function works\n");
    if (!input) {
        printf("The memory was not allocated");
    }
}

void *pop(Dble *input)
{
    // input the last link. 
    // next, prev
    if (!input) return NULL;

    Dble *prev = input->prev;
    if (prev) {
        prev->next = NULL;
    }
    free(input);
    return prev;
}

void *push(Dble *input, int n) {

    Dble *new = (Dble*)calloc(1, sizeof(Dble));
    allocate(new);
    new->data = n;
    new->prev = input;
    new->next = NULL;

    if (input) {
        input->next = new;
    }
    return new;
}

void cleanup(Dble *input)
{
    while (input) {
        Dble *prev = input->prev;
        free(input);
        input = prev;
    }
    // if (!input) {
    //     printf("Mrmory not unallocated");
    // }
}

void forwadPrint(Dble *input)
{
    // printf("%d\n", input->data);
    while (input && input->prev) {
        input = input->prev;
        // printf("data: %d", input->data);
    }
	Dble* p = NULL;
	for(p = input; p != NULL; p = p->next)
	{
		printf("%d\n", p->data);
	}
}