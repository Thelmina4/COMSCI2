// main.java
// runner for Document, InkCartridge, Printer and PrinterConfig

public class main {
    public static void main(String[] args) {

        // Create a document (independent object)
        Document doc = new Document("CSC1031", 12);

        // Create a cartridge (independent object)
        InkCartridge cart = new InkCartridge("HP=301", 40);

        // Create a printer (printer owns its PrinterConfig internally)
        // these are from printerConfig:
        // private String ownerName;
        // private String wifiName;
        // private String wifiPassword;
        // private String firmwareVersion;
        Printer printer = new Printer(
            "LaserFox",
            "Misha",
            "DCU-wifi",
            "1234-very-secret",
            "v1.0.0");
        
        // install cartridge (aggregation)
        printer.installCartridge(cart);

        int printedPages = printer.print(doc);

        System.out.println("Printer Brand: " + printer.getBrand());
        System.out.println("Owner: " + printer.getConfig().getOwnerName());
        System.out.println("WiFi: " + printer.getConfig().getWifiName());
        System.out.println("Firmware: " + printer.getConfig().getFirmwareVersion());
        System.out.println("Printed Pages: " + printedPages);
        
        // the cartrige is still in the printer so use...
        // getCartrige where the cartridge is initialised and then the levels inside the cartridge
        System.out.println("Ink after printing: " + printer.getCartridge().getInkLevel());

        // Remove cartridge (cartridge continues to exist)
        // create a vaiable removed and put it == to the cartrisdge that you're remiving
        // saved the data in that cartridge
        InkCartridge removed = printer.removeCartridge();
        // it is not in the printer, this is TYPE InkCartridge
        //  so access the getmodel directly
        System.out.println("Removed cartridge model: " + removed.getModel());

        // try to print without the cartridge
        int printed = printer.print(new Document("another doc", 3));
        System.out.println("Printed pages w/o a cartridge: " + printed);

        // cartridge still exists and can be re-installed
        printer.installCartridge(removed);
        printer.print(new Document("Short note", 2));

        System.out.println("Ink at the end: " + printer.getCartridge().getInkLevel() + "%");

        // update config (still the same config object owned by the printer)
        printer.getConfig().setFirmwareVersion("v1.0.1");
        System.out.println("Firmware after Update: " + printer.getConfig().getFirmwareVersion());
    }
}