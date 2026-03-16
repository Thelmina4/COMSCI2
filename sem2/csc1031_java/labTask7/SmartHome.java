// TestSmartHome.java

import java.util.ArrayList;
import java.util.List;

public class SmartHome {

    private String ownerName;
    private List<Appliance> appliances;

    public SmartHome(String ownerName, List<Appliance> appliances) {
        setName(ownerName);
        this.appliances = new ArrayList<>(appliances);
    }

    public SmartHome(String ownerName) {
        // Calls other constructor with an empty list
        this(ownerName, new ArrayList<>()); 
    }

    // make a deep copy
    // addAppliance(Appliance appliance)
    public void addAppliance(Appliance appliance) {
        appliances.add(appliance);
    }

    // removeAppliance(Appliance appliance)
    public void removeAppliance(Appliance appliance) {
        // no need to put in an if, it will return true if it exists
        appliances.remove(appliance);
    }

    // getter
    // int getTotalAppliancesInHome()
    public int getTotalAppliancesInHome() {
        // System.out.println(appliances.size());
        return appliances.size();
    }

    public String getOwnerName() {
        return ownerName;
    }

    // setter
    public void setName(String name) {
        if (name != null && !name.trim().isEmpty()) {
            this.ownerName = name;
        } else {
            this.ownerName = "Unknown";
        }
    }
    // void turnOnAllAppliances()
    public void turnOnAllAppliances() {
        for (int i = 0; i <  appliances.size(); i++) {
            appliances.get(i).turnOn();
        }
    }

    // void turnOffAllAppliances()
    public void turnOffAllAppliances() {
        for (int i = 0; i <  appliances.size(); i++) {
            appliances.get(i).turnOff();
        }
    }

    public static void main(String[] argv) {
        Appliance obj = new Appliance("phone", -80);
        obj.setPowerConsumption(55);
        System.out.println(obj.getPowerConsumption());
        System.out.println(obj.getBrand());
        // System.out.println(obj.getId());
        // SmartHome obj2 = new SmartHome("Iphone", 40);
        // System.out.println(obj2.getId());
        // System.out.println(obj2.isOn());

        // obj2.setBrand("car");
        // System.out.println(obj2.getBrand());

        // System.out.println(obj.isOn());
        // System.out.println(obj2.isOn());

        // obj.turnOn();
        // System.out.println(obj.isOn());
        // System.out.println(obj2.isOn());
        // obj.turnOff();
        // System.out.println(obj.isOn());

        WashingMachine wmachine = new WashingMachine("sdff", 30, 40);
        wmachine.washClothes();

        Refrigerator fridge = new Refrigerator("newfr", 34, -2);
        fridge.turnOn();
        fridge.coolItems();

        System.out.println("\n  *****TESTING WASHING MACHINE*****");
        SmartWashingMachine sWm = new SmartWashingMachine("Smart machine thels", 80, 5, false);
        // System.out.println(sWm.isOn());
        sWm.connectToWiFi();
        sWm.turnOn();

        System.out.println("\n  *****END OF TESTING WASHING MACHINE*****");

        List<Appliance> list = new ArrayList<>();
        SmartHome home = new SmartHome("thelmina", list);
        home.addAppliance(sWm);
        home.addAppliance(wmachine);
        System.out.println(home.getTotalAppliancesInHome());
        home.removeAppliance(wmachine);
        System.out.println(home.getTotalAppliancesInHome());
    }
}

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
class Appliance {
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
        if (input > 0) {
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
            System.out.println(brand + " appliance (ID: " + id + ") is already OFF");
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
        } else {
            System.out.println("Washing clothes in a " + getBrand() +" washing machine");
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
        temperature = input;
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
        this.hasWiFi = hasWiFi;
    }
    // getters
    public boolean hasWiFi() {
        return hasWiFi;
    }
    // setters
    public void connectToWiFi() {
        if (isOn()) {
            this.hasWiFi = true;
            System.out.println("Smart Washing Machine (ID: "+ getId() +") connected to WiFi.");
        } else {
            System.out.println("Cannot connect to WiFi. The machine is OFF.");
        }
    }
}
