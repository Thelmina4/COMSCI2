// SuperInheritance.java

class Parent1 {
    void display() {
        System.out.println("this is the parent");
    }
}
class Child1 extends Parent1 {
    void display() {
        super.display();    // calls the parent method
        System.out.println("This is the kid again.");
    }
}

public class SuperInheritance {
    public static void main(String[] args) {
        Child1 obj = new Child1();
        obj.display();
    }
}