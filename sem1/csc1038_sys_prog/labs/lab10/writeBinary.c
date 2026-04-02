/*
Make a script that will read a text file for
lab10-load-binary.c

4 john
3 dcu
18
34.5
6 thelma
7 trinity
120
85.6

print what I have 
convert that into binary

and output that into a file called studentBinary.bin

*/

// Libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct
// do i need it?
typedef struct {
    char name[50];
    char college[50];
    int age;
    int grade;
} Student;

// prototypes

// Main
int main() {
    FILE *txt = fopen("test.txt", "r");
    FILE *bin = fopen("studentBinary.bin", "wb");

    if (!txt || !bin) {
        printf("Failed to open");
    }

    int len;
    Student s;
    // Check that there is a first line in 4
    while (fscanf(txt, "%d", &len) == 1) {
        // read the name
        fscanf(txt, "%s", s.name);

        // now write out to the .bin file the first line
        fwrite(&len, sizeof(int), 1, bin);
        fwrite(s.name, sizeof(char), len, bin);

        // read college
        fscanf(txt, "%d", &len);
        fscanf(txt, "%s", s.college);

        // write college
        fwrite(&len, sizeof(int), 1, bin);
        fwrite(s.college, sizeof(char), len, bin);

        // read age, & grade
        fscanf(txt, "%d", &s.age);
        fscanf(txt, "%d", &s.grade);
        
        fwrite(&s.age, sizeof(int), 1, bin);
        fwrite(&s.grade, sizeof(int), 1, bin);
    }
    
    fclose(txt);
    fclose(bin);
    return 0;
}
// implemented