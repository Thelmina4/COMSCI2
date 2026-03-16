import java.util.ArrayList;
import java.util.List;

interface Vehicle {
    // Inside an interface, every method is implicitly abstract and public.
    //  You don't need to type them out.
    //  Writing abstract void start(); is like saying "a round circle"
    //  the "round" part is already implied!
    void start();
    void stop();
    }

class Car implements Vehicle {
    @Override
    public void start() {
        System.out.println("Car is starting...");
    }

    @Override
    public void stop() {
        System.out.println("Car is stopping...");
    }
}

class Bicycle implements Vehicle {
    @Override
    public void start() {
        System.out.println("Bicycle is starting...");
    }

    @Override
    public void stop() {
        System.out.println("Bicycle is stopping...");
    }
}


public class Vehicles {
    public static void main(String argv[]) {
        // store a Car (child) in a Vehicle (parent) varialbe
        Vehicle myCar = new Car();
        Vehicle myBike = new Bicycle();

        List<Vehicle> garage = new ArrayList<>();
        garage.add(myBike);
        garage.add(myCar);

        for (Vehicle v : garage) {
            v.start();
            v.stop();
        }
    }
}




