/* 
input from a file:
Thelma Clarke 12 FWD 9.99 14 04 2000
John Murphy 8 MID 7.50 01 01 1999
Alice King 10 DEF 5.00 10 09 1998

output:

Name: Thelma Clarke
Goals: 12
Position: FWD
Price: 9.99
DOB: 14-04-2000


*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


// Create a Player easily
Player createPlayer(char *fn, char *ln, int goals, char *pos,
                    float price, int d, int m, int y)
{
    Player p;
    strcpy(p.name.firstName, fn);
    strcpy(p.name.lastName, ln);
    p.goal_scored = goals;
    strcpy(p.position, pos);
    p.price = price;
    p.date_of_birth.day = d;
    p.date_of_birth.month = m;
    p.date_of_birth.year = y;
    return p;
}


// Linked list insert at head
Node *insertHead(Node *head, Player p)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = head;
    return newNode;
}


// Print a single player
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
    while (head != NULL) {
        printPlayer(head->data);
        printf("\n");
        head = head->next;
    }
}


// Read players from file
Node *readFromFile(char *filename, Node *head)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open %s\n", filename);
        return head;
    }

    char fn[30], ln[30], pos[5];
    int goals, d, m, y;
    float price;

    while (fscanf(fp, "%s %s %d %s %f %d %d %d",
                  fn, ln, &goals, pos, &price, &d, &m, &y) == 8)
    {
        Player p = createPlayer(fn, ln, goals, pos, price, d, m, y);
        head = insertHead(head, p);
    }

    fclose(fp);
    return head;
}

float totalSalaries(Node *head)
{
    float total = 0.0;
    while (head != NULL) {
        total += head->data.price;
        head = head->next;
    }
    return total;
}

// helper for the aphabetical order
int listLength(Node *head)
{
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
// compare the players
int comparePlayers(const void *a, const void *b)
{
    const Player *p1 = (const Player*)a;
    const Player *p2 = (const Player*)b;

    int last = strcmp(p1->name.lastName, p2->name.lastName);
    if (last != 0)
        return last;

    return strcmp(p1->name.firstName, p2->name.firstName);
}

void printAlphabetical(Node *head)
{
    int len = listLength(head);
    if (len == 0)
        return;

    // allocate array of players
    Player *arr = malloc(sizeof(Player) * len);

    // copy linked list to array
    Node *curr = head;
    for (int i = 0; i < len; i++) {
        arr[i] = curr->data;
        curr = curr->next;
    }

    // sort array
    qsort(arr, len, sizeof(Player), comparePlayers);

    // print sorted results
    printf("\n=== Players (A-Z) ===\n\n");
    for (int i = 0; i < len; i++) {
        printPlayer(arr[i]);
        printf("\n");
    }

    free(arr);
}

// MAIN
int main()
{
    Node *head = NULL;

    head = readFromFile("players.txt", head);

    printf("=== Player List ===\n\n");
    printList(head);
    printf("Total Salaries: %.2f\n", totalSalaries(head));

    printAlphabetical(head);

    return 0;
}
