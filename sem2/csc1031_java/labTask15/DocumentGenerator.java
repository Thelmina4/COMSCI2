//  implement the Template Method Pattern, which defines
//  the skeleton of an algorithm in a base class while allowing
//  subclasses to override specific steps.

// You will create a document generation system that supports
//  three types of documents:
// Invoice
// Report
// Receipt

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

interface Reader {
    Scanner scanner = new Scanner(System.in);
}

abstract class Document implements Reader {
    // company name, date, document title
    // protected String name;
    // protected String date;
    // protected String title;
    protected List<String> content = new ArrayList<>();

    // Template method
    public final void generateDocument() {
        createHeader();
        createBody();
        createFooter();
        printDocument();
    }

    // COMMON FOR ALL DOCS

    // createHeader() // - Common for all document types (company name, date,
    // document title).
    public void createHeader() {
        // collect the company name and date.
        System.out.print("Enter company name: ");
        String companyName = scanner.nextLine();
        if (companyName.isEmpty())
            throw new IllegalArgumentException("Error: Company name cannot be empty.");

        System.out.print("Enter date (DD/MM/YYYY): ");
        String date = scanner.nextLine();
        if (date.isEmpty())
            throw new IllegalArgumentException("Date cannot be empty.");

        // Add lines to the document
        content.add("Company: " + companyName);
        content.add("Date: " + date);

    }

    // ABSTRACT -> DIFFERENT FOR EACH DOCUMENT
    // createBody() // - Varies depending on the document type (user input needed).
    abstract public void createBody();
    // abstract, meaning each subclass must define how it constructs the body.

    // createFooter()// - Includes document metadata (e.g., writer’s name, document
    // type).
    public void createFooter() {
        content.add("Prepared by: AutoDoc System");

    }

    // printDocument() //- Outputs the document (stored as an array of strings).
    public void printDocument() {
        // should iterate over the stored document lines and print them.
        // there should be a base case
        System.out.println("=== Printing Document ===");

        for (String line : content) {
            System.out.println(line);
        }
        System.out.println("=========================");

    }
}

class Invoice extends Document {
    // Company name (must not be empty).
    // Date (must not be empty).
    // Total amount (must be positive).

    // createBody() // - Varies depending on the document type (user input needed).
    public void createBody() {
        // Total amount
        double totalAmount;
        System.out.print("Enter total amount: ");

        try {
            totalAmount = Double.parseDouble(scanner.nextLine());
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Error: Total amount must be numeric.");
        }
        // totalAmount = scanner.nextDouble();
        if (totalAmount <= 0)
            throw new IllegalArgumentException("Error: Total amount must be positive.");

        content.add("Total Due: €" + totalAmount);

    }
    // abstract, meaning each subclass must define how it constructs the body.

    // printDocument() //- Outputs the document (stored as an array of strings).
    public void printDocument() {
        // should iterate over the stored document lines and print them.
        System.out.println("\n=== Printing Document ===");

        System.out.println("=== INVOICE ===");

        for (String line : content) {
            System.out.println(line);
        }
        System.out.println("Document Type: INVOICE");
        System.out.println("=========================");
    }
}

class Report extends Document {
    // Company name (must not be empty).
    // Date (must not be empty).
    // Report summary (must not be empty).
    public String summary;

    // createBody() // - Varies depending on the document type (user input needed).
    public void createBody() {
        String summary;
        // Report summary
        System.out.print("Enter report summary: ");
        summary = scanner.nextLine();

        if (summary.isEmpty()) {
            System.out.println("Warning: Summary is empty.");
        }
        content.add("Report Summary: " + summary);
    } // abstract, meaning each subclass must define how it constructs the body.

    // createFooter()// - Includes document metadata (e.g., writer’s name, document
    // type).
    public void createFooter() {
        // System.out.println("Reviewed by: Management Department");
        content.add("Reviewed by: Management Department");
    }

    // printDocument() //- Outputs the document (stored as an array of strings).
    public void printDocument() {
        // should iterate over the stored document lines and print them.
        System.out.println("\n=== Printing Document ===");

        System.out.println("=== REPORT ===");

        for (String line : content) {
            System.out.println(line);
        }
        // System.out.println("Reviewed by: Management Department");
        System.out.println("=========================");
    }
}

class Receipt extends Document {
    // Company name (must not be empty).
    // Date (must not be empty).
    // Amount paid (must be positive).
    // Number of items (must be positive).
  
    // createBody() // - Varies depending on the document type (user input needed).
    public void createBody() {
        // Amount paid
        double amountPaid;
        int itemsCount;

        // amount paid
        System.out.print("Enter amount paid: ");
        try {
            amountPaid = Double.parseDouble(scanner.nextLine());
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Error: Amount paid must be numeric.");
        }

        if (amountPaid <= 0)
            throw new IllegalArgumentException("Amount paid must be positive.");

        // Number of items
        System.out.print("Enter number of items: ");
        try {
            itemsCount = Integer.parseInt(scanner.nextLine());
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Items count must be a valid integer.");
        }

        if (itemsCount <= 0) {
            throw new IllegalArgumentException("Error: Items count must be positive.");
        }

        // Division safety
        if (itemsCount == 0) {
            throw new ArithmeticException("Cannot divide by zero.");
        }

        double pricePerItem = amountPaid / itemsCount;

        content.add("Total Paid: €" + amountPaid);
        content.add("Items Purchased: " + itemsCount);
        content.add("Price per Item: €" + pricePerItem);
    } // abstract, meaning each subclass must define how it constructs the body.

    // createFooter()// - Includes document metadata (e.g., writer’s name, document
    // type).

    // printDocument() //- Outputs the document (stored as an array of strings).
    public void printDocument() {
        // should iterate over the stored document lines and print them.
        System.out.println("\n=== Printing Document ===");
        System.out.println("=== RECEIPT ===");

        for (String line : content) {
            System.out.println(line);
        }
        System.out.println("Document Type: RECEIPT");
        System.out.println("=========================");
    }
}

public class DocumentGenerator implements Reader {
    public static void main(String[] args) {
        // Implement a console application (DocumentGenerator) that:
        // Accepts input from the user (e.g., company name, amount, etc.).
        // Uses the template method pattern to generate and print documents.
        // Handles exceptions properly.
        try {
            System.out.println("Choose document type: (INV) Invoice, (REP) Report, (REC) Receipt");
            String choice = scanner.nextLine().toUpperCase();
            Document document = null;
            switch (choice) {
                case "INV":
                    document = new Invoice();
                    break;
                case "REP":
                    document = new Report();
                    break;
                case "REC":
                    document = new Receipt();
                    break;

                default:
                    // This catches any string that isn't INV, REP, or REC
                    throw new IllegalArgumentException("Invalid choice. Exiting.");
            }
            // If we reach here, 'document' is guaranteed to be initialized
            document.generateDocument();
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            // Executoin stops here for this block
        } 
        // catch (Exception e) {
        //     // catch- all for other unexpected issues
        //     System.out.println("An unexpected error occured");
        // }
    }
}