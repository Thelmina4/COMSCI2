
class Product {

    public List<String> getTags(){
        return this.tags; // what is the probel here?
        // it is a reference to the function and So 
        // anyone can access it. This is giving them the memory location.
        // Anyone can access the memory and change it
        
        return new ArrayList<>(this.tags); // this is creating a new array list of the array
        // and so a new memory location, the user cannot change your data 
    }
}