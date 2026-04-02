// implementation of all the helper functions here

#include "simpleshell.h"

// implemented functions
void syserr(char *msg)      // report error code and abort routine
{
    fprintf(stderr, "%s: %s", strerror(errno), msg);
    printf("\n");
    // abort(errno); this line doesn't work, come back to it
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

// handle dir
void handle_dir(char **args) {
    // allocate the memory for the correct size
    char command[MAX_BUFFER];

    // format the string
    // The functions snprintf() and vsnprintf() write  at  most  size  
    //    bytes (including the terminating null byte ('\0')) to str.
    // system("export LS_COLORS='di=0;36:fi=0;31'");
    if (args[1] != NULL) {
        snprintf(command, sizeof(command), "ls -al %s --color=always", args[1]);
    } else {
        snprintf(command, sizeof(command), "ls -al --color=always");
    }    
    // print it to see what is output
    // printf("this is the command: %s\n", command);

    system(command);
}

void handle_fork(char **args, char *shell_path, char *infile, char *outfile, int append, int background) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    } else if (pid == 0) {
        // The child ps
        // set the parent env variable
        setenv("PARENT", shell_path, 1);
        
        // Handle redirection input
        if (infile) {
            // check for opening error
            if (!freopen(infile, "r", stdin)) {
                perror("input redirection failed");
                exit(EXIT_FAILURE);
            }
        }
        // Handle redirection output & errors
        if (outfile) {
            FILE *fp;
            if (append)
                fp = freopen(outfile, "a", stdout);
            else
                fp = freopen(outfile, "w", stdout);
                // make sure that it worked
            if (!fp) {
                perror("output redirect failed");
                exit(EXIT_FAILURE);
            }
        }
        
        // now execvp
        execvp(args[0], args);

        // If exec fails
        perror("exec failed");
        exit(EXIT_FAILURE);
    }
    else {
        // parent ps
        if (!background) {
            // then wait foreground
            waitpid(pid, &status, 0);
        } else {
            // background, so don't wait
            // test
            printf("[Background pid: %d]\n", pid);
        }
        
    }
    // printf("do we get this far? INSIDE\n");
}
// tidy up the if statement for internal commands
FILE *redirect_output(char *outfile, int append) {
    
    if (!outfile) return NULL;
    // make a dup of stdout as file
    // get the fileno, gives first availabe no
    int saved_fd = dup(fileno(stdout));
    // error check for dup
    if (saved_fd < 0) {
        perror("dup failed");
        return NULL;
    }
    FILE *saved = fdopen(saved_fd, "w");
    // error checking
    if (!saved) {
        perror("fdopen failed");
        close(saved_fd);
        // have to return
        return NULL;
    }
    // handle writing to and appending to 
    FILE *fp;
    if (append) {
        fp = freopen(outfile, "a", stdout);
    } else {
        fp = freopen(outfile, "w", stdout);
    }
    // make sure that it worked
    if (!fp) {
        perror("freopen failed");
        dup2(saved_fd, fileno(stdout));
        fclose(saved);
        return NULL;
    }
    return saved;
}

void restore_output(FILE *saved_stdout) {
    // If it's null return
    if (!saved_stdout) return;
    // else clear stdout
    fflush(stdout);
    // dup2(old file descriptor, newfd)
    dup2(fileno(saved_stdout), fileno(stdout));
    // close the file for the next run
    fclose(saved_stdout);
}

void marcel() {
    // I get the name of Marcel the shell from a cute video on youtube
    // https://youtu.be/VF9-sEbqDvU?si=IprP3iNaHwxbW9iC
    char *out = "Hello, my name is Marcel and I am a shell 𓂃๑ï";
    for (int i = 0; i < strlen(out); i++) {
        printf("%c", out[i]);
        fflush(stdout);
        usleep(100000);         // delay
    }
    // I should have put this into an array, but I just realised
    // how much time I spent getting the snail size right.
    // It is time to move on
    printf("\n");
    printf("           ,——----------——.\n");
    printf("          /  /    __    \\  \\\n");
    printf(" (•)(•)  |  |    |  |    |  |\n");
    printf("  \\\\ \\\\   \\______\\__/______/——-.__\n");
    printf("  (-______________________________\\\n");

}

// author:  Thelma Clarke
// SID: 19746069
// I have read and understood the DCU Academic Integrity and Plagiarism Policy. 
// I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
