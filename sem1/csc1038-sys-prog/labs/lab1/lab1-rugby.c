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

int main(int argc, char *argv[]){
    int try = 0;
    int conversion = 0;
    int penalty = 0;
    int goal = 0;
    // try putting them on one line
    try = atoi(argv[1]) * 5; conversion = atoi(argv[2]) * 2; penalty = atoi(argv[3]) * 3; goal = atoi(argv[4]) * 3;
    // try adding inside the printf
    printf("%d\n", try+conversion+penalty+goal);
    return 0;
}