#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
   char *name = malloc(220);
   printf("Whaats your name\n");
   return 0;
}

// strace ./simple.c