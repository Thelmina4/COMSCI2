// package labTask18;

abstract class Vehicle {
    public String brand;

    public Engine engine;

    public Vehicle(String brand, Engine engine) {
        this.brand = brand;
        this.engine = engine;
    }

    public abstract void startEngine();

}

class Car extends Vehicle {
    int numDoors;

    public Car(String brand, int numDoors, Engine engine) {
        super(brand, engine);
        this.numDoors = numDoors;
    }
    @Override
    public void startEngine() {
        System.out.println("Starting car with " + engine.getHorsepower() + " horsepowers");

    }
}

class Bike extends Vehicle {
    boolean hasCarrier;

    public Bike(String brand, boolean hasCarrier, Engine engine) {
        super(brand, engine);
        this.hasCarrier = hasCarrier;
    }
    @Override
    public void startEngine() {
        System.out.println("Starting bike with " + engine.getHorsepower() + " horsepowers");
    }
}

class ElectricCar extends Car {
    int batteryCapacity;
    public ElectricCar(String brand, int numDoor, int batteryCapacity, Engine engine) {
        super(brand, numDoor, engine);
        this.batteryCapacity = batteryCapacity;  
    }
    @Override
    public void startEngine() {
        System.out.println("Starting electric car silently with " + engine.getHorsepower() + " horsepowers");
    }
      

}

class Engine {
    int horsepower;

    public Engine(int horsepower) {
        this.horsepower = horsepower;
    }

    public int getHorsepower() {
        return horsepower;
    }
}

public class Vehicles2 {
    public static void main(String[] args) {
        Engine carEngine = new Engine(150);
        Car myCar = new Car("Toyota", 4, carEngine);
        myCar.startEngine();

        Engine bikeEngine = new Engine(20);
        Bike myBike = new Bike("Yamaha", true, bikeEngine);
        myBike.startEngine();

        Engine electricCarEngine = new Engine(200);
        ElectricCar tesla = new ElectricCar("Tesla", 4, 75, electricCarEngine);
        tesla.startEngine();
    }
}

// public class Main {

// }