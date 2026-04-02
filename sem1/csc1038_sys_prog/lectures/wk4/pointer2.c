#include <stdio.h>

int main (void)
{

char letter = 'A';
char *pletter;

pletter = &letter;
printf ("The address of the letter variable is: %p\n\nThe value stored in letter is: %d\n\nThe actual letter is: %c\n\n",&letter,letter,letter);
// letter +=1;
// letter +="d";       // this doesn't work 
// *pletter +=1;
// pletter +=1;         // don't use this as it changes the address of the pointer, resulting in possibly garbled mess coming out
printf("letterPTR points at memory address: %p\n\nThe actual data it has access to is: %c\n\n",pletter,*pletter);
return (0);
}