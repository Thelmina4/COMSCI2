// Task 1: Break it on purpose (public fields)
// 1) Temporarily change `inkLevel` in `InkCartridge` to `public`.
// 2) In `main`, set it to `-50` using `cart.inkLevel = -50;` line
// 3) Run the program and observe the “impossible” behavior.
// 4) Change it back to `private`.
// Task 2: Add validation to Document
// Currently Document silently converts invalid pages to 1. Improve it:

// 1) If `pages <= 0`, set title to `"INVALID DOCUMENT"` and pages to `1`.
// Task 3: Safe cartridge replacement
// Add method boolean replaceCartridge(InkCartridge newCartridge) to Printer:

// 1)If `newCartridge` is `null`, return `false`.
// 2)Otherwise install it and return `true`.
// Test in main with a null cartridge and a real cartridge.

// Task 4: Print “partially” (challenge)
// Currently, printer prints either 0 pages or all pages. Change print(doc) so that:

// 1) If there is not enough ink for the whole document, it prints as many pages as possible.
// 2) Ink becomes 0 after that.
// 3) Returns the number of pages printed.
// 4) Keep the same ink rule: 1 page = 2% ink.

public class PrinterFullCode {
    public static void main(String[] args) {

        // Create a document (independent object)
        Document doc = new Document("CSC1031 Handout", 12);

        // Create a cartridge (independent object)
        InkCartridge cart = new InkCartridge("HP-301", 40);
        // InkCartridge cart1 = new InkCartridge();
        // InkCartridge cart2 = new InkCartridge("thelma", 40);

        // Create a printer (printer owns its PrinterConfig internally)
        Printer printer = new Printer(
                "LaserFox",
                "Misha",
                "DCU-WiFi",
                "1234-very-secret",
                "v1.0.0"
        );

        // Install cartridge (aggregation)
        printer.installCartridge(cart);

        // Printer uses the document (association)
        int printedPages = printer.print(doc);

        System.out.println("Printer brand: " + printer.getBrand());
        System.out.println("Owner: " + printer.getConfig().getOwnerName());
        System.out.println("WiFi: " + printer.getConfig().getWifiName());
        System.out.println("Firmware: " + printer.getConfig().getFirmwareVersion());
        System.out.println("Printed pages: " + printedPages);

        System.out.println("Ink after printing: " + printer.getCartridge().getInkLevel() + "%");

        // Remove cartridge (cartridge continues to exist)
        InkCartridge removed = printer.removeCartridge();
        System.out.println("Removed cartridge model: " + removed.getModel());

        // Try printing without cartridge
        int printed = printer.print(new Document("Another doc", 3));
        System.out.println("Printed pages without cartridge: " + printed);

        // Cartridge still exists and can be re-installed
        printer.installCartridge(removed);
        printer.print(new Document("Short note", 2));

        System.out.println("Ink at the end: " + printer.getCartridge().getInkLevel() + "%");

        // Update config (still the same config object owned by the printer)
        printer.getConfig().setFirmwareVersion("v1.0.1");
        System.out.println("Firmware after update: " + printer.getConfig().getFirmwareVersion());

        // tests for replaceCartridge
        // make sure that there is no cartridge to start w
        removed = printer.removeCartridge();
        // 1. test w null
        boolean nullResult = printer.replaceCartridge(null);
        System.out.println("\nReplace cartridge with \"null\" input: " + nullResult);
        System.out.println("Cartridge after replaced w null cartridge: " + printer.getCartridge());

        // 2. Test replacing with a real Cartridge
        // tesing larger than pages
        // InkCartridge newCart = new InkCartridge("ThelmaCart", 80);
        // testing == pages
        // InkCartridge newCart = new InkCartridge("ThelmaCart", 10);
        // testing < pages
        // InkCartridge newCart = new InkCartridge("ThelmaCart", 4);
        // testing odd input
        InkCartridge newCart = new InkCartridge("ThelmaCart", 3);
        boolean realResult = printer.replaceCartridge(newCart);
        System.out.println("\nReplace w real cartridge: " + realResult);
        System.out.println("Current cartridge model: " + printer.getCartridge().getModel());
        System.out.println("Curr cartridge ink level: " + printer.getCartridge().getInkLevel() + "%");

        // Tests for partial print 
        // above I input inkCartridge w 80% lavel, 40 pages to print
        System.out.println("\nNumber of pages printed: " + printer.partially(new Document("tester", 5)));
        System.out.println("remaining ink in the cartridge: " + printer.getCartridge().getInkLevel() + "%");
    }
}

// -------------------- Document --------------------
class Document {
    private String title;
    private int pages;

    //Constructor - a method that creates an instance
    public Document(String dcument_title, int document_pages) {
        if (pages <= 0) {
            title = "INVALID DOCUMENT";
            //safe default value
            pages = 1;
        }
        title = dcument_title;
        pages = document_pages;
    }

    // Getters to access the document
    public String getTitle() {
        return title;
    }

    public int getPages() {
        return pages;
    }
}

// -------------------- InkCartridge --------------------
class InkCartridge {
    private String model;
    private int inkLevel; // 0..100

    // Constructor
    public InkCartridge(String model_name, int inkLevel) {
        model = model_name;
        setInkLevel(inkLevel); // validation in one place
    }

    //Getters
    public String getModel() {
        return model;
    }

    public int getInkLevel() {
        return inkLevel;
    }

    //Setters
    // Setter exists because ink changes over time and we must validate it.
    public void setInkLevel(int newLevel) {
        if (newLevel < 0) newLevel = 0;
        if (newLevel > 100) newLevel = 100;
        inkLevel = newLevel;
    }

    // Simple rule: 1 page = 2% ink
    public boolean hasEnoughInkFor(int pages) {
        int needed = pages * 2;
        return inkLevel >= needed;
    }

    public void consumeInkFor(int pages) {
        int needed = pages * 2;
        setInkLevel(inkLevel - needed);
    }
}

// -------------------- PrinterConfig --------------------
class PrinterConfig {
    private String ownerName;
    private String wifiName;
    private String wifiPassword;
    private String firmwareVersion;

    //Construtor
    public PrinterConfig(String owner_Name, String wifi_Name, String wifi_Password, String firmware_Version) {
        ownerName = owner_Name;
        wifiName = wifi_Name;
        wifiPassword = wifi_Password;
        firmwareVersion = firmware_Version;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String Name) {
        if (Name == null || Name.trim().isEmpty())
            return;
        ownerName = Name;
    }

    public String getWifiName() {
        return wifiName;
    }

    public void setWifiName(String name) {
        if (name == null || name.trim().isEmpty()) return;
        wifiName = name;
    }

    public String getWifiPassword() {
        return wifiPassword;
    }

    public void setWifiPassword(String Password) {
        if (Password == null || Password.trim().isEmpty()) return;
        wifiPassword = Password;
    }

    public String getFirmwareVersion() {
        return firmwareVersion;
    }

    public void setFirmwareVersion(String  Version) {
        if (Version == null || Version.trim().isEmpty()) return;
        firmwareVersion = Version;
    }
}

// -------------------- Printer --------------------
class Printer {
    private String brand;

    // Aggregation (weak has-a): can be installed/removed
    private InkCartridge cartridge;

    // Composition (strong has-a): owned internal component
    private PrinterConfig config;

    public Printer(String printer_brand, String ownerName, String wifiName, String wifiPassword, String firmwareVersion) {
        brand = printer_brand;

        // Created internally -> composition
        // We call PrinterConfig constructor inside this class
        // PrinterConfig object will be destroyed once Printer is gone
        config = new PrinterConfig(ownerName, wifiName, wifiPassword, firmwareVersion);
    }

    public String getBrand() {
        return brand;
    }

    public InkCartridge getCartridge() {
        return cartridge;
    }

    public boolean hasCartridge() {
        return cartridge != null;
    }

    public void installCartridge(InkCartridge new_cartridge) {
        if (new_cartridge == null) return;
        cartridge = new_cartridge;
    }

    public InkCartridge removeCartridge() {
        InkCartridge tmp = cartridge; //save for later
        cartridge = null; //remove from printer
        return tmp; //return to "outside" of printer world
    }

    public boolean replaceCartridge(InkCartridge new_Cartridge) {
        if (new_Cartridge == null) {
            return false;
        } else {
            installCartridge(new_Cartridge);
            return true;
        }
    }

    // Access to config (read-only object reference, but values can be changed via setters)
    public PrinterConfig getConfig() {
        return config;
    }

    // Printer uses Document (association)
    public int print(Document doc) {
        if (doc == null) return 0;
        if (cartridge == null) return 0;

        int pages = doc.getPages();
        if (!cartridge.hasEnoughInkFor(pages)) {
            return 0; // just fail safely if we don't have enough ink
        }

        cartridge.consumeInkFor(pages);
        return pages;
    }

    public int partially(Document doc) {
        if (doc == null) return 0;
        if (cartridge == null) return 0;

        int pages = doc.getPages();
        int possiblePrint = cartridge.getInkLevel() / 2;
        
        if ((possiblePrint - pages) >= 0) {
            cartridge.consumeInkFor(pages);
            return pages;
        }
        // Ink becomes 0 after that.
        cartridge.consumeInkFor(possiblePrint);
        // Returns the number of pages printed.
        return possiblePrint;
    
       
    }
}