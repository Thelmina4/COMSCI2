// implementation of all the helper functions here

#include "simpleshell.h"

// implemented functions
void syserr(char *msg)      // report error code and abort routine
{
    fprintf(stderr, "%s: %s", strerror(errno), msg);
    printf("\n");
}
// echo function 
// addition, might need to add a check to see if there is an open & close ""
void handle_echo(char **args) {
    if (args[1] == NULL) {
        printf("\n");
        // can't continue if not in while loop
        return; // break out of 'while' loop
    } 
    if (strcmp(args[1], "$PATH") == 0 && args[2] == NULL) {
        char *path = getenv("PATH");
        printf("%s\n", path ? path : "");
        return;
    } 
    // Take in the full line using simple while loop
    int i = 1; // Start at 1 to skip the word "echo"
    while (args[i] != NULL) {
        printf("%s", args[i]);
        // Add a space ONLY if there is another word coming
        if (args[i + 1] != NULL) {
            printf(" ");
        }
        i++;
    }
    printf("\n"); // Have to end in new line
}

void handle_cd(char **args) {
    // cd  - change the current default directory. 
    // If the argument is not present, report the current directory. 
    // If the directory does not exist an appropriate error should be reported. 
    // This command should also change the PWD environment variable.
    // If no argument: print current directory
    char cwd[512];
    if (args[1] == NULL) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd failed");
        }
        return;
    }   
    // Try to change directory
    if (chdir(args[1]) != 0) {
        perror("cd failed");
        return;
    }
    // Update PWD environment variable
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        setenv("PWD", cwd, 1);
    } else {
        perror("getcwd failed");
    }    
}

// handle the input of environ or env
void handle_env() {
    int i;
    // while loop each of the env variables
    for (i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    } 
}
// pause command
void handle_pause() {
    printf("Press Enter to continue...");
    fflush(stdout);
    // This loop clears out any existing characters
    //  and then waits for the next Enter
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char *make_prompt(char * last_dir, char *cwd) {
    // check if last dir exists & > 1
    if (last_dir != NULL && strlen(last_dir) > 1) {
        // move forward: /home -> home
        last_dir++; 
    } else {
        last_dir = cwd; // Fallback for the root directory "/"
    }
    return last_dir;
}

// author:  Thelma Clarke
// SID: 19746069
// I have read and understood the DCU Academic Integrity and Plagiarism Policy. 
// I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
