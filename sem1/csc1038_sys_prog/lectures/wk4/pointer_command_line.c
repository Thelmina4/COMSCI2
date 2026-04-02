#include<stdio.h>
#include<string.h>
// ./pointer_command_line a aisdufh
int main(int argc, char *argv[]) {

    char *letter = argv[1];
    printf("argv[1] : %c \n\n", *letter);

    char *word = argv[2];
    int count = 0;
    for(int i = 0; i < sizeof(word); i++) {
        printf("while loop to print each element in the array of argv[2] : %c \n", *(word+i));
        if (*letter == *(word+i)) {
            printf("%c == %c\n", *letter, *(word+i));
            count++;
        }
    }
    printf("%d\n", count);
    // printf("it actually prints off and extra line, so I should do (sizeof(array)-1)");
    return 0;
}