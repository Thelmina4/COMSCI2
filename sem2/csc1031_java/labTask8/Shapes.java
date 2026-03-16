import static java.lang.Math.*;

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

    public Circle(String color, double radius) {
        super(color);
        this.radius = radius;
    }
    @Override
    double getArea() {
        if (radius > 0 ) {
            return Math.PI * radius * radius;
        }
        return 0.0;
    }
}

class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle(String color, double width, double height) {
        super(color);
        this.width = width;
        this.height = height;
    }

    @Override
    double getArea() {
        if ( width > 0 && height > 0) {
            return width * height;
        }
        return 0.0;
    }
}
