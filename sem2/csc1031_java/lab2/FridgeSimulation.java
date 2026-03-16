// FridgeSimulation.java

public class FridgeSimulation {
    public static void main(String[] args) {
        Fridge fridge = new Fridge(5); // Initial balance: €5

        fridge.addFood("Milk", 3); // balance == 2
        fridge.addFood("Bread", 1); // balance == 1

        // Not enough money now
        // Error message should appear
        fridge.addFood("Eggs", 4);

        fridge.getFood("Milk");
        fridge.getFood("Bread");
        fridge.getFood("Juice"); // Error message should appear

        fridge.checkStatus();
    }
}