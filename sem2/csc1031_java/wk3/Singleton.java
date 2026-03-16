// Singleton.java
// The Singleton pattern is simple and doesn't require inheritance, interfaces, or abstraction.
// ● It solves the problem of ensuring there’s only one instance of a class globally.
// ● Where Is It Used?
// ○ Logging
// ○ Configuration settings
// ○ Managing database connections

class SingletonEg1 {
    private static SingletonEg1 instance;

    // private constructor to prevent instantiation
    private SingletonEg1() {}
    
    // Method to provide access to the single instance
    public static SingletonEg1 getInstance() {
        if (instance == null) {
            instance = new SingletonEg1();
        }
        return instance;
    }
    public void showMessage() {
        System.out.println("Hello from the Singleton ");
    }
}
public class Singleton {
    public static void main(String[] args) {
        SingletonEg1 s1 = SingletonEg1.getInstance();
        SingletonEg1 s2 = SingletonEg1.getInstance();

        System.out.println(s1 = s2); // true, both refer to the saame instance
        s1.showMessage();
    }
}

