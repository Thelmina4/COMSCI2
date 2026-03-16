public class Client {

    // : Represents a mobile phone.
    // unique phone number.
    // Each phone has a current location (x, y).
    // registered with a specific operator.
    // connects to the nearest tower that supports
    //      its operator and is within range.
    // If no tower is within range, the phone has no signal.
    private Integer number;
    private Operator operator;
    private Integer x;
    private Integer y;

    // private Integer range;
    // private boolean tower_in_range;

    // contructors
    public Client(Integer number, 
        Operator operator,
        Integer x,
        Integer y) {
        this.number = number;
        this.operator = operator;
        this.x = x;
        this.y = y;
    }
        

    // getters

    // setters
    // update 

}
