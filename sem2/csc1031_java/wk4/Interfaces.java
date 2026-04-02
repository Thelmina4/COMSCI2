// Interfaces.java

interface Animal {
    void eat();
}

interface Walkable {
    void walk();
}

class Dog implements Animal, Walkable {
    public void eat() {
        System.out.println("I eat food"); 
    }
    public void walk() {
        System.out.println("I can walk too!");
    }
}

public class Interfaces {
    public static void main(String[] argv) {
        Dog pup = new Dog();
        pup.eat();
        pup.walk();
    }
}