// WhileLoopExample.java

import java.util.Scanner;

public class WhileLoopExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int sum = 0;
        int number;

        System.out.println("Enter numbers to sum ( 0 to stop): ");
        while ((number = scanner.nextInt()) != 0) {
            sum += number;
        }
        System.out.println("Total sum : " + sum);
    }
}