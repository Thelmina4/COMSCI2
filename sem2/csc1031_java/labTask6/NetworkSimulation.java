// package labTask6;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Celltower {
    // don't need to input the id as it is unique
    // this should be a string
    // private final int tower_id;
    // private static int next_id = 1;
    private String tower_id;
    // coords
    private int x;
    private int y;
    // this might need to be a double?
    private int coverage_radius;

    // constructor
    // maybe make a defaut constructor w no input, one w coords and 1 w coverage?
    // do I need to make a deep copy?
    public Celltower(String tower, int x, int y, int coverage) {
        // can't do the next id like this as he is supplying them.
        // need to make a conparison somehow
        // tower_id = next_id++;
        set_tower_id(tower);
        this.x = x;
        this.y = y;
        coverage_radius = coverage;
    }

    // public Celltower(int x, int, y, int coverage)

    // do I need to make a deep copy?
    // DEEP COPY IF NEEDED
    // public Celltower copyCelltower() {
    // Celltower nCelltower = new Celltower(this.tower_id, this.x, this.y,
    // this.coverage_radius);
    // return nCelltower;
    // }

    // getters don't think I need these, but lets see
    public String get_tower_id() {
        return tower_id;
    }

    public int get_x() {
        return x;
    }

    public int get_y() {
        return y;
    }

    public int get_coverage_radius() {
        return coverage_radius;
    }

    // setters
    public void set_tower_id(String tower) {
        if (tower != null && !tower.trim().isEmpty()) {
            this.tower_id = tower;
        }
    }
}

// //////////////////////////////////////////////////////////
// OPERATOR
// //////////////////////////////////////////////////////////

class Operator {
    private String operator_name;
    private List<Client> clients;
    private List<Celltower> towers;

    public Operator(String operator_name) {
        set_operator(operator_name);
        this.clients = new ArrayList<>();
        this.towers = new ArrayList<>();
    }

    // public Operator(String operator_name) {
    // set_operator(operator_name);
    // this(new ArrayList<>(), new ArrayList<>());
    // }

    // do I need to make a deep copy?
    // public Operator copyOperator() {
    // Operator nOperator = new Operator(String operator_name, List<Client> clients,
    // List<Celltower> towers)
    // return nOperator;
    // }

    // getters
    public String get_operator_name() {
        return operator_name;
    }

    public int getClientCount() {
        return clients.size();
    }

    public int getCellTowersLength() {
        return towers.size();
    }

    public List<Celltower> getCelltower() {
        return new ArrayList<>(towers);
    }

    public List<Client> get_operatorClients() {
        return new ArrayList<>(clients);
    }

    // setters
    public void set_operator(String operator) {
        if (operator != null && !operator.trim().isEmpty()) {
            this.operator_name = operator;
        }
    }

    public void update_towers(Celltower tower) {
        if (tower != null && !towers.contains(tower)) {
            towers.add(tower);
        }
    }

    public void delete_tower(Celltower tower) {
        towers.remove(tower);
    }

    public void update_clients(Client client) {
        if (client != null && !clients.contains(client)) {
            clients.add(client);
        }
    }

    public void delete_client(Client client) {
        clients.remove(client);
    }
}

// //////////////////////////////////////////////////////////
// CLIENT
// //////////////////////////////////////////////////////////

class Client {
    private final int phone_number;
    private Operator operator;
    private int x;
    private int y;
    private Celltower connected_tower;
    private boolean hasSignal;

    // client MUST have an operator
    public Client(int phone_number, Operator operator, int x, int y) {
        this.phone_number = phone_number;
        this.operator = operator;
        this.x = x;
        this.y = y;
        this.connected_tower = null;
        this.hasSignal = false;
    }

    // getters
    public int get_phone_number() {
        return phone_number;
    }

    public Operator getOperator() {
        return operator;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Celltower getConnectedCelltower() {
        return connected_tower;
    }

    public boolean getHasSignal() {
        return hasSignal;
    }

    // setters
    public void setOperator(Operator operator) {
        if (operator != null) {
            this.operator = operator;
        }
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    // methods for setting tower
    public void set_tower(Celltower tower) {
        this.connected_tower = tower;
        this.hasSignal = (tower != null);
    }

    // public void setHasSignal(Celltower tower) {
    // if (tower != null) {hasSignal = true;}
    // else hasSignal = false;
    // }
}
// //////////////////////////////////////////////////////////
// NETWORK
// //////////////////////////////////////////////////////////

class Network {
    // Manages all towers, operators, and clients.

    // Lists of all the current towers, operators and clients
    private List<Client> clients;
    private List<Celltower> towers;
    private List<Operator> operators;
    // makes sure that these are unique?

    public Network() {
        clients = new ArrayList<>();
        towers = new ArrayList<>();
        operators = new ArrayList<>();
    }

    private List<Operator> get_operators() {return operators;}

    // does the calculation for the moving of the clients to nearest tower
    // take the list of towers from the operator
    // calculate the distance from the phone to the tower
    // if the radius > distance add it to new list of ok towers.
    //
    public double distance(Client c, Celltower t) {
        int cx = c.getX();
        int cy = c.getY();
        int tx = t.get_x();
        int ty = t.get_y();
        double nx = Math.pow((tx - cx), 2);
        double ny = Math.pow((ty - cy), 2);
        return Math.sqrt(nx + ny);
    }

    // helper to find operators
    public Operator find_by_operator_name(String name) {
        for (Operator op : operators) {
            if (name.equals(op.get_operator_name())) {
                return op;
            }
        }
        return null;
    }

    // find the client
    public Client find_by_number(int phone) {
        for (Client c : clients) {
            if (phone == c.get_phone_number()) {
                return c;
            }
        }
        return null;
    }

    // count the connected clients to the tower
    private int countClients(Celltower t) {
        int count = 0;
        for (Client c : clients) {
            if (c.getConnectedCelltower() == t) {
                count++;
            }
        }
        return count;
    }

    public Celltower closestCelltower(Client client) {
        Operator op = client.getOperator();
        if (op == null) { return null; }
        
        List<Celltower> ts = op.getCelltower();


        Celltower closest = null;
        double minDistance = -1;

        for (Celltower t : ts) {
            double dist = distance(client, t);
            if (dist <= t.get_coverage_radius()) {
                // cover all the bases
                // If multiple towers are at the same distance,
                // choose the one with the fewest phones connected.
                if (minDistance < 0 || dist < minDistance ||
                        (dist == minDistance && countClients(t) < countClients(closest))) {
                    minDistance = dist;
                    closest = t;
                }
            }
        }
        return closest;
    }

    // MOVE_CLIENT
    public void MOVE_CLIENT(int phone, int x, int y) {
        Client c = find_by_number(phone);
        if (c == null) {
            return;
        }
        c.setX(x);
        c.setY(y);
        Celltower update_tower = closestCelltower(c);
        c.set_tower(update_tower);
        // c.setHasSignal(update_tower);
    }

    // CHANGE_OPERATOR phone_number new_operator_name
    public void CHANGE_OPERATOR(int phone_number, String new_operator_name) {
        // Updates the operator of a client.
        // If the new operator does not support the current tower,
        // the phone should switch to the nearest available tower.

        Operator newOp = find_by_operator_name(new_operator_name);
        Client c = find_by_number(phone_number);
        // check that not null
        if (c == null || newOp == null) {
            return;
        }

        // old operator
        Operator oldOp = c.getOperator();

        // remove old op
        oldOp.delete_client(c);

        // add the new op
        newOp.update_clients(c);
        c.setOperator(newOp);

        Celltower update_tower = closestCelltower(c);
        c.set_tower(update_tower);
        // c.setHasSignal(update_tower);
    }

    public Celltower find_by_tower_id(String tower_id) {
        for (Celltower t : towers) {
            if (tower_id.equals(t.get_tower_id())) {
                return t;
            }
        }
        return null;
    }

    // TOWER_CLIENT_COUNT
    public int TOWER_CLIENT_COUNT(String tower_id) {
        // Returns the number of phones currently connected to a given tower.
        Celltower t = find_by_tower_id(tower_id);
        // for (Client c : clients) {
        //     System.out.println(
        //         "Client " + c.get_phone_number() +
        //         " -> " +
        //         (c.getConnectedCelltower() == null ? "NONE" :
        //         c.getConnectedCelltower().get_tower_id())
        //     );
        // }

        if (t == null) {return 0;}
        int count = 0;
        for (Client c : clients) {
            if (c.getConnectedCelltower() == t) {
                count++;
            }
        }
        return count;
    }

    // OPERATOR_SUBSCRIBER_COUNT
    public int OPERATOR_SUBSCRIBER_COUNT(String operator_name) {
        // Returns the number of clients registered under a given operator.
        Operator op = find_by_operator_name(operator_name);

        return op.getClientCount();
    }

    // ADD_CLIENT
    // add it to the list here too
    // make sure that the id is unique
    // Registers a new client with a specific operator and initial location.
    public void ADD_CLIENT(int phone_number, String operator_name, int x, int y) {
        // check it's unique
        if (find_by_number(phone_number) != null) {
            return;
        }
        // get the operator
        Operator op = find_by_operator_name(operator_name);
        // make sure that it isn't null
        if (op == null) {
            return;
        }
        Client new_Client = new Client(phone_number, op, x, y);
        Celltower tower = closestCelltower(new_Client);
        new_Client.set_tower(tower);
        // new_Client.setHasSignal(tower);

        clients.add(new_Client);
        op.update_clients(new_Client);

        // for (Client c : clients) {
        // if (phone_number != c.get_phone_number()) {
        // // client
        // Client new_Client = new Client(phone_number, op, x, y);
        // Celltower update_tower = closestCelltower(new_Client);
        // c.set_tower(update_tower);
        // c.setHasSignal(update_tower);
        // // operator
        // op.update_clients(new_Client);
        // }
        // }
    }

    // REMOVE_CLIENT
    public void REMOVE_CLIENT(int phone_number) {
        // Removes a client from the system.
        // remove it from networks list, the operator list
        Client c = find_by_number(phone_number);
        if (c == null) {
            return;
        }
        Operator op = c.getOperator();
        op.delete_client(c);
        clients.remove(c);
    }

    // ADD_TOWER
    public void ADD_TOWER(String tower_id, int x, int y, int coverage_radius) {
        // Adds a new tower with given coverage
        // but does not assign it to any operator initially.
        if (find_by_tower_id(tower_id) != null) {
            return;
        }
        Celltower newCelltower = new Celltower(tower_id, x, y, coverage_radius);
        towers.add(newCelltower);

        // for (Celltower tower : towers) {
        // if (tower_id != tower.get_tower_id()) {
        // Celltower newCelltower = new Celltower(tower_id, x, y, coverage_radius);
        // towers.add(newCelltower);
        // }
        // }
    }

    // REGISTER_OPERATOR_TOWER
    public void REGISTER_OPERATOR_TOWER(String operator_name, String tower_id) {
        // Assigns a tower to an operator, allowing its clients to use it.
        Operator op = find_by_operator_name(operator_name);
        Celltower tower = find_by_tower_id(tower_id);
        op.update_towers(tower);
    }

    // REMOVE_TOWER
    public void REMOVE_TOWER(String tower_id) {
        // Removes a tower from the system.
        // Phones previously connected to this tower
        // should switch to the nearest available tower.

        Celltower tower = find_by_tower_id(tower_id);
        if (tower == null) { return; }

        // need to remove it from the networks list
        towers.remove(tower);

        // need to remove it from the operators list
        // get the phones to search from a new tower and adust their has signal
        for (Operator op : operators) {
            op.delete_tower(tower);
        }

        for (Client c : clients) {
            if (c.getConnectedCelltower() == tower) {
                Celltower update_tower = closestCelltower(c);
                c.set_tower(update_tower);
            }
        }
    }

    // NO_SIGNAL_COUNT
    public String NO_SIGNAL_COUNT() {
        for (Operator op : operators) {
            int countFalse = 0;

            for (Client c : clients) {
                if (c.getOperator() == op && !c.getHasSignal()) {
                    countFalse++;
                }
            }
            // OperatorA: 1 phones without signal.
            System.out.println(op.get_operator_name() + ": " + countFalse + " phones without signal.");
        }
        return null;
    }
    // for (Client c : clients) {
    // if (!c.getHasSignal()) {
    // count++;
    // }
    // }
    // System.out.println("NO_SIGNAL_COUNT " + count);

    // ADD_OPERATOR
    public void ADD_OPERATOR(String operator_name) {
        Operator op = new Operator(operator_name);
        if (find_by_operator_name(operator_name) != null) {
            return;
        }
        operators.add(op);
    }
}

public class NetworkSimulation {
    // what goes here?
    public static void main(String[] args) {
        // Celltower c = new Celltower("t1", 2, 3, 4);
        // System.out.println(c.get_coverage_radius());
        // System.out.println(c.get_tower_id());
        // System.out.println(c.get_x());
        // System.out.println(c.get_y());

        // Operator op = new Operator("t1");
        // op.update_towers(c);
        // System.out.println("Operator: " + op.get_operator_name());
        // System.out.println("Operator getClientCount: " + op.getClientCount());
        // System.out.println("Operator getCellTowersLength: " +
        // op.getCellTowersLength());
        // System.out.println("Operator getCelltower: " + op.getCelltower());
        // System.out.println("Operator get_operatorClients: " +
        // op.get_operatorClients());

        // System.out.println(" ");
        // Client client = new Client(123456, op, 1, 4);
        // client.setOperator(op);
        // System.out.println("Client: " + client.get_phone_number());
        // System.out.println("Client: " + client.getOperator());
        // System.out.println("Client: " + client.getX());
        // System.out.println("Client: " + client.getY());
        // System.out.println("Client: " + client.getConnectedCelltower());
        // System.out.println("Client: " + client.getHasSignal());

        // need to make different cases for each of the functions
        Scanner sc = new Scanner(System.in);
        Network net = new Network();

        // while loop to continue till no more input
        while (sc.hasNext()) {
            String command = sc.next();

            switch (command) {
                // ADD_OPERATOR
                case "ADD_OPERATOR":
                    String opName = sc.next();
                    net.ADD_OPERATOR(opName);
                    break;

                // MOVE_CLIENT
                case "MOVE_CLIENT":
                    int p = sc.nextInt();
                    int x = sc.nextInt();
                    int y = sc.nextInt();
                    net.MOVE_CLIENT(p, x, y);
                    break;

                // CHANGE_OPERATOR
                case "CHANGE_OPERATOR":
                    int ph = sc.nextInt();
                    String n = sc.next();
                    net.CHANGE_OPERATOR(ph, n);
                    break;

                case "TOWER_CLIENT_COUNT":
                    String tid = sc.next();
                    System.out.println(net.TOWER_CLIENT_COUNT(tid));
                    break;

                case "OPERATOR_SUBSCRIBER_COUNT":
                    String opsubcount = sc.next();
                    System.out.println(net.OPERATOR_SUBSCRIBER_COUNT(opsubcount));
                    break;

                case "ADD_CLIENT":
                    int pn = sc.nextInt();
                    String opClient = sc.next();
                    int xc = sc.nextInt();
                    int yc = sc.nextInt();
                    net.ADD_CLIENT(pn, opClient, xc, yc);
                    break;

                case "REMOVE_CLIENT":
                    int clientNumber = sc.nextInt();
                    net.REMOVE_CLIENT(clientNumber);
                    break;

                case "ADD_TOWER":
                    String addTID = sc.next();
                    int addTx = sc.nextInt();
                    int addTy = sc.nextInt();
                    int radius = sc.nextInt();
                    net.ADD_TOWER(addTID, addTx, addTy, radius);
                    break;

                case "REGISTER_OPERATOR_TOWER":
                    String registerName = sc.next();
                    String registerTID = sc.next();
                    net.REGISTER_OPERATOR_TOWER(registerName, registerTID);
                    break;

                case "REMOVE_TOWER":
                    String removeTower = sc.next();
                    net.REMOVE_TOWER(removeTower);
                    break;

                case "NO_SIGNAL_COUNT":
                    net.NO_SIGNAL_COUNT();
                    break;               
            }
        }
        

        // // ADD_OPERATOR
        // net.ADD_OPERATOR("OperatorA");

        // net.ADD_OPERATOR("OperatorB");

        // // ADD_TOWER
        // net.ADD_TOWER("T1", 0, 0, 10);
        // net.ADD_TOWER("T2", 20, 20, 15);
        // net.ADD_TOWER("T3", 50, 50, 20);

        // // REGISTER_OPERATOR_TOWER
        // net.REGISTER_OPERATOR_TOWER("OperatorA", "T1");
        // net.REGISTER_OPERATOR_TOWER("OperatorA", "T2");
        // net.REGISTER_OPERATOR_TOWER("OperatorB", "T3");

        // // ADD_CLIENT
        // net.ADD_CLIENT(123456, "OperatorA", 5, 5);
        // net.ADD_CLIENT(789012, "OperatorA", 25, 25);
        // net.ADD_CLIENT(345678, "OperatorB", 55, 55);
        // net.ADD_CLIENT(987654, "OperatorA", 100, 100);

        // // INITIAL COUNTS
        // System.out.println(net.TOWER_CLIENT_COUNT("T1")); // ?
        // System.out.println(net.TOWER_CLIENT_COUNT("T2")); // ?
        // System.out.println(net.TOWER_CLIENT_COUNT("T3")); // ?

        // // MOVE_CLIENT
        // net.MOVE_CLIENT(123456, 15, 15);

        // System.out.println(net.TOWER_CLIENT_COUNT("T1")); // ?
        // System.out.println(net.TOWER_CLIENT_COUNT("T2")); // ?

        // // CHANGE_OPERATOR
        // net.CHANGE_OPERATOR(789012, "OperatorB");

        // // System.out.println("TOWER_CLIENT_COUNT");
        // System.out.println(net.TOWER_CLIENT_COUNT("T2")); // ?
        // System.out.println(net.TOWER_CLIENT_COUNT("T3")); // ?

        // // REMOVE_TOWER
        // net.REMOVE_TOWER("T2");

        // // System.out.println("TOWER_CLIENT_COUNT");
        // System.out.println(net.TOWER_CLIENT_COUNT("T2")); // ?
        // System.out.println(net.TOWER_CLIENT_COUNT("T3")); // ?

        // // REMOVE_CLIENT
        // net.REMOVE_CLIENT(987654);

        // // System.out.println("OPERATOR COUNTS");
        // // OPERATOR COUNTS
        // System.out.println(net.OPERATOR_SUBSCRIBER_COUNT("OperatorA"));
        // System.out.println(net.OPERATOR_SUBSCRIBER_COUNT("OperatorB"));

        // // NO SIGNAL
        // net.NO_SIGNAL_COUNT();

        // // ///////////////////////
        // // second set of tests
        // // ///////////////////////

        // Network netB = new Network();

        // // ADD_OPERATOR
        // netB.ADD_OPERATOR("OpX");
        // netB.ADD_OPERATOR("OpY");

        // // ADD_TOWER
        // netB.ADD_TOWER("T100", 10, 10, 10);
        // netB.ADD_TOWER("T200", 30, 30, 10);

        // // // REGISTER_OPERATOR_TOWER
        // netB.REGISTER_OPERATOR_TOWER("OpX", "T100");
        // netB.REGISTER_OPERATOR_TOWER("OpY", "T200");

        // // // ADD_CLIENT
        // netB.ADD_CLIENT(555001, "OpX", 12, 12);
        // netB.ADD_CLIENT(555002, "OpX", 5, 5);
        // netB.ADD_CLIENT(555003, "OpY", 35, 35);
        // netB.ADD_CLIENT(555004, "OpY", 50, 50);

        // // // INITIAL COUNTS
        // // System.out.println("INITIAL COUNTS, 2, 1");
        // System.out.println(netB.TOWER_CLIENT_COUNT("T100")); // 2
        // System.out.println(netB.TOWER_CLIENT_COUNT("T200")); // 1

        // // move client
        // netB.MOVE_CLIENT(555002,25, 25);

        // System.out.println(netB.TOWER_CLIENT_COUNT("T100")); // 1
        // System.out.println(netB.TOWER_CLIENT_COUNT("T200")); // 1

        // // change operator
        // netB.CHANGE_OPERATOR(555002, "OpY");

        // System.out.println(netB.TOWER_CLIENT_COUNT("T100")); // 1
        // System.out.println(netB.TOWER_CLIENT_COUNT("T200")); // 1

        // // remove tower
        // netB.REMOVE_TOWER("T100");

        // System.out.println(netB.TOWER_CLIENT_COUNT("T100")); // 1
        // System.out.println(netB.TOWER_CLIENT_COUNT("T200")); // 2
 
        // // 2 0 2 1 2 1wo signal 0 wosignal

        // // REMOVE_CLIENT
        // netB.REMOVE_CLIENT(555004);

        // System.out.println(netB.OPERATOR_SUBSCRIBER_COUNT("OpX"));
        // System.out.println(netB.OPERATOR_SUBSCRIBER_COUNT("OpY"));

        // netB.NO_SIGNAL_COUNT(); 

        // 2 1 1 1 1 2 0 2 1 2
        // 2 1 1 1 1 2 0 2 1 2
        // OpX: 1 phones without signal.
        // OpY: 0 phones without signal.

        // 2 1 1 1 1 2 0 2 1 2
        // OpX: 1 phones without signal.
        // OpY: 0 phones without signal.

        // MOVE_CLIENT
        // CHANGE_OPERATOR
        // TOWER_CLIENT_COUNT
        // OPERATOR_SUBSCRIBER_COUNT
        // ADD_CLIENT
        // REMOVE_CLIENT
        // ADD_TOWER
        // REGISTER_OPERATOR_TOWER
        // REMOVE_TOWER
        // NO_SIGNAL_COUNT
        
    }
}
