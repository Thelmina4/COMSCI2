// NestedIfExample.java

public class NestedIfExample {
    public static void main(String[] args) {
        int number = 15;
        if (number > 0) {
            if (number % 2 == 0) {
                System.out.println("The number is positive and even");
            } else {
                System.out.println("The number is positive and odd");
            }
        } else {
            System.out.println("The number is negative");
        }

    }
}