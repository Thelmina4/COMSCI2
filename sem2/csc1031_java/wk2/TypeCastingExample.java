// TypeCastingExample.java

public class TypeCastingExample {
    public static void main(String[] args) {
        //    Example: int → long, float → double

        // implicit casting
        int num = 10;
        double converted = num; // int to double
        System.out.println("Implicit casting: " + converted);

        // explicit casting
        double pi = 3.14159;
        int truncated = (int) pi; // double to int
        System.out.println("Explicit casting: " + truncated);
    }
}
// lab2$ java TypeCastingExample 
// Implicit casting: 10.0
// Explicit casting: 3