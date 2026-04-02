// InkCartridge.java

// an InkCartridge can exist on it's own (you can buy it/store it)
// So Printer will have a cartridge reference
// AGGREGATION

// We keep the ink level private and only change it through methods.

// Ink rule for this lab: 1 page = 2% ink.

class InkCartridge {
    private String model;
    private int inkLevel;

    // constructor
    public InkCartridge(String model_name, int inkLevel) {
        model = model_name;
        setInkLevel(inkLevel); // validation in one place
    }

    // getters
    public String getModel() {
        return model;
    }

    public int getInkLevel() {
        return inkLevel;
    }

    // setters
    // Setter exists because ink changes over time and we must validate it
    public void setInkLevel(int newLevel) {
        if (newLevel < 0) newLevel = 0; // setting a min of 0%
        if (newLevel > 100) newLevel = 100; // setting a max of 100%
        inkLevel = newLevel;
    }

    // Simple rule: 1 page = 2% ink
    public boolean hasEnoughInkFor (int pages) {
        int needed = pages * 2;
        return inkLevel >= needed;
    }
    // if InkCartridge hasEnoughInkFor == True, then
    // setInkLevel to the new consumeInkFor amount
    public void consumeInkFor(int pages) {
        int needed = pages * 2;
        setInkLevel(inkLevel - needed);
    }
}