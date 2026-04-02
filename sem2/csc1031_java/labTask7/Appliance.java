// SmartHome.java
// requirements
// Only one class can be public

// Other classes must NOT be public

//     private int privateVar = 10;     // not inheritable
//     int defaultVar = 20;            // inherited (in the same package only)#
//     protected int protectedVar = 30;    // inherited (even in subclass outside pakage)
//     public int publicVar = 40;          // always inherited

// Do NOT use nested static classes

// Each class must be top-level

// import java.lang.reflect.Constructor;

// public class SmartHome {

// }
public class Appliance {
    // not inheritable
    private final int id;
    private String brand;
    private double powerConsumption;
    private boolean isOn;
    private static int nextID = 1;

    // constructors
    //Constructor must take:
    // All fields are primitives or String (which is immutable). So deep copy is irrelevant
    // String brand
    // double powerConsumption
    // Responsibilities:
    // Assign id = nextId
    // Increment nextId
    // Initialize brand
    // Initialize powerConsumption
    // Set isOn = false
    public Appliance(String brand, double powerConsumption) {        
        id = nextID++;
        isOn = false;
        setBrand(brand);
        setPowerConsumption(powerConsumption);
    }

    // Getters and setters for:
    // brand
    // powerConsumption
    // getters
    public String getBrand() {
        return brand;
    }

    public double getPowerConsumption() {
        return powerConsumption;
    }

    public int getId() {
        return id;
    }

    public boolean isOn() {
        return isOn;
    }

    // setters
    public void setBrand(String brandname) {
        if (brandname != null && !brandname.trim().isEmpty()) brand = brandname;
    }

    public void setPowerConsumption(double input) {
        if (input >= 0) {
            powerConsumption = input;
        } else {
            System.out.println("Invalid value. Must be positive.");
        }
    }

    public void turnOn() {
        if (!isOn) {
            isOn = true;
            System.out.println("Turning on " + brand + " appliance (ID: " + id + ")");
        } else {
            System.out.println(brand + "appliance (ID: " + id + ") is already ON");
        }
    }
    public void turnOff() {
        if (isOn) {
            isOn = false;
            System.out.println("Turning off " + brand + " appliance (ID: " + id + ")");
        } else {
            System.out.println(brand + "appliance (ID: " + id + ") is already OFF");
        } 
    }
}

class WashingMachine extends Appliance {
    private int drumSize;

    // constructor
    public WashingMachine(String brand, double powerConsumption, int drumSize){
        super(brand, powerConsumption);      // calling the parent
        setDrumSize(drumSize);
    }

    // getters
    public int getDrumSize() {
            return drumSize;    
    }

    // setters
    public void setDrumSize(int input) {
        if (input > 0) {
            drumSize = input;
        } else {
            System.out.println("Invalid value. Must be positive.");
        }
    }

    // washClothes() → Works ONLY if the machine is ON. If OFF: 
    // "Cannot wash clothes. The washing machine is OFF."
    public void washClothes() {
        if (!isOn()) {
            System.out.println("Cannot wash clothes. The washing machine is OFF.");
        }
    }
}

class Refrigerator extends Appliance {
    private double temperature;

    // constructor
    public Refrigerator(String brand, double powerConsumption, double temperature) {
        super(brand, powerConsumption);
        setTemperature(temperature);
    }

    // getters
    public double getTemperature() {
        return temperature;
    }

    // setters
    public void setTemperature(double input) {
        if (input > -5) temperature = input;
    }

    // addtitional methods
    public void coolItems() {
        if (isOn()) {
            System.out.println("Cooling items in " + getBrand() + " refrigerator at " + temperature + "°C (ID: " + getId() + ")");
        } else {
            System.out.println("Cannot cool items. The refrigerator is OFF.");
        }
    }
}

class SmartWashingMachine extends WashingMachine {
    private boolean hasWiFi;

    // constructor
    public SmartWashingMachine(String brand, double powerConsumption, int drumSize, boolean hasWiFi) {
        super(brand, powerConsumption, drumSize);
        hasWiFi = false;
    }
    // getters
    public boolean getWifi() {
        return hasWiFi;
    }
    // setters
    public void hasWiFi() {
        if (!hasWiFi && isOn()) {
            hasWiFi = true;
        }
    }

    public void connectToWiFi() {
        if (hasWiFi) {
            System.out.println("Smart Washing Machine (ID: "+getId()+") connected to WiFi.");
        } else {
            System.out.println("Cannot connect to WiFi. The machine is OFF.");
        }
    }
}
