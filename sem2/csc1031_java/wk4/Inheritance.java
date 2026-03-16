class Grandparent {
    void grandparentMethod() {
        System.out.println("Grandparnet method");
    }
}
class Parent extends Grandparent{
    void show() {
        System.out.println("This is the parent class");
    }
}

class Child extends Parent {
    void display() {
        System.out.println("this is the child class");
    }
}
public class Inheritance {
    public static void main(String[] args) {
        Child kid = new Child();
        kid.show(); // inherited parent method
        kid.display();  // child
        kid.grandparentMethod();
    }
}

