class Personal {
    private String name;
    private int age;

    public Personal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return name + " " + age;
    }
}

public class Person {
    public static void main(String[] args) {
        Personal person = new Personal("Thelma", 23);
        System.out.println(person);
    }
}