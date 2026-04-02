// Product.java

// requirements:

// CONSTRUCTORS should initialize all fields correctly, 
//      with DEFAULT values where applicable.

import java.util.ArrayList;
import java.util.List;

public class Product {

    // ATTRIBUTES
    private String productName;

    private long price;

    private boolean inStock;

    private List<String> tags;

    // CONSTUCTORS
    // what are the main fields?
    // productName, price (test and then adjust)
    // default chained constructor
    public Product() {
        // constructor chaining, initialise balance to 0
        this("Unknown", 0L, false, new ArrayList<>());
    }

    // constructer w just name supplied
    // === Testing Constructor with productName ===
    public Product(String productName) {
        this(productName, 0L, false, new ArrayList<>());
    }

    // === Testing Constructor with productName and price ===
    public Product(String productName, long price) {
        this(productName, price, false, new ArrayList<>());
    }

    // === Testing Constructor with productName, price, and inStock ===
    public Product(String productName, long price, boolean inStock) {
        this(productName, price, inStock, new ArrayList<>());
    }

    public Product(String productName, boolean inStock) {
        this(productName, 0L, inStock, new ArrayList<>());
    }

    // === Testing Constructor with productName, price, and tags ===
    public Product(String productName, boolean inStock, List<String> tags) {
        this(productName, 0L, inStock, tags);
    }

    public Product(String productName, long price, List<String> tags) {
        this(productName, price, false, tags);
    }
    // constuctor w all fields provided

    public Product(String productName, long price, boolean inStock, List<String> tags) {
        if (productName != null && !productName.trim().isEmpty()) {
            this.productName = productName.trim();
        } else {
            this.productName = "Unknown";
        }
        if (price >= 0){
            this.price = price;
        } else {
            this.price = 0L;
        }
        
        this.inStock = inStock;
        
        if (tags == null) {
            this.tags = new ArrayList<>();
        } else {
            this.tags = new ArrayList<>(tags);
        }
    }

    // the deep copy
    public Product(Product other) {
        this.productName = other.productName;
        this.price = other.price;
        this.inStock = other.inStock;
        this.tags = new ArrayList<>(other.tags); 
    }

    // METHODS
    // encapsulation of the tags:

    // public List<String> getTags(): Returns tags list.
    public List<String> getTags() {

        return new ArrayList<>(tags);
    }

    // public void setTags(List<String> tags): Sets the tags list.
    public void setTags(List<String> tags) {
        // if the array == empty
        if (tags == null) {
            // then make a new list
            this.tags = new ArrayList<>();
        } else {
            this.tags = new ArrayList<>(tags);
        }
    }
    // public void addTag(String tag): Adds a tag to the tags list.
    public void addTag(String tag) { 
        if (tag != null && !tag.isEmpty()) {
            tags.add(tag);
        }
    }

    @Override
    public String toString() {
        return "Product{" +
                "productName='" + productName + '\'' +
                ", price=" + price +
                ", inStock=" + inStock +
                ", tags=" + tags +
                '}';
    }

    // main method to test ...
    // Each constructor, including edge cases
    // (e.g., null values, empty strings, negative prices)
    public static void main(String[] argv) {
        // what to test
        // constructors
        // empty
        // Product p1 = new Product();
        // System.out.println(p1);

        // // just the name
        // Product p2 = new Product("Fridge");
        // System.out.println(p2);

        // Product p3 = new Product("  campervan  ", -3);
        // System.out.println(p3);

        // Product p4 = new Product("    ", 10);
        // System.out.println(p4);
        // // getTags, setTags, addTag, toString
        // Product p5 = new Product("TV", 234, true);
        // System.out.println(p5);
        
        // Product p6 = new Product("phone l", true);
        // System.out.println(p6);    

        // // tags tests

        // System.out.println("There shouldn't be a tags list here: " + p6.getTags());
        // p6.addTag("This is great");
        // System.out.println(p6);  
        // System.out.println("There SHOULD be a tags list here: " + p6.getTags());

        // // null and ""
        // Product p7 = new Product("Video kill radiostar", 10000, true);
        // p7.addTag(null);
        // p7.addTag("");
        // p7.addTag("Enter Tag");
        // System.out.println(p7.getTags());

        // // protected from external additions
        // List<String> testAdd = p7.getTags();
        // testAdd.add("Adding tag test");
        // System.out.println("lets see if this prevents more tags: " + testAdd);
        // System.out.println("lets see if this prevents more tags in the product: " + p7.getTags());

        // // testing set tags
        // p7.setTags(null);
        // System.out.println("Set the tags: " + p7.getTags());
        // System.out.println(p7);

        // List<String> tags7 = new ArrayList<>();

        // tags7.add("sale");
        // tags7.add("limited");
        // p7.setTags(tags7);
        // tags7.add("EXTERNAL");   
        // System.out.println("External list modified: " + tags7);
        // System.out.println("tags should NOT contain 'EXTERNAL': " + p7.getTags());

        // Product copy = new Product(p7);
        // copy.addTag("copy-only");
        // System.out.println("Original product tags: " + p1.getTags());
        // System.out.println("Copied product tags: " + copy.getTags());

    }
}
