// PrinterConfig.java

// PrinterConfig stores the “current printer setup”
//  (owner and Wi‑Fi settings). 
// In this lab, we model it as composition: 
// it is created inside the printer and belongs only to it.

// Fields in this config are private, and changes go through setters.

class PrinterConfig {
    private String ownerName;
    private String wifiName;
    private String wifiPassword;
    private String firmwareVersion;

    // constructor
    public PrinterConfig(String owner_Name,
                        String wifi_Name,
                        String wifi_Password, 
                        String firmware_Version) {
        ownerName = owner_Name;
        wifiName = wifi_Name;
        wifiPassword = wifi_Password;
        firmwareVersion = firmware_Version;
    }
    // getter ownername
    public String getOwnerName() {
        return ownerName;
    }

    // setter ownername
    public void setOwnerName(String Name) {
        if (Name == null || Name.trim().isEmpty()) return;
        ownerName = Name;
    }
    
    // getter wifiName
    public String getWifiName() {
        return wifiName;
    }

    // setter wifiName
    public void setWifiName(String Name) {
        if (Name == null || Name.trim().isEmpty()) return;
        wifiName = Name;
    }

    // getter wifiPassword
    public String getWifiPassword() {
        return wifiPassword;
    }

    // setter wifiPassword
    public void setWifiPassword(String Password) {
        if (Password == null || Password.trim().isEmpty()) return;
        wifiPassword = Password;
    }

    // getter firmwareVersion
    public String getFirmwareVersion() {
        return firmwareVersion;
    }

    // setter firmwareVersion
    public void setFirmwareVersion(String Version) {
        if (Version == null || Version.trim().isEmpty()) return;
        firmwareVersion = Version;
    }

}