// DefaultValuesExample.java

public class DefaultValuesExample {
    static int defaultInt;
    static double defaultDouble;
    static boolean defaultBoolean;
    static String defaultString;

    public static void main(String[] args) {
        System.out.println("Default Int  = " + defaultInt);
        System.out.println("Default Double = " + defaultDouble);
        System.out.println("Default Boolean = " + defaultBoolean);
        System.out.println("Default String = " + defaultString);
    }
}

// lab2$ javac DefaultValuesExample.java 
// lab2$ java DefaultValuesExample 
// Default Int  = 0
// Default Double = 0.0
// Default Boolean = false
// Default String = null