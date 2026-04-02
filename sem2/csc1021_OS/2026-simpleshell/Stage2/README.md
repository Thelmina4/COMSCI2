# TO-DO-LIST

on top of the stuff for stage 1

All other command line input is interpreted as program invocation which should be done by the shell forking and execing* the programs as its own child processes. 

The programs should be executed with an environment that contains the entry: 
parent= /simpleshell where /simpleshell is as described in the paragraph above.
* see man execv
<!--    https://linux.die.net/man/3/execv
        The exec() family of functions replaces the current process image with a new process image.

        The execlp(), execvp(), and execvpe() functions duplicate the actions of the shell in searching for an executable file if the specified filename does not contain a slash (/) character. The file is sought in the colon-separated list of directory pathnames specified in the PATH environment variable
        
        #include <unistd.h> 
        execl, execlp, execle, execv, execvp, execvpe - execute a file -->

## I/O Redirection - Stage 2
The shell must support i/o-redirection on either or both stdin and/or stdout. i.e. the command line:

programname arg1 arg2 < inputfile > outputfile

will execute the program programname with arguments arg1 and arg2, the stdin FILE stream replaced by inputfile and the stdout FILE stream replaced by outputfile.

stdout redirection should also be possible for the internal commands: dir, environ, echo, and help.

With output redirection, if the redirection character is > then the outputfile is created if it does not exist and truncated if it does. If the redirection token is >> then outputfile is created if it does not exist and appended to if it does.

## Background Execution - Stage 2
The shell must support background execution of programs. This does not need to be implemented for internal commands but it should be implemented for "Other Commands". An ampersand , or & character, at the end of the command line indicates that the shell should return to the command line prompt immediately after launching that program whilst it continues to run in the background.

Miscellaneous
The command line prompt must contain the pathname of the current directory. Note: you can assume that all command line arguments including the redirection symbols, <, > and >> and the background execution symbol, & will be delimited from other command line arguments by white space - one or more spaces and/or tabs (see the command line above). We should just have to type make to build your shell. There should be evidence in your code that you have attempted to handle errors. For example, if using fopen, freopen, etc you should check the return status and indicate if an error has occurred, and take appropriate action. 

## Stage 2 (45 marks)  - deadline to have deliverables in your repository: 22nd March 2026 23:59.

This stage represents getting more advanced functionality working. 

Extend the code base you developed in Stage 1 to include the following functionality:

> External Commands: Forking and execing for external command execution, with the environment variable parent set accordingly.

> Background Execution: Support for background process execution using the & symbol.

> I/O Redirection: Implementation of input (<) and output (>, >>) redirection for both internal and external commands.

Submit source code files (e.g., simpleshell.c, utility.c, simpleshell.h) with inline comments into the folder “Stage2”.

Note: your Stage 2 delivery must retain the functionality you developed in Stage 1 i.e. Stage 2 builds upon what was developed in Stage 1. 

External command functionality (10 marks)
I/O redirection (15 marks)
Background execution (15 marks)
A extended readme file (5 marks) - see “user manual” section for requirements for Stage 2.

## Marking Criteria

Stage 2:

External command functionality (10 marks)

I/O redirection (15 marks)

Background execution (15 marks)

A extended readme file (from Stage 1) that explains also explains how i/o redirection works in your simpleshell, the program environment (like environment variables), and background program execution (background vs foreground execution) (5 marks)