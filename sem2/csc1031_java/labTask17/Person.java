// package labTask17;

import java.lang.String;
import java.lang.Integer;

interface SpecialFunctionality {
    void fire();
}

class Worker extends Person implements SpecialFunctionality {
    
    public String workerID;

    public Worker(String name, int age, String address, String workerID) {
        super(name, age, address);
        this.workerID = workerID;
    }
    public void fire() {
        this.address = "Fired";
        System.out.println("Worker " + workerID + " has been fired!");

    }
    // public void updateWorkerInfo(Object input) {
    //     if (input instanceof String address) {
    //         if (address != null && !address.trim().isEmpty()) {this.address = address;}
    //         this.address = address;
    //     } else if (input instanceof Integer age) {
    //         this.age = age;
    //     }
         
    // }

    // Method Overloading
    // Handles String input
    public void updateWorkerInfo(String address) {
        if (address != null && !address.trim().isEmpty()) {
            this.address = address;
        }
    }

    // Handles int input
    public void updateWorkerInfo(int age) {
        this.age = age;
    }
}

public class Person {
    String name;
    int age;
    String address;

    public Person(String name, int age, String address) {
        System.out.println("Person constructor");
        this.name = name;
        this.age = age;
        this.address = address;
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
    }
}

// public class Main {
//     public static void main(String[] args) {
//         Worker worker = new Worker("John", 30, "123 Main St", "W123");
//         worker.displayInfo();

//         worker.updateWorkerInfo("456 Elm St");
//         worker.displayInfo();

//         worker.updateWorkerInfo(35);
//         worker.displayInfo();

//         worker.fire();
//         worker.displayInfo();
//     }
// }