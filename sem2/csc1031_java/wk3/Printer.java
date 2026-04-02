// Printer.java

// Printer has two important relationships:

// Aggregation with InkCartridge
// (can install/remove it; cartridge can exist independently).

// Composition with PrinterConfig
//  (created inside; belongs to this printer only).

// The printer also uses Document while printing (association).

class Printer {
    private String brand;

    // Aggregation (week has-a): can be installed removed
    private InkCartridge cartridge; //used in cartridge function below

    // composition (strong has-a) owned internal component
    private PrinterConfig config; // used in getConfig below

    public Printer(String printer_brand, String ownerName, String wifiName, String wifiPassword, String firmwareVersion) {
        brand = printer_brand;

        // Created internally -> composition
        // We call PrinterConfig constructor inside this class
        // PrinterConfig object will be destroyed once Printer is gone
        config = new PrinterConfig(ownerName, wifiName, wifiPassword, firmwareVersion);
    }

    // getter for getBrand
    public String getBrand() {
        return brand;
    }

    // get the details of type InkCartridge
    // private String model;
    // private int inkLevel;
    public InkCartridge getCartridge() {
        return cartridge; // made the variable above

    }

    public boolean hasCartridge() {
        return cartridge != null;
    }

    // setter for installing the InkCartridge
    public void installCartridge(InkCartridge new_cartridge) {
        // if the new_cartridge doesn't exist return;
        if (new_cartridge == null) return;
        cartridge = new_cartridge;
    }

    // setter for removing the InkCartridge
    public InkCartridge removeCartridge() {
        InkCartridge tmp = cartridge; // save for later
        cartridge = null; // remove it
        return tmp; // return to "outside" of the printer world
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

    // Printer uses Document (ASSOCIATION)
    // private String title;
    // private int pages;
    public int print(Document doc) {
        if (doc == null) return 0;
        if (cartridge == null) return 0;

        int pages = doc.getPages();
        if (!cartridge.hasEnoughInkFor(pages)) {
            return 0; // just fail safely if we don't have enough ink
        }

        cartridge.consumeInkFor(pages);
        return pages; // return how many pages were printed
    }
}