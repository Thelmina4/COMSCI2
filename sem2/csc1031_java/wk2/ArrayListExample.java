// ArrayListExample.java
import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        // create and array list of strings
        ArrayList<String> names = new ArrayList<>();

        // add elements
        names.add("Thelma");
        names.add("John");
        names.add("Annie");

        // Access elements
        System.out.println("First name: " + names.get(0));

        // remove an element
        names.remove("Annie");

        // iterating through the ArrayList
        System.out.println("Remaining names: ");
        for (String name : names) {
            System.out.println(name);
        }
    }
}

// add(element) : Adds an element to the ArrayList.

// add(index, element) : Inserts an element at the specified index.

// remove(index) :  Removes the element at the specified index.

// remove(object) : Removes the first occurrence of the object.

// get(index): Retrieves the element at the specified index.

// size(): Returns the number of elements.

// clear(): Removes all elements.