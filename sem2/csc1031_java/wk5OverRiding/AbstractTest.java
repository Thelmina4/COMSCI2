// Abtract is like a blue print that doesn't have content
//  but forces the children of it to create to implement them 

abstract class AbstractAnimal {
    String name;

    AbstractAnimal(String name) {
        this.name = name;
    }

    abstract void makeSound();  // Abract method (no implementation)
    
    void sleep() {              // concrete method
        System.out.println(name + " is sleeping.");
    }
}

class ConcreteDog extends AbstractAnimal{
    ConcreteDog(String name) {
        super(name);
    }

    @Override
    void makeSound() {
        // 
        System.out.println(name + "Barks");
    }
}
public class AbstractTest {
    ConcreteDog aa = new ConcreteDog("Bryan");

}

abstract class Shape {
    // It provides a level of access control that allows access
    //  within the same package and by subclasses,
    //  even if they are in different packages.

    // A protected String color field.
    protected String color;

    // A constructor to initialize color.
    Shape(String color){
        this.color = color;
    }

    // An abstract method double getArea().
    abstract double getArea();      // Abract method (no implementation)

    // A concrete method void displayColor() that prints "Shape color: <color>".
    public void displayColor() {
        System.out.println("Shape color: " + color);
    }
}
// Create two subclasses: Circle, Rectangle

class Circle extends Shape {
    private double radius;

    Circle(String color, double radius) {
        super(color);
        this.radius = radius;
    }
    @Override
    double getArea() {
        return 3.14 * radius * radius;
    }
}

class Rectangle extends Shape {
    private double width;
    private double height;

    Rectangle(String color, double width, double height) {
        super(color);
        this.width = width;
        this.height = height;
    }

    @Override
    double getArea() {
        return width * height;
    }
}


