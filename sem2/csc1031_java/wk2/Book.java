// Book.java

public class Book {
    // attributes
    private String title;
    private boolean isBorrowed;

    // Methods
    // constuctor
    public Book(String title) {
        this.title = title;
        this.isBorrowed = false;
    }

    // Getter
    public String getTitle() {
        return title;
    }

    // another getter
    public boolean isBorrowed() {
        return isBorrowed;
    }

    // Setter ... Kinda
    public void borrow() {
        if (!isBorrowed) {
            // if the book is false
            // set it to true
            isBorrowed = true;
            System.out.println("You borrowed \"" + title + "\".");
        } else {
            System.out.println("\"" + title + "\" is already borrowed.");
        }
    }

    public void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            System.out.println("You returned \"" + title + "\".");
        } else {
            System.out.println("\"" + title + "\" was not borrowed.");
        }
    }
}