/*
Author: Thelma Clarke
SID: 19746069

Practice for lab exam 2
Singly linked list

 input:
Input at the head instead of the tail
./ 10 20 30
 output:
30
20
10

Plan:
make a struct for the linked list
make allocated funtion
make an array for the input - or is there any need for this?
print the linked list
Free the memory

*/

// Struct
typedef struct Sll Sll;

struct Sll {
    int data;
    Sll * next;
};

// Libraries
#include<stdio.h>
#include<stdlib.h>

// prototype functions
void allocated(Sll *input);
void printInts(Sll *start);

Sll *insert_middle(int n, Sll *middle, Sll *start)
{
    Sll *tmp = (Sll*)calloc(1, sizeof(Sll));
    tmp = start;
    while(n) {
        if (tmp->data < middle->data ) {
            tmp = tmp->next;
            n--;
        }
        middle->next = tmp->next;
        tmp->next = middle;
        n = 0;
    }
    return start;
}

Sll *insert_head(int i, char *argv[], Sll *head)
{
    // printf("new_node: %d\n head: %d\n", new_node->data, head->data);
    Sll *new_node = (Sll*)calloc(1, sizeof(Sll));
    new_node->data = atoi(argv[i]);
    new_node->next = head;
    // printf("new_node: %d\n head: %d\n", new_node->data, head->data);
    head = new_node;
    return head;
}

Sll *first_node(int i, char * argv[])
{
    Sll *first = (Sll*)calloc(1, sizeof(Sll));
    first->data = atoi(argv[i]);
    first->next = NULL;
    return first;
}

void countNodes(Sll *start)
{
    int count = 0;
    Sll *p = NULL;
    for (p = start; p != NULL; p = p->next ) {
        count++;
    }
    printf("Total nodes: %d\n", count);
}

void freeList(struct Sll *head) {
    while (head) {
        struct Sll *t = head;
        head = head->next;
        free(t);
    }
}

Sll *node(int i)
{
    Sll *first = (Sll*)calloc(1, sizeof(Sll));
    first->data = i;
    first->next = NULL;
    return first;
}

void largestNode(Sll *start) {
    int large = start->data;
    // printf("large start: %d\n", large);
    Sll *p = NULL;
    for (p = start; p != NULL; p = p->next ) {
        if (p->data > large) {
            large = p->data;
        }
    }
    printf("largest Node = %d\n", large);
}

Sll *rm_node(int value, Sll *start)
{
    // think about the cases
    // 1. empty list
    if (start == NULL) {
        return start;
    }

    Sll *curr = start;
    Sll *prev = NULL;

    // case 2 , the vlaue is at the head
    if (curr->data == value) {
        start = curr->next;
        free(curr);
        return start;
    }

    // the node is somewhere else in the list
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);

    return start;
}
// main function
int main(int argc, char *argv[]) {
    
    int n = argc - 1;
    if (n == 0) {
        return 0;
    }
    Sll *start = NULL;
    Sll *middle = NULL;
    middle = first_node(1, argv);
    start = first_node(2, argv);
    // printInts(start);
    // command line is ./ 25 10 20 30 
    for (int i = 3; i<= n; i++) {
        start = insert_head(i, argv, start);
    }

    start = insert_middle(n, middle, start);
    // I want to insert 25 into the linked list
    // printInts(start);
    countNodes(start);
    largestNode(start);

    start = rm_node(50, start);

    printInts(start);

    freeList(start);
    return 0;
}

// implementation of Functions


void allocated(Sll *input) {
    // printf("Test that allocation function works: \n");
    if (!input) {
        printf("The memory was not allocated: \n");
    }
}

void printInts(Sll *start) {
   	int count = 0;
	Sll* p = NULL;
	for(p = start; p != NULL; p = p->next)
	{
		printf("%d\n", p->data);
	}
}
