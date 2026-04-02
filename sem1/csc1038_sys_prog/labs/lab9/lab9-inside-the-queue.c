/*
Author: Thelma Clarke
SID: 19746069

given: 8 7 3 4 5 6 9 2 14 12
 first argument is a member of the given list of numbers
find where the member is in the list, and place the second argument (an integer) after found member.
Then the program displays the new list line by line.
 required to implement a linked list to store all integers. 

 input:
./lab9-inside-the-queue 5 17
 output:
8
7
3
4
5
17
6
9
2
14
12

Plan:
make a struct, singly linked list is fine
make a get_int function
make an insert function
tmp->data = val
tmp->prev = (don't need for SLL)
tmp->next = cur->next
cur->next = tmp

print function from start
*/

// Libraries
#include<stdio.h>
#include<stdlib.h>
// Struct
typedef struct SLL SLL;

struct SLL
{
    /* data */
    int data;
    SLL *next;
};

// prototype functions
void allocate(SLL *input);

SLL *get_int(int *num, int len_array);
void printSLL(SLL *start);
SLL *insertInt(SLL *start, int find, int input);

// main function
int main(int argc, char *argv[]) {

    int find = atoi(argv[1]);
    int input = atoi(argv[2]);
    int numbers[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    int len_array = sizeof(numbers)/sizeof(int);

    // for (int i =0;i<sizeof(numbers)/sizeof(int);i++) printf("%d ", numbers[i]);

    SLL *start = get_int(numbers, len_array);
    // printf("start->data: %d\n", start->data);
    SLL *middle = insertInt(start, find, input);
    printSLL(start);
    return 0;
}

// implementation of Functions
void allocate(SLL *input)
{
    if (!input) printf("Memory is NOT allocated\n");
    // if (input) printf("Memory IS allocated\n");
}

SLL *get_int(int *num, int len_array)
{
    // printf("num[0]: %d ",num[0]);
    SLL *curr, *first;
    first = (SLL*)calloc(1, sizeof(SLL));
    allocate(first);
    curr = first;
    int i = 0;
    // printf("%d\n", num[i]);
    curr->data = num[i];
    // printf("%d\n", curr->data);
    i++;
    // printf("%d \n", curr->data);
    while (i < len_array) {
        curr->next = (SLL*)calloc(1, sizeof(SLL));
        allocate(curr->next);
        
        curr = curr->next;
        curr->data = num[i];
        // printf("%d\n", num[i]);
        i++;
    }
    curr->next = NULL;
    // printf("first->data: %d\n", first->data);
    return first;
}

void printSLL(SLL *start)
{
    SLL *p = NULL;
    // printf("Start: %d\n", start->data);
    for (p = start; p != NULL; p = p->next) {
        printf("%d\n", p->data);
    }
}

SLL *insertInt(SLL *start, int find, int input)
{
    SLL *curr = start;
    while (curr->data != find) {
        curr = curr->next;
    }
    // printf("find: %d\n", curr->data);
    // break the chain
    // the next point is curr->next so input->next shoult be this

    // turn the input into a link
    SLL *insert;
    insert = (SLL*)calloc(1, sizeof(SLL));
    insert->data = input;

    // attach it to the next link in curr->next
    insert->next = curr->next;
    // insert it into curr-Next
    curr->next = insert;
}