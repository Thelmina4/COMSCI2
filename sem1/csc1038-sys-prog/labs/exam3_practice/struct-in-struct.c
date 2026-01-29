/* 
input from command line:
Thelma Clarke 12 FWD 9.99 14 04 2000 John Murphy 8 MID 7.50 01 01 1999 shauna Clarke 11 FWD 9.99 14 04 2000 Alice King 10 DEF 5.00 10 09 1998 Brian Clarke 12 FWD 9.99 14 04 2000

output:

Name: Thelma Clarke
Goals: 12
Position: FWD
Price: 9.99
DOB: 14-04-2000

top goal scorer of forward players

total goals scored

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Typedef forward declarations
typedef struct DOB DOB;
typedef struct Name Name;
typedef struct Player Player;
typedef struct Node Node;

// Struct definitions
struct DOB {
    int day;
    int month;
    int year;
};

struct Name {
    char firstName[30];
    char lastName[30];
};

struct Player {
    Name name;
    int goal_scored;
    char position[5];
    float price;
    DOB date_of_birth;
};

struct Node {
    Player data;
    struct Node *next;
};

// prototype methods
// ensure that the memory is assigned
void allocated(Node *input);
// clear the full list
void freeList(Node *head);

// create player
Player create(char *fn, char *ln, int g, char *pos, float pr, int d, int m, int y)
{
    // Thelma Clarke 12 FWD 9.99 14 04 2000
    Player p;
    strcpy(p.name.firstName, fn);
    // printf("p.name.firstName %s\n", p.name.firstName);
    strcpy(p.name.lastName, ln);
    p.goal_scored = g;
    strcpy(p.position, pos);
    p.price = pr;
    p.date_of_birth.day = d;
    p.date_of_birth.month = m;
    p.date_of_birth.year = y;
    return p;

}

// add player to node ll at tail
Node *insertTail(Node *head, Player p)
{
    Node *newNode = malloc(sizeof(Node));
    // make sure that the memory is allocated
    allocated(newNode);
    // add the data to the new node
    newNode->data = p;
    newNode->next = NULL;

    // check if the list is empty
    if (head == NULL) {
        return newNode;
    }
    // find the tail
    Node *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    // Link the tmp to the newnode
    tmp->next = newNode;

    // return the first node in the LL
    return head;
}

// create the player list
Node* createPlayerList(int argc, char *argv[]) {
    int numPlayers = (argc - 1) / 8;  // each player has 8 args
    Node *head = NULL;
    int index = 1;

    for (int i = 0; i < numPlayers; i++) {
        char *fn = argv[index++];
        char *ln = argv[index++];
        int goal = atoi(argv[index++]);
        char *pos = argv[index++];
        float price = atof(argv[index++]);
        int day = atoi(argv[index++]);
        int month = atoi(argv[index++]);
        int year = atoi(argv[index++]);

        Player p = create(fn, ln, goal, pos, price, day, month, year);
        head = insertTail(head, p);
    }

    return head;
}

// print all nodes
void printPlayer(Player p)
{
    printf("Name: %s %s\n", p.name.firstName, p.name.lastName);
    printf("Goals: %d\n", p.goal_scored);
    printf("Position: %s\n", p.position);
    printf("Price: %.2f\n", p.price);
    printf("DOB: %02d-%02d-%4d\n",
           p.date_of_birth.day,
           p.date_of_birth.month,
           p.date_of_birth.year);
}


// Print entire linked list
void printList(Node *head)
{
    while (head->next != NULL) {
        printPlayer(head->data);
        printf("\n");
        head = head->next;
    }
}

// delete node

// top goal scorer of forward players

// total goals scored

// print sorted by name

// ################## - main function - ###############################
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please input a player\n");
        return 1;
    }
    Node *head = createPlayerList(argc, argv);
    printList(head);
    freeList(head);
    return 0;
}

// ####################################################################

// Implemented Functions
void allocated(Node *input) {
    // printf("Test that allocation function works: \n");
    if (!input) {
        printf("The memory was not allocated: \n");
    }
}

void freeList(Node *head) {
    while (head) {
        struct Node *t = head;
        head = head->next;
        free(t);
    }
}
