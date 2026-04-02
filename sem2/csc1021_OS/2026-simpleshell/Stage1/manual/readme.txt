---------------------------------------------------------------------------
|                     SimpleShell User Manual                             |
---------------------------------------------------------------------------

NAME
    SimpleShell -  This is a basic UNIX like shell.

DESCRIPTION
    SimpleShell is a basic command line interpreter 
    that accepts user command either interactively from
    a user or from a in batch mode from a batch file.

    Compile shell:
        make

    Run shell:
        make run

    Interactive mode:
        ./bin/simpleshell

    Batch mode:
        ./bin/simpleshell [batchfile]

    Remove ./bin/simpleshell:
        make clean



NOTES
    Command names are case-senstive. 

INTERNAL COMMANDS
-----------------

cd [directory]
    Change the working directory of the shell.
    If no directory is specified, then the current directory is output.
    If the directory does not exist, an error is output.
    If the current directory command is successful the PWD environment
    is updated accordingly.

    EXAMPLES
        Change to the parent directory of the working directory
            cd ..

        Change to the directory bin which is a sister directory
        of the current working directory 
            cd ../bin

clr | clear
    Clears the terminal using the system "clear" command.

dir
    Long lists the files of the current directory
    using the system "ls -al" command
    -a     do not ignore entries starting with .
    -l     use a long listing format

environ | env
    Displays all environment variables.
    The environment includes:
        SHELL = full path of the executable simpleshell
        PWD = the current working directory 

echo [string]
    displays a line of text followed by a new line
    If echo is the only argument a new line is output
    If echo is followed by multiple arguments separated
    by tabs or spaces, they are reduced to a single spaces

    EXAMPLES
        Output a newline only
            echo

        Output text followed by a newline
            echo [string] \t [string]

        Output a list of directories thaat are searches anytime 
        a command is run
            echo $PATH

help
    Displays this manual using the 'more' filter.

    Navigation in more:
        Space  - Next page
        Enter  - Next line
        q      - Quit manual

pause
    Pauses shell execution until the Enter key is pressed.

quit | q
    Exits the shell.
