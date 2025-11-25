#include<stdio.h>

int main() {
int matrix[3][3] = {
                   {10,20,30},
                   {40,50,60},
                   {70,80,90}
                 };

printf("matrix[1][2]: %d\n", matrix[1][2]); /* the normal way */
printf("*(matrix[1]+2): %d\n", *(matrix[1]+2)); /* pointer and array */
printf("*(*(matrix + 1)+2): %d\n", *(*(matrix + 1)+2)); /* using pointer only */
printf("*(*matrix + 5): %d\n", *(*matrix + 5)); /* using pointer only */
return 0;
}