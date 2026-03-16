class Parents {
    private int privateVar = 10;     // not inheritable
    int defaultVar = 20;            // inherited (in the same package only)#
    protected int protectedVar = 30;    // inherited (even in subclass outside pakage)
    public int publicVar = 40;          // always inherited
    void shows() {
        System.out.println("Parent here");
    }
    void display(){
        
    }
}

class Childs extends Parents {
    @Override
    void shows() {
        System.out.println("You are overriden! (mic drop)");
    }
    void display() {
        // System.out.println(privateVar); // Error: private NOT accesible
        System.out.println(defaultVar);     // Accessible (same package)
        System.out.println(protectedVar);   // accessible
        System.out.println(publicVar);      // accessible
    }
}

public class OverRiding {
    public static void main(String[] argv) {
        Parents obj = new Childs();     // UPCASTING
        obj.shows();                    // calls overridden method in child class
        obj.display();
    }
}
