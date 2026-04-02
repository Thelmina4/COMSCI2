// C program to sort Linked List
// using Bubble Sort

#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to get the length of the linked list
int getLength(struct Node *head) {
    int len = 0;
    struct Node *curr = head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

// Function to perform bubble sort on the linked list
struct Node *bubbleSort(struct Node *head) {
    struct Node *currNode = head;
    int len = getLength(head);
    int itr = 0;
    int swapped;

    // Iterating over the whole linked list
    while (itr < len) {
        struct Node *traverseNode = head;
        struct Node *prevNode = head;
        swapped = 0;

        while (traverseNode->next != NULL) {

            // Temporary pointer to store the next
            // pointer of traverseNode
            struct Node *ptr = traverseNode->next;
            if (traverseNode->data > ptr->data) {
                swapped = 1;
                if (traverseNode == head) {

                    // Performing swap operations and
                    // updating the head of the linked list
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode = ptr;
                    head = prevNode;
                }
                else {

                    // Performing swap operation
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode->next = ptr;
                    prevNode = ptr;
                }
                continue;
            }
            prevNode = traverseNode;
            traverseNode = traverseNode->next;
        }

        // If no swap occurred, break the loop
        if (!swapped) {
            break;
        }

        ++itr;
    }

    // Returning the head of the linked list
    return head;
}

void printList(struct Node *curr) {
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

struct Node *createNode(int x) {
    struct Node *newNode = 
      (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
  
  	// Create a hard-coded linked list:
	// 5 -> 1 -> 32 -> 10 -> 78
    struct Node *head = createNode(5);
    head->next = createNode(1);
    head->next->next = createNode(32);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(78);

    head = bubbleSort(head);
    printList(head);

    return 0;
}