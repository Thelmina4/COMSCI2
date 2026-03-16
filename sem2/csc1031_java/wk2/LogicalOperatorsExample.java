// LogicalOperatorsExample.java
// && AND
// || OR
// ! NOT
public class LogicalOperatorsExample {
    public static void main(String[] args) {
        int age = 25;
        boolean hasLicense = true;

        if (age >= 18 && hasLicense) {
            System.out.println("You are eligible to drive.");
        } else {
            System.out.println("You are not eligible to drive!");
        }
    }
}