import java.util.ArrayList;
import java.util.List;

public class Operator {
    // : Represents a mobile network operator.
    // name
    // list of clients - UNIQUE PHONES
    // list of towers

    private String name;
    private List<Integer> clients;
    private List<Integer> towers;
    // private List<Client> clients;
    // private List<CellTower> towers;

    // constructor
    public Operator(String name, List<Integer> clients, List<Integer> towers) {
        this.name = name;
        // deep copy of the list of clients that one operator has.
        this.clients = new ArrayList<>(clients);
        // deep copy of the list of towers that one operator can use.
        this.towers = new ArrayList<>(towers);
    }
    // getters 
    // get the name of the operator
    public String getOperatorName() {
        return this.name;
    }
    // get list of clients
    public List<Integer> getOperatorClients() {
        return this.clients;
    }
    // get the list of towers that it uses
    public List<Integer> getOperatorTowers() {
        return this.towers;
    }
    // get the number of clients that the operator has
    public Integer clientCount() {
        return this.clients.size();
    }
    // setters
    // setter for the operator name
    public void setOperatorName(String var1) {
        if (var1 != null && !var1.trim().isEmpty()) {
            this.name = var1;
        }
    }
    // setter for list of clients
    public void setOperatorClients(List<Integer> lst1) {
        if (lst1 != null && !lst1.isEmpty()) {
            this.clients = lst1;
        }
    }
    // setter for list of allowed towers
    public void setOperatorTowers(List<Integer> lst1) {
        if (lst1 != null && !lst1.isEmpty()) {
            this.towers = lst1;
        }
    }    
    // add a tower to the list

    // add a phone to the list



}
