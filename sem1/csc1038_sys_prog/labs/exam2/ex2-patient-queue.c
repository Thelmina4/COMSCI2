/*
Author: Thelma Clarke
SID: 19746069
Date: 27/11/2025
Filename:
ex2-patient-queue.c
Given:
implementing a simple patient queue system for a small clinic.
 - ID (an integer, assigned automatically starting from 
    - 1 in the order they appear in the input)
 - Name (a string, you can assume maximum 50 characters)
 - Priority (an integer between 1 and 5, where 5 is the highest priority)
input:
./ex2-patient-queue 3 "Alice" 3 "Bob" 5 "Carol" 4
 - Accepts the number of patients and their details (name and priority) as command-line arguments.
 - Assigns IDs automatically in the order they are inserted into the list (starting from 1).
 - Displays the full queue in the order of arrival in the following format ID:
    <id>, Name: <name>, Priority: <priority> 


output:
Counts and displays how many patients have priority
    4 or 5 (high priority) in the format High priority count: <number>
ID: 1, Name: Alice, Priority: 3
ID: 2, Name: Bob, Priority: 5
ID: 3, Name: Carol, Priority: 4
High priority count: 2

Plan:
make Struct for patient
 - id
 - name
 - priority

make a funtion fpor printing
make a function to find cound of priority of > 4 

*/
// Libraries

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
// struct
typedef struct Patient Patient;

struct Patient {
    int id;
    char name[50];
    int priority;
    Patient *next;
};

// prototype functions
// to confirm that the memory is allocated correctly
// there is nothing returned so the function is void
void allocated(Patient *input);
void freeList(Patient *head);
void printFullOutput(Patient *head);
Patient *node(Patient *head, int ID, char *name, int priority);

int priorityCount(Patient *head);
// main function
int main(int argc, char *argv[]) {
    // basic printf to copy & paste to where is needed
    // printf("\n", )

    int n = atoi(argv[1]);
    // set the first patient to null
    Patient *head = NULL;

    int index = 2;
    for (int i = 0; i < n; i++) {
        char *name = argv[index++];
        int priority = atoi(argv[index++]);

        head = node(head, i+1, name, priority);
    }

    printFullOutput(head);
    int c = priorityCount(head);
    printf("High priority count: %d\n", c);
    freeList(head);
    return 0;
}

// implementation of Functions
void allocated(Patient *input) {
    // printf("Test that allocation function works: \n");
    if (!input) {
        printf("The memory was not allocated: \n");
    }
}

void freeList(Patient *head) {
    while (head) {
        struct Patient *t = head;
        head = head->next;
        free(t);
    }
}

void printFullOutput(Patient *head) {
    while (head) {
        printf("ID: %d, Name: %s, Priority: %d\n",
               head->id, head->name, head->priority);
        head = head->next;
    }
}

Patient *node(Patient *head, int ID, char *name, int priority)
{
    Patient *newNode = (Patient*)malloc(1 * sizeof(Patient));
    allocated(newNode);

    newNode->id = ID;
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->next = NULL;
    // printf("%d, %s, %d\n", curr->id, curr->name, curr->priority);

    if (head == NULL) {
        return newNode;
    }

    Patient *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

int priorityCount(Patient *head)
{
    int count = 0;
    while (head) {
        if (head->priority >= 4) count++;
        head = head->next;
    }
    return count;
}