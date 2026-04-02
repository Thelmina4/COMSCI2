// Member.java

import java.util.ArrayList;
import java.util.List;

public class Member {
    private String name;
    private List<Book> borrowedBooks;

    public Member(String name) {
        this.name = name;
        this.borrowedBooks = new ArrayList<>();
    }

    public void borrowBook(Book book) {
        if (!book.isBorrowed()) {
            book.borrow();
            borrowedBooks.add(book);
        } else {
            System.out.println("Sorry, " + name + ", \"" + book.getTitle() + "\" is unavailable.");
        }
    }

    public void returnBook(Book book) {
        if (borrowedBooks.contains(book)) {
            book.returnBook();
            borrowedBooks.remove(book);
        } else {
            System.out.println("You don't have \"" + book.getTitle() + "\" to return.");
        }
    }

    public void showBorrowedBooks() {
        System.out.println(name + "'s Borrowed Books:");
        for (Book book : borrowedBooks) {
            System.out.println("- " + book.getTitle());
        }
    }
}