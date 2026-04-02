// lab3-find-longest-word.c

// ise the indeces
// find where ther is no char and tjen the word is that len. 
// if one len is > then the last len then the stored index
// for the start of the word is that & the last index is the end of that word.
// in the end printf the index of the string from start to finish
#include<stdio.h> // input output
#include<string.h> // dealing with strings
#include<ctype.h> // booleans

// find the ascii value
// int asciiValue(char k[]);

int main(int argc, char* argv[]) {

    // define my variables
    char* line = argv[1];
    // printf("%s\n", line);

    int len_line = strlen(line);
    // printf("%d\n", len_line);

    int max_len = 0;
    int curr_len = 0;
    int start = 0;
    int curr_start = 0; 

    // for loop to wrap it all
    for (int i = 0; i <= len_line; i++){
        // find the first alpha
        if (isalpha(line[i])){
            // if it's an alpha, then start the counter
            if (curr_len == 0){
                curr_start = i;
            }
            curr_len++;
        }
        // if it's not an alpha then word end
        else {
            if (curr_len > max_len){
                max_len = curr_len;
                start = curr_start; 
            }
            curr_len = 0;
        }
    }
    // printf from the index until the len on max len
    for (int j = 0; j < max_len; j++){
        printf("%c", line[start + j]);
    }
    printf("\n");
    return 0;
}

