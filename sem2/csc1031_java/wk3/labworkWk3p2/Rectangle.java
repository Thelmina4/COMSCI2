
public class Rectangle {
    private int width;
    private int height;

    // default constructor
    public Rectangle() {
        this.width = 1;
        this.height = 1; // default dimensions
    }

    // constructor w 1 parameter
    public Rectangle(int size) {
        // it's a square!
        this.width = size;
        this.height = size;
    }

    public Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public String toString() {
        return "Rectangle{" +
                "width=" + width +
                ", height= " + height +
                "}";
    }
    public static void main(String[] args) {
        Rectangle defaultRectangle = new Rectangle();
        Rectangle square = new Rectangle(5);
        Rectangle customRectangle = new Rectangle(4, 8);

        System.out.println(defaultRectangle);
        System.out.println(square);
        System.out.println(customRectangle);

    }
}
