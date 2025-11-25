/*
rugby.py
Author: thelma clarke
A try (worth 5 points)
A conversion (worth 2 points)
A penalty (worth 3 points)
A drop-goal (worth 3 points).

Take four inputs (try, conversion, penalty, drop-goal) from command lines;

Calculate the total point;

Print the total point;
*/

#include<stdio.h>
#include<stdlib.h>

void totalScore(int t, int c, int p, int g){
    // try putting them on one line
    int finalScore = (t * 5) + (c * 2) + (p * 3) + (g * 3);
    // try adding inside the printf
    printf("Final Score: %d\n", finalScore); 
}

int validInput(char prompt[]){
    int num;
    char eol;
    char repeat[] = "Please enter a number greater than or equal to zero\n";
    int i = 2;

        printf("%s", prompt);
        int ch = getchar();
        if (ch == '\n') {
            printf("%s", repeat);
            continue;
        } else {
            ungetc(ch, stdin); // put it back so scanf sees it
        }
        if (scanf("%d%c", &num, &eol) != 2) {
            printf("%s", repeat);
            while (getchar() != '\n');
            continue;
        }
        if (eol != '\n' || num == '\n'){
            printf("%s", repeat);
            while (getchar() != '\n');
            continue;
        }

        if (num < 0) {
            printf("%s", repeat);
            continue;
        }
        return num; 

    } 
}

int main(){
    int try = 0;
    int conversion = 0;
    int penalty = 0;
    int goal = 0;

    try = validInput("How many tries were scored? ");
    conversion = validInput("How many conversions were there? ");
    penalty = validInput("How many penalties were scored? ");
    goal = validInput("How many drop goals were there? ");

    totalScore(try, conversion, penalty, goal);
    return (0);
}