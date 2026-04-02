
class Person {
    String name;

    Person(String name) {
        this.name = name;
    }
}
public class ShallowPerson {
    public static void main(String[] args) {
        Person original = new Person("Alice");
        Person shallowPerson = original; // shallow copy
        // As the original and the shallow copy with the same memory,
        // them changing the name of one, will change the name of the other
        shallowPerson.name = "Bob"; // modifies the shared object
        System.out.println(original.name);
    }
}

