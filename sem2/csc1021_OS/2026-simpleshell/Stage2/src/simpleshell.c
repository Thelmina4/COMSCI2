/*
SimpleShell - Assignment
stage: 2
version: 1.0
date:    March 2026
author:  Thelma Clarke
SID: 19746069
I have read and understood the DCU Academic Integrity and Plagiarism Policy.
I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.

*/
/*********************************************************************
 This assignment is based off the lab assignments using the following as a basis
version: 1.0
date:    December 2003
author:  Ian G Graham
School of Information Technology
Griffith University, Gold Coast
ian.graham@griffith.edu.au
copyright (c) Ian G Graham, 2003. All rights reserved.
This code can be used for teaching purposes, but no warranty,
explicit or implicit, is provided.
*******************************************************************/
#include "simpleshell.h"

int main(int argc, char *argv[]) {

    // get the Shell ENV
    char shell_path[MAX_BUFFER];

    // argv[0] is the name of the program
    // realpath()
    // https://www.man7.org/linux/man-pages/man3/realpath.3.html
    if (realpath(argv[0], shell_path)) {
        setenv("SHELL", shell_path, 1);
    } else {
        perror("realpath failed");
    }

    // system("export LS_COLORS='di=0;36:fi=0;31'");
    // for batchmode in help
    char manual_path[MAX_BUFFER];

    if (realpath("./manual/readme.txt", manual_path) == NULL) {
        perror("manual path failed");
    }

    // char *colors = "rs=0:di=01;35:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=00:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.avif=01;35:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:*~=00;90:*#=00;90:*.bak=00;90:*.crdownload=00;90:*.dpkg-dist=00;90:*.dpkg-new=00;90:*.dpkg-old=00;90:*.dpkg-tmp=00;90:*.old=00;90:*.orig=00;90:*.part=00;90:*.rej=00;90:*.rpmnew=00;90:*.rpmorig=00;90:*.rpmsave=00;90:*.swp=00;90:*.tmp=00;90:*.ucf-dist=00;90:*.ucf-new=00;90:*.ucf-old=00;90:*.txt=01;43";
    // cleaner version
    char *colors = "di=01;35:ln=01;36:ex=01;32:";

    // setenv("LS_COLORS", getenv("LS_COLORS"), 1)
    setenv("LS_COLORS", colors, 1);

    /* get command line from input */
    char buf[MAX_BUFFER]; // line buffer
    char *args[MAX_ARGS]; // pointers to args strings
    char **arg;           // working pointer thru args

    // turn stdin to FILE *input
    FILE *input;
    // No arguments → interactive mode
    if (argc == 1) {
        input = stdin;
    }
    // One argument → batch mode
    else if (argc == 2) {
        input = fopen(argv[1], "r");
        if (!input) {
            perror("Error opening batch file");
            exit(1);
        }
    } else {
        fprintf(stderr, "Usage: %s [batchfile]\n", argv[0]);
        exit(1);
    }
    // clean up zombies from forking
    signal(SIGCHLD, SIG_IGN);
    /* Keep reading input until quit or eof of redirected input */
    while (1) {
        // Extend parsing: detect redirection tokens
        char *infile = NULL;        // redirect <
        char *outfile = NULL;       // redirect >
        int append = 0;             // redirect >> append to the file

        // only print a promp if getting from stdin
        if (input == stdin) {
            char cwd[512];
            char prompt_buffer[1024];
            char *prompt = "==> ";

            if (getcwd(cwd, sizeof(cwd)) == NULL) {
                // need to error check it
                perror("getcwd failed");
            } else {
                char *last_dir = strrchr(cwd, '/');
                last_dir = make_prompt(last_dir, cwd);

                snprintf(prompt_buffer, sizeof(prompt_buffer),
                         "%s%s", last_dir, prompt);

                fputs(prompt_buffer, stdout);
                fflush(stdout); // VERY IMPORTANT
            }
        }

        /* ---------- READ BATCH FILE ---------- */
        if (fgets(buf, MAX_BUFFER, input) == NULL) {
            break; // EOF
        }
        /* REMOVE \n AND \r  in input file */
        buf[strcspn(buf, "\r\n")] = '\0';

        /* ---------- TOKENISE ARGS ---------- */
        arg = args;
        *arg++ = strtok(buf, SEPARATORS);

        while ((*arg++ = strtok(NULL, SEPARATORS)))
            ;

        if (!args[0])
            continue;

        /* ---------- REDIRECTION ---------------- */
        for (int i = 0; args[i] != NULL; i++) {
            if (strcmp(args[i], "<") == 0) {
                // if (args[i + 1] == NULL) {
                //     fprintf(stderr, "Error: no output file\n");
                //     continue;
                // }
                infile = args[i + 1];
                args[i] = NULL;
                i++;
            }
            else if (strcmp(args[i], ">") == 0) {
                // what if there is nothing after
                // if (args[i + 1] == NULL) {
                //     fprintf(stderr, "Error: no output file\n");
                //     continue;
                // }
                outfile = args[i + 1];
                append = 0;
                args[i] = NULL;
                i++;
            }
            else if (strcmp(args[i], ">>") == 0) {
                // if (args[i + 1] == NULL) {
                //     fprintf(stderr, "Error: no output file\n");
                //     continue;
                // }
                outfile = args[i + 1];
                append = 1;
                args[i] = NULL;
                i++;
            }
        }
        /* ---------- & BACKGROUND EXECUTION & ---------- */
        //  "Other Commands".-> FORKING
        int background = 0;

        for (int i = 0; args[i] != NULL; i++) {
            if (strcmp(args[i], "&") == 0) {
                background = 1;
                args[i] = NULL; // remove & from args
                break;
            }
        }
        /* ---------- INTERNAL COMMANDS ---------- */

        if (!strcmp(args[0], "clear") || !strcmp(args[0], "clr")) {
            // "clear" command
            system("clear");
            continue;
        }
        // long list all the files in curr dir OR NAMED DIR
        if (!strcmp(args[0], "dir")) {
            // handle redirection
            // if outfile is not null, then it has redirect <
            FILE *saved = redirect_output(outfile, append);

            // "ls -al" command
            handle_dir(args);

            restore_output(saved);
            continue;
        }
        // quit the program
        if (!strcmp(args[0], "quit") || !strcmp(args[0], "q"))
            break;

        // list all the environment variables, changing SHELL="bin/bash" to the below
        // if (!strcmp(args[0], "environ") || !strcmp(args[0], "env")) {
        if (!strcmp(args[0], "environ")) {
            // handle redirection
            // before redirect function
            // if (outfile)
            // {
            //     // saved_stdout = stdout;

            //     if (append)
            //         freopen(outfile, "a", stdout);
            //     else
            //         freopen(outfile, "w", stdout);
            // }
            FILE *saved = redirect_output(outfile, append);

            // run through env function
            handle_env();
            // if (outfile)
            // {
            //     // flush it
            //     fflush(stdout);
            //     freopen("/dev/tty", "w", stdout);
            // }
            restore_output(saved);
            continue;
        }

        // echo command
        if (!strcmp(args[0], "echo")) {
            // handle redirection

            FILE *saved = redirect_output(outfile, append);

            handle_echo(args);
            restore_output(saved);

            continue; // Go back to the prompt
        }

        if (strcmp(args[0], "cd") == 0) {
            handle_cd(args);
            continue;
        }

        if (strcmp(args[0], "pause") == 0) {
            handle_pause();
            continue;
        }

        if (!strcmp(args[0], "help")) {
            // handle redirection & batch mode
            char *cmd = (input == stdin) ? "more" : "cat";

            // take the realpath and input here
            char *help_args[] = {cmd, manual_path, NULL};

            handle_fork(help_args, shell_path, infile, outfile, append, 0);

            continue;
        }

        // echo commanda little fun
        if (!strcmp(args[0], "marcel") && args[1] == NULL) {
            // a little hello from marcel the shell

            FILE *saved = redirect_output(outfile, append);

            marcel();
            restore_output(saved);

            continue; // Go back to the prompt
        }
        // printf("Command not recognised: %s\n", args[0]);

        // All other command line input is interpreted as program invocation which should be done by
        // the shell forking and execing* the programs as its own child processes.
        // input shell_path from above so I can change parent
        handle_fork(args, shell_path, infile, outfile, append, background);
        // printf("do we get this far? OUTSIDE\n");
    }
    if (input != stdin) {
        fclose(input);
    }
    return 0;
}

// implemented functions in utility.c
