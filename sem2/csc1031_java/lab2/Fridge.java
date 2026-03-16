// Fridge.java

// input:

// output:

// requirements:
// Fridge class that simulates a fridge
//  - Store a list of food items.
//  - Track the BALANCE of money available for purchasing food.
//  - Provide methods to interact with the fridge, such as
//      adding food,
//      retrieving food, and 
//      checking the fridge’s status.

// Attributes: 
//  - foodItems (List<String>): Stores the list of food items in the fridge.
//  - balance (int): Tracks the available money for purchasing food.

// Constructor:
//  - Fridge(int initialBalance)
//  - Initializes the fridge with the specified balance.
//  - If the initial state of the fridge is unacceptable 
//      (e.g., a negative balance), print Error and set balance to 0.

// Methods:
//  - void addFood(String item, int cost)
//      - Adds a food item AND deducts cost
//      - unacceptable state (e.g., insufficient balance, invalid inputs), print Error.
//  - void getFood(String item) 
//      - Removes a food item
//      - unacceptable state (e.g., the item does not exist, invalid inputs), print Error
//  - void checkStatus() 
//      - List of food items and the current balance

// plan: !!! Write the pseudocode first
// for Fridge class
//  - initialise an arrayList to add the items into
//  - initialise an int balance to 0 

// void addFood(String item, int cost)
// if cost < balance, add the food item, else print 'Error'


// void getFood(String item)
//  if the item is in the array, remove it, else print 'Error'

// checkStatus: if the array list isEmpty() print "none"
//      else println 'Food Items: ', iterate throu the list. and print 'Balance: €'

import java.util.ArrayList;
import java.util.List;

public class Fridge {

    // ATTRIBUTES

    // make list that we can add items to
    private List<String> items;
    // balance
    private int balance;

    // CONSTUCTOR

    public Fridge() {
        // constructor chaining, initialise balance to 0
        this(0);
    }

    public Fridge(int initialBalance) {
        if (initialBalance < 0) {
            System.out.println("Error");
            this.balance = 0;
        } else {
            this.balance = initialBalance;
        }
        this.items = new ArrayList<>();
    }

    // METHODS for the class

    public void addFood(String item, int cost) {

        if (item == null || cost < 0 || cost > balance) {
           System.out.println("Error");
           return;
        }
        balance -= cost;
        items.add(item);
        System.out.println("Item " + item + " has been added to the fridge.");
    }

    public void getFood(String item) {
        if (items.contains(item)) {
            System.out.println("Item " + item + " has been removed from the fridge.");
            items.remove(item);
        } else {
            System.out.println("Error");
        }
    }

    public void checkStatus() {
        // fisrt line
        System.out.println("Food items:");
        // base case is empty array
        if (items.size() == 0) {
            System.out.println("(none)");
        } else {
            // iterate through the array
            for (String item : items) {
                System.out.println(item);
            }
        }

        // balance either 0 or ++
        System.out.println("Balance: €" + balance);

    }

}
