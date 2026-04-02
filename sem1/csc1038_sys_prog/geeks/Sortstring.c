Sort string of characters
Last Updated : 02 May, 2025
Given a string of lowercase characters from 'a' - 'z'. We need to write a program to print the characters of this string in sorted order.

Examples: 

Input : "dcab" 
Output : "abcd"

Input : "geeksforgeeks"
Output : "eeeefggkkorss"

Try it on GfG Practice
redirect icon
Naive Approach - O(n Log n) Time
A simple approach is to use sorting algorithms like quick sort or merge sort and sort the input string and print it. 




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
​
// comparison function for qsort
int compare(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}
​
// function to print string in sorted order
void sortString(char *str)
{
    int n = strlen(str);
    qsort(str, n, sizeof(char), compare);
    printf("%s", str);
}
​
// Driver program to test above function
int main()
{
    char s[] = "geeksforgeeks";
    sortString(s);
    return 0;
}

Output
eeeefggkkorss


Efficient Approach - O(n) Time
An efficient approach will be to observe first that there can be a total of 26 unique characters only. So, we can store the count of occurrences of all the characters from 'a' to 'z' in a hashed array. The first index of the hashed array will represent character 'a', second will represent 'b' and so on. Finally, we will simply traverse the hashed array and print the characters from 'a' to 'z' the number of times they occurred in input string.

Below is the implementation of above idea: 




#include <stdio.h>
#include <string.h>
​
#define MAX_CHAR 26
​
// Function to print string in sorted order
void sortString(char s[]) {
    int charCount[MAX_CHAR] = {0};
    
    // Traverse the string and count characters
    for (int i = 0; i < strlen(s); i++) {
        charCount[s[i] - 'a']++;
    }
    
    // Traverse the count array and print characters
    for (int i = 0; i < MAX_CHAR; i++) {
        for (int j = 0; j < charCount[i]; j++) {
            printf("%c", 'a' + i);
        }
    }
}
​
int main() {
    char s[] = "geeksforgeeks";    
    sortString(s);    
    return 0;
}

Output
eeeefggkkorss