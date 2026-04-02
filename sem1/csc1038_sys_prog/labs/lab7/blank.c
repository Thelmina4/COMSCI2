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
void allocated(Student *input) {
    printf("Allocation Fucntion Works\n");
    if (!input) {
        printf("Memory not allocated");
    }
}

void getinput(Student *pStudents, char *argv[], int startIndex, int numStudents) {
    // each student uses 3 inputs
    int argindex = 1 + (startIndex * 3);

    for (int i = 0; i < numStudents; i++) {
        strcpy(pStudents[startIndex + i].name, argv[argindex++]);
        printf("%s\n", pStudents[i].name);
        strcpy(pStudents[startIndex + i].programme, argv[argindex++]);
        pStudents[startIndex + i].grade = atof(argv[argindex++]);
    }
}



// void printStudents(Student *pStudents, int totalStudents) {
//     for (int i = 0; i < totalStudents; i++) {
//         printf("%s\t%s\t%.2f\n",
//                pStudents[i].name,
//                pStudents[i].programme,
//                pStudents[i].grade);
//     }
// }

// Main Function
int main(int argc, char *argv[]) {

    // how many students in total?
    int total = (argc -1) /3;
    printf("sdfsdfgdf\n");
    // make the student array of type student for 2 only
    Student *pStudent = NULL;
    pStudent = malloc(2*sizeof(Student));
    allocated(pStudent);

    // get the input for the first 2 students
    getinput(pStudent, argv, 0, 2);

    for (int i = 0; i < 2; i++) {
    printf("%s\t%s\t%.2f\n",
            pStudent[i].name,
            pStudent[i].programme,
            pStudent[i].grade);
    }

    if (total > 2) {
        Student *tmp = realloc(pStudent, total*sizeof(Student));
        allocated(tmp);
        pStudent = tmp;
        getinput(pStudent, argv, 2, total - 2);  
    }  

    for (int i = 0; i < total; i++) {
        printf("%s\t%s\t%.2f\n",
                pStudent[i].name,
                pStudent[i].programme,
                pStudent[i].grade);
    }
    // printStudents(pStudent, total);
    free(pStudent);
    pStudent = NULL;
    return 0;
}
// Functions