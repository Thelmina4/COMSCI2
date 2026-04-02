// PublicPrivateClasses.java

// Book.java
// Member.java

public class PublicPrivateClasses {
    public static void main(String[] args) {
        // Create books
        Book book1 = new Book("1984");
        Book book2 = new Book("To Kill a Mockingbird");
        Book book3 = new Book("The Great Gatsby");

        // Create a member
        Member member = new Member("Alice");

        // Borrow books
        member.borrowBook(book1);
        member.borrowBook(book2);

        // Show borrowed books
        member.showBorrowedBooks();

        // Return a book
        member.returnBook(book1);

        // Show borrowed books again
        member.showBorrowedBooks();

        // Try borrowing an already borrowed book
        Member anotherMember = new Member("Bob");
        anotherMember.borrowBook(book2);
    }
}