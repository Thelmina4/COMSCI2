/*
Thelma Clarke
19746069

initially accepts an array of two students: the command line:

Name (an array of 20 characters)

Programme (an array of 20 characters)

Grade (float)

check if the number of input students from the command lines is more than two,
it allocate more memory so that all students info can be accommodated

The program displays the student info line by line

. malloc, calloc, realloc and free

Plan:
malloc for 2.
take in the data
if argc/3 < 2 realloc for argc/3 (remember that the first 2 are already in)

print each player name, progamme, grade

*/

// libraries
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
// Turn Struct to Variables
typedef struct Student Student;

struct Student {
    char name[20];
    char programme[20];
    float grade;
};

// prototype functions
void allocated(Student *input);
// input the first 2 students
void firstTwo(Student *pStudent, char *argv[]);

void getRest(Student *pStudent, char *argv[],int total);

int main(int argc, char *argv[]) {
    // printf("Hello");

    // how many students in total?
    int total = (argc -1) /3;
    // printf("%d\n", total);
    // make the student array of type student for 2 only
    Student *pStudent = NULL;
    pStudent = malloc(2*sizeof(Student));
    allocated(pStudent);

    firstTwo(pStudent, argv);

    if (total > 2) {
        Student *tmp = realloc(pStudent, total*sizeof(Student));
        allocated(tmp);
        pStudent = tmp;
        int rest = total-2;
        getRest(pStudent, argv, rest);
    }

    for (int i = 0; i < total; i++) {
    printf("%s, %s, %.2f\n",
            pStudent[i].name,
            pStudent[i].programme,
            pStudent[i].grade);
    }

    free(pStudent);
    pStudent = NULL;
    return 0;
}

void allocated(Student *input) {
    // printf("Allocation Fucntion Works\n");
    if (!input) {
        printf("Memory not allocated");
    }
}

// input the first 2 students
void firstTwo(Student *pStudent, char *argv[]) {
    int index = 1;
    for (int i = 0; i < 2; i++) {
        strcpy(pStudent[i].name, argv[index++]);
        // printf("%s\n", pStudent[i].name);
        strcpy(pStudent[i].programme, argv[index++]);
        pStudent[i].grade = atof(argv[index++]);
    }
}
void getRest(Student *pStudent, char *argv[],int total){
    int index = 7;

    for (int i = 2; i < total+2; i++) {
        strcpy(pStudent[i].name, argv[index++]);
        // printf("%s\n", pStudent[i].name);
        strcpy(pStudent[i].programme, argv[index++]);
        pStudent[i].grade = atof(argv[index++]);
    }
}