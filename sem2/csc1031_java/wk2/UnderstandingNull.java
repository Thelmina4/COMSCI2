// UnderstandingNull.java

public class UnderstandingNull {
    public static void main(String[] args) {
        String name = null;
        System.out.println(name); // prints>> null

        if (name == null) {
            System.out.println("The name is not set for this variable");
        }
    }
}