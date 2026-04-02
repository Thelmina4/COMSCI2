interface Vehicle {
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

public class InterfaceTest {
    
}
