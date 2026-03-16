public class FactorialDemo {
    public static void main(String[] args) {
        int number = 4;
        int result = factorial(number);
        System.out.println("The factorial of " + number + " is: " + result);
    }

    public static int factorial(int n) {
        // Breakpoint here!
        if (n <= 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
}