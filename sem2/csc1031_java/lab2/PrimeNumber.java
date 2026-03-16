// PrimeNumber.java

// input:
// user to enter a positive integer

// requirements:
//  - Use loops to check whether a number is prime. Scanner
//  - Use conditionals (if) to determine divisibility.
//  - Use a counter to keep track of the total number of primes.

// output:
// Display the count of prime numbers between 1 and the entered number.
// between 1 and number: > 1 & < number

// plan:
//  - follow the Eratosthenes sieve
// primes are > 1 and are only divisible by themselves

import java.util.Scanner;

public class PrimeNumber {
    // global sieve
    static boolean[] isPrimeArray;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // System.out.println("Please enter a positive integer");
        // read the upper limit
        long limit = scanner.nextLong();

        // counter of prime number
        long cnt = 0;

        if (limit < 2) {
            System.out.println(0);
            return;
        }

        // create sieve (array index must be int)
        isPrimeArray = new boolean[(int) (limit + 1)];

        // assume all are prime initially
        for (int i = 2; i <= limit; i++) {
            isPrimeArray[i] = true;
        }

        // build the sieve
        for (int i = 2; (long) i * i <= limit; i++) {
            if (isPrimeArray[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrimeArray[j] = false;
                }
            }
        }

        long count = 0;
        for (int i = 2; i <= limit; i++) {
            if (isPrime(i)) {
                cnt++;
            }
        }

        System.out.println(cnt);
        // close the scanner
        scanner.close();
    }

    // Function to check if it is prime or not
    private static boolean isPrime(long num) {
        return isPrimeArray[(int) num];
    }
}