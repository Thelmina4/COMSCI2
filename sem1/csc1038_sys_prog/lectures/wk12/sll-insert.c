#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node *next;
};

// Insert new node at the head of the list
void insertAtHead(struct Node **head, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Print the linked list
void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Free all nodes
void freeList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        struct Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    struct Node *head = NULL;

    // Insert all command-line args at the head
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        insertAtHead(&head, value);
    }

    // Print final list
    printList(head);

    // Free memory
    freeList(head);

    return 0;
}
