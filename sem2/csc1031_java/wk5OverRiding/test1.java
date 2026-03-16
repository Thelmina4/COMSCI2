// Object[] arr = new Object[5];
// arr[0] = "String";
// arr[1] = 42;;
// arr[2] = 3.14;
// arr[3] = new int[] 3;

class Animal {
    public void makesound() {
        System.out.println("Animal Sounds! Rar!!!");
    }
}

class Dog extends Animal {
    // @Override
    public void makesound() {
        System.out.println("Bark bark.");
    }
    public void eats() {
        System.out.println("Dog eat");
    }
}

class Employee {
    void work() {
        System.out.println("Employee is workin' it!");
    }
}

class Manager extends Employee {
    @Override
    void work() {
        super.work();   // call the parent class method
        System.out.println(" And managing the team.");
    }
}


public class test1 {
    public static void main(String[] args) {
        Animal a = new Dog();
        a.makesound();

        // the variable cannot eat as it is of type ANIMAL
        // a.eats();

        // can't declare a variable of type Dog using Animal
        // Dog b = new Animal();

        Dog c = new Dog();
        c.eats();

        Animal d = new Animal();
        d.makesound();

        Manager man = new Manager();
        man.work();
    }
}