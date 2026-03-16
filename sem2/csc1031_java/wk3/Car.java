// jsut playing

public class Car {
    String brand;
    double price;

    // constructor
    public Car(String brand, double price) {
        this.brand = brand;
        this.price = price;
    }
    // overload constructor - static polymorphism
    public Car(Car other) {
        this.brand = other.brand;
    }

    // method to create a deep copy of the object
    public Car copyCar() {
        Car a = new Car(this.braand, this.price); // use constructor to copy fields
        return a; // return the new independent object
    }

    public static void main(String[] args) {
        // original car
        Car original = new Car("toyota", 30000.0);

        // create a deep copy using the copyCar method
        Car copied = original.copyCar();
}
}