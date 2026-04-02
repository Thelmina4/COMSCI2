// ArrayExample.java

public class ArrayExample {
    public static void main(String[] args) {
        // declaration and initialisation
        int[] numbers = {1, 2, 3, 4, 5};

        // accessing elements
        System.out.println("First number: " + numbers[0]); // output = 1

        // modifying an element
        numbers[2] = 10;

        // Iterating through an array
        System.out.println("Array elements:");
        for (int number : numbers) {
            System.out.println(number);
        }
    }
}

// int[] arr = new int[5];
// Create an array of size 5.
// arr.length : Get the size of the array.
// arr[index] : Access or modify an element at a specific index.
// for loop : Iterate over the elements.