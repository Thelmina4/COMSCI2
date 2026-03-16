#include<stdio.h>


// Add a permission (set a bit to 1)
void addPermission(int *perm, int flag) {
    // POINTERS
    // To change a variable inside a function, you must pass its address
    // Then the function can dereference the pointer and modify the original
    
    // OR sets the bit at position flag
    *perm |= (1 << flag);
}

// Check if a permission exists (is the bit = 1?)
int hasPermission(int perm, int flag) {
    // AND checks the bit at position flag
    return (perm & (1 << flag)) != 0;
}

// Remove a permission (clear a bit to 0)
void removePermission(int *perm, int flag) {
    // AND with NOT-mask clears the bit
    *perm &= ~(1 << flag);
}

int main(int argc, char *argv[]) {
    int perm = 0;

    // Add permissions
    addPermission(&perm, 0); // READ
    addPermission(&perm, 2); // EXECUTE

    printf("Permissions value: %d\n", perm);

    // Check permissions
    printf("Has READ?    %d\n", hasPermission(perm, 0)); // 1
    printf("Has WRITE?   %d\n", hasPermission(perm, 1)); // 0
    printf("Has EXECUTE? %d\n", hasPermission(perm, 2)); // 1

    // Remove EXECUTE
    removePermission(&perm, 2);

    printf("After removing EXECUTE, has EXECUTE? %d\n",
        hasPermission(perm, 2)); // 0
     

    return 0;

}