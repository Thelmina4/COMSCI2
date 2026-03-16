// Main.java

import java.util.ArrayList;
import java.util.List;

class Person2 {
    private String name;
    private List<String> hobbies;

    public Person2(String name, List<String> hobbies) {
        this.name = name;
        this.hobbies = new ArrayList<>(hobbies); // Deep copy of the list
    }

    @Override
    public String toString() {
        return "Person{name = '" + name + "', hobbies = " + hobbies + '}';
    }

    // make a deep copy
    public void addHobby(String hobby) {
        hobbies.add(hobby);
    }
}
public class Main {
    public static void main(String[] args) {
        List<String> hobbies = new ArrayList<>();
        hobbies.add("Reading");
        hobbies.add("Swimming");

        Person2 original = new Person2("Alice", hobbies);
        Person2 deepCopy = new Person2("Alice", hobbies); // Deep copy

        // Modify the original list
        hobbies.add("Gaming");

        // Modify one of the objects
        original.addHobby("Singing");

        System.out.println(original); // Person{name='Alice', hobbies=[Reading, Swimming, Singing]}
        System.out.println(deepCopy); // Person{name='Alice', hobbies=[Reading, Swimming]}
        System.out.println(hobbies);
    }
}