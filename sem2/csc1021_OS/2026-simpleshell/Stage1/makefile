# Thelma Clarke, A19746069 - Operating Systems Project 1
# CSC1021/simpleshell
FLAGS = -Wall
SRC = src/simpleshell.c src/utility.c src/simpleshell.h 
TARGET = bin/simpleshell

# simpleshell is in src
$(TARGET): $(SRC)
	mkdir -p bin
	gcc $(FLAGS) src/simpleshell.c src/utility.c -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

# I have read and understood the DCU Academic Integrity and Plagiarism Policy. 
# I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
