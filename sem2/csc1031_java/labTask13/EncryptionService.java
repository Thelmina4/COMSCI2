// package labTask13;

// import java.util.ArrayList;
// import java.util.List;
import java.util.Base64;

interface EncryptionStrategy  {
    String encrypt(String text);
}

class CaesarCipherEncryption implements EncryptionStrategy  {
    private final int shift;

    // constructor
    // input is the shift
    public CaesarCipherEncryption(int shift) {
        this.shift = shift;
    }

    // implementation of the encryption
    @Override
    public String encrypt(String text) {
        StringBuilder result = new StringBuilder();
        for (char ch : text.toCharArray()) {
            if (Character.isLetter(ch)) {
                char base = Character.isLowerCase(ch) ? 'a' : 'A';
                ch = (char) ((ch - base + shift) % 26 + base);
            }
            result.append(ch);
        }
        return result.toString();
    }
}

class Base64Encryption implements EncryptionStrategy  {
    public Base64Encryption() {
        ;
    }

    @Override
    public String encrypt(String text) {
        return Base64.getEncoder().encodeToString(text.getBytes());
    }
}

class XOREncryption implements EncryptionStrategy  {
    private final char key;

    public XOREncryption(char key) {
        this.key = key;
    }

    @Override
    public String encrypt(String text) {
        StringBuilder result = new StringBuilder();
        for (char ch : text.toCharArray()) {
            result.append((char) (ch ^ key));
        }
        return result.toString();
    }
}

class ReverseStringEncryption implements EncryptionStrategy {
    public ReverseStringEncryption() {
        ;
    }
    @Override
    public String encrypt(String text) {
        String result = new StringBuilder(text).reverse().toString();
        return result;
    }
}
class DuplicateCharacterEncryption implements EncryptionStrategy {
    public DuplicateCharacterEncryption() {
        ;
    }
    @Override
    public String encrypt(String text) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            result.append(text.charAt(i));
            result.append(text.charAt(i));
        }
        return result.toString();
    }
}

// Context Class - the navigation app that combines the classes
public class EncryptionService {
    private EncryptionStrategy strategy;

    public void setEncryptionStrategy(EncryptionStrategy strategy) {
        this.strategy = strategy;
    }
    public String encrypt(String text) {
        return strategy.encrypt(text);
    }
}

// Main Class to Test the Strategies
// public class Main {
//     public static void main(String[] args) {
//         // Create an encryption service that will handle different encryption strategies
//         EncryptionService service = new EncryptionService();

//         // Create a Caesar Cipher encryption strategy with a shift of 3
//         EncryptionStrategy caesar = new CaesarCipherEncryption(3);

//         // Set the encryption strategy to Caesar Cipher
//         service.setEncryptionStrategy(caesar);
//         System.out.println(service.encrypt("hi"));
//         // Encrypt three different strings using the same Caesar Cipher strategy
//         System.out.println(service.encrypt("HelloWorld")); // Output: Encrypted text with shift 3
//         System.out.println(service.encrypt("StrategyPattern")); // Output: Encrypted text with shift 3
//         System.out.println(service.encrypt("EncryptionLab")); // Output: Encrypted text with shift 3

//         // BASE64
//         EncryptionStrategy base64 = new Base64Encryption();
//         service.setEncryptionStrategy(base64);
//         System.out.println(service.encrypt("HelloWorld")); // Output: Encrypted text with shift 3
//         System.out.println(service.encrypt("StrategyPattern")); // Output: Encrypted text with shift 3
//         System.out.println(service.encrypt("EncryptionLab")); // Output: Encrypted text with shift 3

//         // XOR
//         char key = 'K';
//         EncryptionStrategy xor = new XOREncryption(key);
//         service.setEncryptionStrategy(xor);
//         System.out.println(service.encrypt("HelloWorld")); // Output: Encrypted text with shift 3
//         System.out.println(service.encrypt("StrategyPattern")); // Output: Encrypted text with shift 3
//         System.out.println(service.encrypt("EncryptionLab")); // Output: Encrypted text with shift 3
       
//         // Change the encryption strategy to Reverse String Encryption
//         service.setEncryptionStrategy(new ReverseStringEncryption());

//         // Encrypt a different string using the Reverse String strategy
//         System.out.println(service.encrypt("Password")); // Output: "drowssaP" (reversed)

//         service.setEncryptionStrategy(new DuplicateCharacterEncryption());
//         System.out.println(service.encrypt("Password")); // Output: "drowssaP" (reversed)

//     }

// }