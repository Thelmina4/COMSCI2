// package wk11;

// import javax.swing.Box;

class Box<T> {
    private T value;

    public void set(T value) {
        this.value = value;
    }

    public T get() {
        return value;
    }
}

public class Generic {
    public static void main(String[] args) {
        Box<String> stringBox = new Box<>();
        stringBox.set("Hello");
        String s = stringBox.get(); // No casting needed

        System.out.println(s);
    }

}
