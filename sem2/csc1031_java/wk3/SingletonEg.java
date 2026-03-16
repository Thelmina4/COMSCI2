class SingletonEg {
    private static SingletonEg instance;

    // private constructor to prevent instantiation
    private SingletonEg() {}
    
    // Method to provide access to the single instance
    public static SingletonEg getInstance() {
        if (instance == null) {
            instance = new SingletonEg();
        }
        return instance;
    }
    public void showMessage() {
        System.out.println("Hello fromt he Singleton ");
    }
}