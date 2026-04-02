// NetworkSimulation.java

// single global cellular network consists of...

// - Cell Towers (Base Stations)
//      - each w  unique ID and specific coordinates (x, y).
//      - coverage radius that determines which phones it can connect
//      - A tower does not initially belong to any operator
//          but can be assigned to one later.

//  - Mobile Network Operators
//      - name
//      - list of clients(phones)
//      - list of allowed towers

//  - Clients (Mobile Phones)
//      - UNIQUE phone no
//      - current location, x y
//      - registered with a specific operator.
//      - connects to the nearest tower 
//          that supports its operator and is within range.
//      - no tower is within range, the phone has no signal.

// requirements:
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
// ADD_OPERATOR

// Use Classes:

// CellTower: Represents a network tower.

// Operator: Represents a mobile network operator.

// Client: Represents a mobile phone.

// Network: Manages all towers, operators, and clients.

// Algorithmic Considerations:

// Use the Pythagorean theorem to compute the distance between a phone and a tower:

// Evaluation Criteria
// Correctness: The system correctly assigns phones to the nearest available towers.

// Encapsulation: The system properly manages data using appropriate classes and methods.

// Efficiency: Efficient use of data structures for quick lookup and updates.

// Error Handling: Handles edge cases such as removing non-existent clients or towers.

// Code Readability: Code is well-structured, with meaningful class and method names.

import java.util.ArrayList;
import java.util.List;

public class NetworkSimulation {
    // ATTRIBUTES FOR SIMULATION

    // 1. list of celltowers to compare off new ones
MOVE_CLIENT
phone_number
new_x
new_y

CHANGE_OPERATOR
phone_number
new_operator_name

TOWER_CLIENT_COUNT
tower_id

OPERATOR_SUBSCRIBER_COUNT
operator_name - clientCount in operators

ADD_CLIENT
phone_number
operator_name
x
y



    public static void main(String[] argv) {
    // ADD_TOWER
    // T1
    // 0
    // 0
    // 10

    // ADD_TOWER
    // T2
    // 20
    // 20
    // 15

    // REGISTER_OPERATOR_TOWER
    // OperatorA
    // T1
    // REGISTER_OPERATOR_TOWER
    // OperatorA
    // T2
    // ADD_CLIENT
    // 123456
    // OperatorA
    // 5
    // 5
    // ADD_CLIENT
    // 789012
    // OperatorA
    // 25
    // 25
    // TOWER_CLIENT_COUNT
    // T1
    // TOWER_CLIENT_COUNT
    // T2
    // REMOVE_TOWER
    // T1
    // TOWER_CLIENT_COUNT
    // T1
    // TOWER_CLIENT_COUNT
    // T2
    // NO_SIGNAL_COUNT

    // Expected Output:

    // 1
    // 1
    // 0
    // 2
    // OperatorA: 0 phones without signal.
    }
}

// use binary search to find the closest tower?
// KD tree!!!