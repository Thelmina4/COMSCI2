# CSC1021 Operating Systems: customshell

## SimpleShell - Assignment 
### Thelma Clarke 
This assignment is worth 20% of your overall mark for CSC1021.

Supported Commands (Internal Commands) - Stage 1
The shell must support the following internal commands:

    **clr** - clear the screen (via clear command). :white_check_mark:

    **dir**  - list the contents of directory :white_check_mark:
    (via ls -al <directory>)

    **quit** - quit the shell :white_check_mark:

    **environ** - list all the environment strings
    The shell environment should contain shell= /simpleshell where /simpleshell is the full path for the shell executable (not a hardwired path back to your directory, but the one from which it was executed). :white_check_mark:

    **echo**  - echo  on the display followed by a new line (multiple spaces/tabs may be reduced to a single space) :white_check_mark:
     - might add loop to handle ""

    **cd**  - change the current default directory. If the argument is not present, report the current directory. If the directory does not exist an appropriate error should be reported. This command should also change the PWD environment variable. :white_check_mark:

    **help** - display a basic user manual using the ‘more’ filter.  

    **pause** - pause operation of the shell until 'Enter' is pressed

    Basic error handling and environment variable setup (i.e., setting shell to the executable’s full path).

    Batch Mode: Ability for the shell to process command lines from a file if a batch file is provided.

    Submit source code files (e.g., simpleshell.c, utility.c, simpleshell.h) with inline comments into the folder “Stage1”.

There are 3 folders (Stage1, Stage2, and Stage3), and within Stage1 and Stage2 there are **src, manual, bin directories.
Add your files relating to the manual/help command to the manual directory.
Your makefile should build the binary and place it in the bin directory.**

For Stage3, you should only add a file named video.txt containing the link to your video submission. This folder should only contain this single file. :white_check_mark:

Stage1/
|_ makefile
|_ bin - where the make file will generate simple shell
|_ manual - README.md, readme.txt for Stage1
|_ src - simpleshell.c, simpleshell.h, utility.c

