// command_line.c

/*** You need to add the relevant includes. ***/
#include<stdio.h>
// #include<unistd.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
   int i;
   printf("argc = %d\n", argc);                  // print arg count
   for (i = 0; i < argc; i++)              // print args
      printf("argv[%d]: %s\n",i, argv[i]);
   exit(0);
}

// lab3$ gcc -o command command_line.c
// lab3$ ./command test args Foo 12
// argc = 5
// argv[0]: ./command
// argv[1]: test
// argv[2]: args
// argv[3]: Foo
// argv[4]: 12