#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    // plan the number of --
    // the max fname = 50
    // the max lname = 50
    // the max pos = 4
    // the max goals = 10000 (5 + 2)
    // the max total goals = same (5 + 2) 

    // for the number of ----, factor in the number of borders.
    // 1 plus the max space that I give it PLUS the number of cols
    
    int row, col;

    for (row= 0; row < 6; row++) {
        char *dash = "-";
        for (int i = 0; i<20; i++) {
            printf("%s", dash);
        }
        printf("\n");
                    printf("%s", "|");

        for (col = 0; col < 7; col++){
            // make the border 
            char *border = "|";
            char *s = "hi";
            printf("%*s%*s", 5+strlen(s)/2, s, 5-strlen(s)/2, "");
            printf("%s", border);

        }

        printf("\n");
            for (int i = 0; i<20; i++) {
            printf("%s", dash);
        }
        printf("\n");
    }
    int num = 321;
    char snum[5];

    // Convert 123 to string [buf]
    itoa(num, snum, 10);

    // Print our string
    printf("%d\n", strlen(snum));
    return 0;
}