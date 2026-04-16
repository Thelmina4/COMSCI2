// package labTask16;

// What is a Prefix Tree?
// A Prefix Tree (Trie) is a tree-based data structure that stores
//  a set of strings in a way that allows fast prefix-based lookups.
//  Each node in the tree represents a single character,
//  and paths from the root to the leaves form words or sequences.

// Implement a TrieNode class to represent nodes in the Prefix Tree.
// Implement a PrefixTree class to manage word insertions and lookups.
// Ensure prefix-based search is efficient.
// Implement a traverse() function to print the tree hierarchy.

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Arrays;

class TrieNode {
    // Implement a TrieNode class to represent nodes in the Prefix Tree.
    // Represents a single node in the tree.

    // Contains:
    // Character value
    private char value;
    // Reference to child nodes (stored in a map)
    private HashMap<Character, TrieNode> children;
    // Boolean flag to indicate the end of a branch
    private Boolean isLeaf;
    
    // Methods to Implement: - Constructor to initialize a node. - markAsLeaf() to indicate that a word ends at this node.
    public TrieNode(char value) {
        this.value = value;
        children = new HashMap<>();
        isLeaf = false;
    }

    // getters
    // public String getValue() {return value.toString();} <- doesn't work
    public HashMap<Character, TrieNode> getChildren() {return children;}
    
    public boolean getIsLeaf() {return isLeaf;}

    public char getValue() {return value;}

    // setters
    public void markAsLeaf() {
        this.isLeaf = true;
    }
}

public class PrefixTree {
    private TrieNode root;
    // constructor
    public PrefixTree() {
        // initialise it with an empty root
        root = new TrieNode('\0');
    }
    // Implement a PrefixTree class to manage word insertions and lookups.
    // Maintains a root node and enables word insertion and lookup.

    // Supports efficient prefix searching.

    // insert(String word): Inserts a word into the tree.
    public void insert(String word) {
        TrieNode current = root;
        // if (value != null && !value.trim().isEmpty()) {
        //     throw new IllegalArgumentException("Error: Word entered cannot be empty");
        // }
        for (char c : word.toCharArray()) {
            current.getChildren().putIfAbsent(c, new TrieNode(c));
            current = current.getChildren().get(c);
        }
        current.markAsLeaf();
    }

    // search(String word): Checks if a word exists in the tree.
    // want to traverse through the list and either return the last node in the
    // OR null
    // helper function for search and startsWith
    private TrieNode findNode(String compareStr) {
        TrieNode current = root;

        for (char c : compareStr.toCharArray()) {
            if (!current.getChildren().containsKey(c)) {
                return null;
            }
            current = current.getChildren().get(c);
        }
        return current;
    }
    public boolean search(String word) {
        // full word if it's not the first/middle (non starter) 
        // AND IS the last char isLeaf.
        TrieNode node = findNode(word);
        if (node != null && node.getIsLeaf()) {return true;}
        return false;

    }
    // startsWith(String prefix): Checks if any word in the tree starts with the given prefix.
    public boolean startsWith(String prefix) {
        // is prefix IF it is not null (and so therefore failed)
        return findNode(prefix) != null;

    }

    // recursive helper for taverse 
    // output:
    //  need to add a "  └── " 2 spaces + └── to every letter
    // if .getIsLeaf() add an " (end)"
    // traverse(): Recursively prints the tree structure.
    private void traverseHelper(TrieNode node, String indent) {
        for (TrieNode child : node.getChildren().values()) {
            System.out.print(indent + "└── " + child.getValue());

            if (child.getIsLeaf()) {
                System.out.print(" (end)");
            }
            System.out.println();
            traverseHelper(child, indent + "  ");
        }
    }
    
    
    public void traverse() {
        TrieNode current = root;
        traverseHelper(current, "  ");
    } 
}
// public class PrefixTreeUsage {
//     public static void main(String[] args) {
//         PrefixTree trie = new PrefixTree();

//         trie.insert("cat");
//         trie.insert("car");
//         trie.insert("dog");

//         System.out.println("Search 'cat': " + trie.search("cat")); // true
//         System.out.println("Search 'bat': " + trie.search("bat")); // false
//         System.out.println("StartsWith 'ca': " + trie.startsWith("ca")); // true
//         System.out.println("StartsWith 'do': " + trie.startsWith("do")); // true
//         System.out.println("StartsWith 'bo': " + trie.startsWith("bo")); // false

//         System.out.println("Trie Structure:");
//         trie.traverse();
//     }
// }

// HASHMAP METHODS
// Method	    Description	        Return Type
// clear()	Remove all entries from the map.	void
// clone()	Create a copy of the HashMap.	Object
// compute()	Compute a value for an entry based on its key and the current value (if it has one)	V
// computeIfAbsent()	Compute a value for an entry based on its key only if an entry using the key does not already exist	V
// computeIfPresent()	Compute a new value for an entry based on its key and current value but only if an entry with the key already exists	V
// containsKey()	Indicate if an entry with the specified key exists in the map	boolean
// containsValue()	Indicate if an entry with the specified value exists in the map	boolean
// entrySet()	Return a set of all entries in the map	Set< Map.Entry<K,V> >
// forEach()	Perform an action on every entry in the map	void
// get()	Return the value of the entry with a specified key	V
// getOrDefault()	Return the value of the entry with a specified key or a default value if the entry is not found	V
// isEmpty()	Indicate whether the map is empty	boolean
// keySet()	Return a set of all keys in the map	Set<K>
// merge()	Compute a value for an entry based on its key and value or write a specific value if the entry does not yet exist	V
// put()	Write an entry into the map	V
// putAll()	Write all of the entries from another map into this one	void
// putIfAbsent()	Write an entry into the map but only if an entry with the same key does not already exist	V
// remove()	Remove an entry from the map	V|boolean
// replace()	Write to an entry in the map only if it exists	V|boolean
// replaceAll()	Replaces the value of every entry with the result of an operation	void
// size()	Return the number of entries in the map	int
// values()	Return a collection containing all of the values in the map	Collection<V>


// // sTRING METHODS
// Method	Description	Return Type
// charAt()	Returns the character at the specified index (position)	char
// codePointAt()	Returns the Unicode of the character at the specified index	int
// codePointBefore()	Returns the Unicode of the character before the specified index	int
// codePointCount()	Returns the number of Unicode values found in a string.	int
// compareTo()	Compares two strings lexicographically	int
// compareToIgnoreCase()	Compares two strings lexicographically, ignoring case differences	int
// concat()	Appends a string to the end of another string	String
// contains()	Checks whether a string contains a sequence of characters	boolean
// contentEquals()	Checks whether a string contains the exact same sequence of characters of the specified CharSequence or StringBuffer	boolean
// copyValueOf()	Returns a String that represents the characters of the character array	String
// endsWith()	Checks whether a string ends with the specified character(s)	boolean
// equals()	Compares two strings. Returns true if the strings are equal, and false if not	boolean
// equalsIgnoreCase()	Compares two strings, ignoring case considerations	boolean
// format()	Returns a formatted string using the specified locale, format string, and arguments	String
// getBytes()	Converts a string into an array of bytes	byte[]
// getChars()	Copies characters from a string to an array of chars	void
// hashCode()	Returns the hash code of a string	int
// indexOf()	Returns the position of the first found occurrence of specified characters in a string	int
// intern()	Returns the canonical representation for the string object	String
// isEmpty()	Checks whether a string is empty or not	boolean
// join()	Joins one or more strings with a specified separator	String
// lastIndexOf()	Returns the position of the last found occurrence of specified characters in a string	int
// length()	Returns the length of a specified string	int
// matches()	Searches a string for a match against a regular expression, and returns the matches	boolean
// offsetByCodePoints()	Returns the index within this String that is offset from the given index by codePointOffset code points	int
// regionMatches()	Tests if two string regions are equal	boolean
// replace()	Searches a string for a specified value, and returns a new string where the specified values are replaced	String
// replaceAll()	Replaces each substring of this string that matches the given regular expression with the given replacement	String
// replaceFirst()	Replaces the first occurrence of a substring that matches the given regular expression with the given replacement	String
// split()	Splits a string into an array of substrings	String[]
// startsWith()	Checks whether a string starts with specified characters	boolean
// subSequence()	Returns a new character sequence that is a subsequence of this sequence	CharSequence
// substring()	Returns a new string which is the substring of a specified string	String
// toCharArray()	Converts this string to a new character array	char[]
// toLowerCase()	Converts a string to lower case letters	String
// toString()	Returns the value of a String object	String
// toUpperCase()	Converts a string to upper case letters	String
// trim()	Removes whitespace from both ends of a string	String
// valueOf()	Returns the string representation of the specified value	String


// Common List Methods
// Method	Description
// add()	Adds an element to the end of the list
// get()	Returns the element at the specified position
// set()	Replaces the element at the specified position
// remove()	Removes the element at the specified position
// size()	Returns the number of elements in the list