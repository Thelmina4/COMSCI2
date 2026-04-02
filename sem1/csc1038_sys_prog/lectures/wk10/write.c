#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    char *filename = "myname.txt";
    FILE *pfile = NULL;
    pfile = fopen(filename, "w");
    if (!pfile) {
        printf("failed to open");
    
    }
    fprintf(pfile,"%s", argv[1]);
    fclose(pfile);
    return 0;
}