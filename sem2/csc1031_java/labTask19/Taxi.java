// package labTask19;

// MEDIATOR
// /////////////////
// Passengers request taxi rides, and taxi drivers can accept or reject these requests.

// Important: Passengers and taxi drivers must NOT communicate directly.

// import java.util.ArrayList;
// import java.util.List;
import java.util.Queue;
import java.util.LinkedList;

// passenger / taxi
// interface Communications {
//     // passenger
//     void requestRide(String location, DispatchCenter dispatchCenter);
//     void setAvailable(boolean bool);
//     void respondToRide(boolean bool);
// }

// concrete users of the centre
class Passenger {
    // Request a taxi ride to a destination:

    // Print: Passenger <name> requested a ride to <destination>.

    // The Passenger does not maintain a reference to the DispatchCenter,
    //  as communication is one-directional.
    //  It only interacts with the DispatchCenter when requesting a ride,
    //  passing it as a parameter.
    //  All further coordination is handled by the DispatchCenter,
    //  ensuring loose coupling between system components.

    private String name;
    private String destination;

    public Passenger(String name) {
        this.name = name;
    }

    // No functional difference in this case. name ~ this.name
    // Both return the same thing.
    public String getName() {return name;}
    public String getdestination() {return this.destination;}

    public void requestRide(String destination, DispatchCenter dispatchCenter) {
        this.destination = destination;    
        System.out.println("Passenger " + name + " requested a ride to " + destination + ".");
        // this refers to the current DispatchCenter object
        // Without storing this, the Taxi would have no way to communicate back to the DispatchCenter.
        dispatchCenter.addPassenger(this);
    }
}

public class Taxi {
    // Notify the dispatch center when becoming available:
    // Print: Taxi <taxi-id> is now available.
    // Accept or reject ride assignments:
    // If accepted, print: Taxi <taxi-id> accepted the ride to <destination>.
    // If rejected, print: Taxi <taxi-id> rejected the ride to <destination>. Searching for another taxi…​

    private String taxiID;
    private boolean available;
    private DispatchCenter center;
    private Passenger passenger;

    public Taxi(String taxiID) {
        this.taxiID = taxiID;
    }
    // getters 
    public String getID() {return taxiID;}

    public void setDispachCentre(DispatchCenter centre) {
        this.center = centre;
    }

    public void setAvailable(boolean bool) {
        available = bool;
        if (available) {
            System.out.println("Taxi " + taxiID + " is now available.");
            center.addTaxi(this);
        }
    }

    public void assignPassenger(Passenger passenger) {
        this.passenger = passenger;
        this.available = false;
    }

    public void respondToRide(boolean bool) {
        // if there is no passenger, then return
        if (passenger == null) {return;} 
        // if accept = true?
        if (bool) {
            System.out.println("Taxi " + taxiID + " accepted the ride to " + passenger.getdestination() + ".");
            passenger = null;

        } else {
            System.out.println("Taxi " + taxiID + " rejected the ride to " + passenger.getdestination()+ ". Searching for another taxi...");
            center.handleRejection(this, passenger);
            passenger = null;
        }
        
    }
}
// Do I need to overrride the interface functions?
// It is considered a best practice because it lets the compiler check
//  that you actually correctly implemented the intended method.
//  If you make a typo (e.g., startEngin() instead of startEngine()),
//  the compiler will throw an error immediately rather than creating
//  a new, separate method.
interface Mediator {
    // Receive passenger ride requests and add to queue.
    // Manage taxi availability and add taxis to queue.
    // Assign passenger requests from queue to available taxis immediately upon either:
    // Taxi becoming available and passengers waiting in queue, or
    // Passenger request arriving while taxis are already available.
    // Print: Dispatch assigned Taxi <taxi-id> to passenger <passenger-name>.
    void registerTaxi(Taxi taxi);
    void handleRejection(Taxi taxi, Passenger passenger);
    void addPassenger(Passenger passenger);
    void addTaxi(Taxi taxi);
    void assignTaxi();

}

class DispatchCenter implements Mediator {
    // Receive passenger ride requests and add to queue.
    // Manage taxi availability and add taxis to queue.
    // Assign passenger requests from queue to available taxis immediately upon either:
    // Taxi becoming available and passengers waiting in queue, or
    // Passenger request arriving while taxis are already available.
    // Print: Dispatch assigned Taxi <taxi-id> to passenger <passenger-name>.

    //     Assignment of taxis to passengers occurs under two conditions:
    // When a taxi becomes available and there is at least one passenger waiting in the queue.
    // When a passenger requests a ride and there is at least one available taxi.

    Queue<Passenger> passengerQueue = new LinkedList<>();
    Queue<Taxi> taxiQueue = new LinkedList<>();

    // Main methods:
    // passengerQueue.add(passenger); // Adds passenger to the queue
    // passengerQueue.poll(); // Removes and returns the passenger at the front of the queue

    // taxiQueue.add(taxi); // Adds taxi to the queue
    // taxiQueue.poll(); // Removes and returns the taxi at the front of the queue

    // public DispatchCenter() {
    //     passengerQueue = new LinkedList<>();
    //     taxiQueue = new LinkedList<>();
    // }
    // registerTaxi(taxi1)
    @Override
    public void registerTaxi(Taxi taxi) {
        taxi.setDispachCentre(this);
    }
    @Override
    public void addPassenger(Passenger passenger) {
        passengerQueue.add(passenger);
        assignTaxi();
    }
    
    @Override
    public void addTaxi(Taxi taxi) {
        taxiQueue.add(taxi);
        assignTaxi();
    }

    @Override
    public void assignTaxi() {
        // if the queues are not empty
        // take the first passenget & 1st taxi
        // give the passanger to the taxi

        while (!passengerQueue.isEmpty() && !taxiQueue.isEmpty()) {
            Taxi taxi = taxiQueue.poll();
            Passenger passenger = passengerQueue.poll();
            System.out.println("Dispatch assigned Taxi " + taxi.getID() + " to passenger " + passenger.getName() + ".");
            taxi.assignPassenger(passenger);
        }
    }

    @Override
    public void handleRejection(Taxi taxi, Passenger passenger) {
        // put the taxi at the back of the queue
        taxiQueue.add(taxi);

        // put the rejected passenget back at the front of the line
        Queue<Passenger> tmp = new LinkedList<>();
        tmp.add(passenger);
        while (!passengerQueue.isEmpty()) {
            tmp.add(passengerQueue.poll());
        }

        passengerQueue = tmp;
        assignTaxi();
    }
}


// public class Main {
//     public static void main(String[] args) {
//         DispatchCenter dispatchCenter = new DispatchCenter();

//         Passenger alice = new Passenger("Alice");
//         Passenger bob = new Passenger("Bob");

//         Taxi taxi1 = new Taxi("Taxi-01");
//         Taxi taxi2 = new Taxi("Taxi-02");
//         Taxi taxi3 = new Taxi("Taxi-03");

//         dispatchCenter.registerTaxi(taxi1);
//         dispatchCenter.registerTaxi(taxi2);
//         dispatchCenter.registerTaxi(taxi3);

//         alice.requestRide("Airport", dispatchCenter);
//         bob.requestRide("Downtown", dispatchCenter);

//         taxi1.setAvailable(true);
//         taxi2.setAvailable(true);
//         taxi3.setAvailable(true);

//         taxi1.respondToRide(true); // Accept the ride
//         taxi2.respondToRide(false); // Reject the ride
//         taxi3.respondToRide(true); // Accept the rejected ride
//     }
// }


// Methods of Queue Interface
// Method	Description
// add(E e)	Inserts the specified element; throws exception if insertion fails.
// offer(E e)	Inserts the specified element; returns false if insertion fails.
// remove()	Removes and returns the head of the queue; throws exception if empty.
// poll()	Removes and returns the head; returns null if empty.
// peek()	Retrieves, but does not remove, the head; returns null if empty.
// size()	Returns the number of elements in the queue.
// isEmpty()	Returns true if the queue contains no elements.
// contains(Object o)	Returns true if the queue contains the specified element.
// iterator()	Returns an iterator over the elements in the queue.
// toArray()	Converts the queue elements into an array.
// addFirst(E e)	Inserts element at the front (Deque only).
// addLast(E e)	Inserts element at the end (Deque only).
// offerFirst(E e)	Inserts element at the front; returns false if fails (Deque only).
// offerLast(E e)	Inserts element at the end; returns false if fails (Deque only).
// removeFirst()	Removes and returns the first element (Deque only).
// removeLast()	Removes and returns the last element (Deque only).
// pollFirst()	Removes and returns the first element; returns null if empty (Deque only).
// pollLast()	Removes and returns the last element; returns null if empty (Deque only).
// getFirst()	Retrieves, but does not remove, the first element (Deque only).
// getLast()	Retrieves, but does not remove, the last element (Deque only).
// peekFirst()	Retrieves, but does not remove, the first element; returns null if empty (Deque only).
// peekLast()	Retrieves, but does not remove, the last element; returns null if empty (Deque only).
// put(E e)	Inserts element, waits if necessary (BlockingQueue only).
// take()	Removes and returns head element, waits if empty (BlockingQueue only).

// package mediator;


// doctor practice
// import java.util.Queue;
// import java.util.LinkedList;

// interface Mediator {

// }

// class Patient {
//     // A patient arrives with a condition:
//     // Print: Patient <name> arrived with <condition>.

//     // variables
//     private String name;
//     private String injury;
//     private String typeDoc;
//     // constructor
//     public Patient(String name) {
//         this.name = name;
//     }

//     // getters
//     public String getName() {return name;}

//     public String getInjury() {return injury;}

//     public String getDoc() {return typeDoc;}

//     // setters

//     // methods
//     // arrive
//     public void arrive(String injury, ERCoordinator er, String typeDoc) {
//         this.typeDoc = typeDoc;
//         this.injury = injury;
//         System.out.println("Patient " + name + " arrived with " + injury + ".");
//         er.addPatient(this);
//     }

// }

// class Doctor {
//     // A doctor becomes available:
//     // Print: Doctor <doctor-id> is now available.

//     // A doctor can:

//     // Accept a patient:
//     //       Doctor <doctor-id> is treating <patient-name>.
//     // Reject a patient (maybe too complex case):
//     //       Doctor <doctor-id> cannot treat <patient-name>. Looking for another doctor...

//     // variables
//     private String id;
//     private boolean available;
//     private ERCoordinator er;
//     private Patient patient;
//     private String specialty;

//     // constructor
//     public Doctor(String id, String specialty) {
//         this.id = id;
//         this.specialty = specialty;
//     }
//     public Doctor(String id) {
//         this.id = id;
//         this.specialty = "General Doc";
//     }


//     // getters
//     public String getID() {return id;}

//     public Patient getPatient() {return patient;}

//     public String getSpecialty() {return specialty;}

//     // setters
//     public void setSpecialty(String s) {
//         if (s != null && !s.trim().isEmpty()) {specialty = s;}      
//     }

//     // methods
//     // 
//     public void setPatient(Patient p) {
//         patient = p;
//         available = false;
//     }

//     public void setER(ERCoordinator er) {this.er = er;}

//     // setAvailable
//     public void setAvailable(boolean bool) {
//         available = bool;
//         if (available) {
//             System.out.println("Doctor " + id + " is now available.");
//             er.addDoctor(this);
//         }
//     }

//     // respondToPatient
//     public void respondToPatient(boolean bool) {
//         if (patient == null) {return;}
//         if (bool && (specialty.equals(patient.getDoc()))) {
//             System.out.println("specialty: " + specialty + "\ntypeDoc : " + patient.getDoc());
//             System.out.println("Doctor " + patient.getName() + " is treating Mary.");
//             patient = null;
//         } else {
//             System.out.println("specialty: " + specialty + "\ntypeDoc : " + patient.getDoc());
//             System.out.println(specialty.equals(patient.getDoc()));
//             System.out.println("Doctor " + id + " cannot treat " + patient.getName() + ". Looking for another doctor...");
//             patient = null;
//         }
//     }
// }

// class ERCoordinator {
//     // Assign a doctor when:

//     // A patient arrives AND a doctor is available
//     // A doctor becomes available AND patients are waiting

//     // Coordinator assigned Doctor <doctor-id> to Patient <patient-name>.
//     // 
//     // 4. Rejection logic
//     // If a doctor rejects:
//     // Doctor goes to end of doctor queue
//     // Patient goes to front of patient queue
//     // Immediately try reassignment

//     Queue<Patient> patientQueue = new LinkedList<>();
//     Queue<Doctor> doctorQueue = new LinkedList<>();

//     // getters

//     // setters

//     // registerDoctor
//     public void registerDoctor(Doctor doc) {
//         doc.setER(this);
//     }
    
//     public void addPatient(Patient p) {
//         patientQueue.add(p);
//         work();
//     }

//     public void addDoctor(Doctor d) {
//         doctorQueue.add(d);
//         work();    
//     }

//     private void work() {
//         if (!patientQueue.isEmpty() && !doctorQueue.isEmpty()) {
//             Doctor doc = doctorQueue.poll();
//             Patient p = patientQueue.poll();
//             System.out.println("Coordinator assigned Doctor " + doc.getID() + " to Patient " + p.getName() + ".");
//             doc.setPatient(p);

//         }
//     }
//     public void handleRejection(Doctor d, Patient p) {
//         doctorQueue.add(d);

//         Queue<Patient> tmp = new LinkedList<>();
//         tmp.add(p);
//         while (!patientQueue.isEmpty()) {
//             tmp.add(patientQueue.poll());
//         }
//         patientQueue = tmp;
//         work();
//     }
// }


// // public class Main {
// //     public static void main(String[] args) {
// //         ERCoordinator er = new ERCoordinator();

// //         Patient p1 = new Patient("John");
// //         Patient p2 = new Patient("Mary");

// //         Doctor d1 = new Doctor("Dr-01", "a");
// //         Doctor d2 = new Doctor("Dr-02", "b");
// //         Doctor d3 = new Doctor("Dr-03", "c");

// //         er.registerDoctor(d1);
// //         er.registerDoctor(d2);
// //         er.registerDoctor(d3);

// //         p1.arrive("Broken Arm", er, "a");
// //         p2.arrive("Head Injury", er, "b");

// //         d1.setAvailable(true);
// //         d2.setAvailable(true);
// //         d3.setAvailable(true);

// //         d1.respondToPatient(true);   // accepts
// //         d2.respondToPatient(false);  // rejects
// //         d3.respondToPatient(true);   // takes reassigned patient
        
// //         // String a = "a";
// //         // String b = "a";
// //         // System.out.println(a == b);    
// //     }
// // }


// package chain_of_responsibility;

// // Customer Support Ticket System
// // Level 1 Support → Level 2 Support → Manager
// // Each level decides:
// // Can I handle this?
// //  YES → handle it
// //  NO → pass to next handler

// abstract class SupportHandler {
//     protected SupportHandler next;

//     // availbe for all concrete classes
//     public void setNext(SupportHandler next) {
//         this.next = next;
//     }
//     // must be adapted by the concrete classes
//     public abstract void handleRequest(Ticket t);

// }

// class Level1Support extends SupportHandler {
//     private String issues = "password";
//     private String handler = "Level1";

//     @Override
//     public void handleRequest(Ticket t) {
//         if (t.getissueType().equals(issues)) {
//             System.out.println(handler + " handled " + issues + " issue for " + t.getName() + ".");
//         } else if (next != null){
//             System.out.println(handler + " cannot handle " + t.getissueType() + " issue. Passing to next level...");
//             next.handleRequest(t);
//         } else {
//             System.out.println("Issue type " + t.getissueType() + " could not be handled.");         
//         }
//     }
// }

// class Level2Support extends SupportHandler {
//     private String issues = "software";
//     private String handler = "Level2";

//     @Override
//     public void handleRequest(Ticket t) {
//         if (t.getissueType().equals(issues)) {
//             System.out.println(handler + " handled " + issues + " issue for " + t.getName() + ".");
//         } else if (next != null){
//             System.out.println(handler + " cannot handle " + t.getissueType() + " issue. Passing to next level...");
//             next.handleRequest(t);
//         } else {
//             System.out.println("Issue type " + t.getissueType() + " could not be handled.");         
//         }
//     } 
// }

// class Manager extends SupportHandler {
//     private String issues = "billing";
//     private String handler = "manager";

//     @Override
//     public void handleRequest(Ticket t) {
//         if (t.getissueType().equals(issues)) {
//             System.out.println(handler + " handled " + issues + " issue for " + t.getName() + ".");
//         } else if (next != null){
//             System.out.println(handler + " cannot handle " + t.getissueType() + " issue. Passing to next level...");
//             next.handleRequest(t);
//         } else {
//             System.out.println("Issue type " + t.getissueType() + " could not be handled.");         
//         }
//     }    
// }

// class Ticket {
//     private String customerName;
//     private String issueType;

//     public Ticket(String customerName, String issueType) {
//         this.customerName = customerName;
//         this.issueType = issueType;
//     }
//     public String getName() {return customerName;}
//     public String getissueType() {return issueType;}
// }
// public class Chain {
//     public static void main(String[] args) {

//         SupportHandler level1 = new Level1Support();
//         SupportHandler level2 = new Level2Support();
//         SupportHandler manager = new Manager();

//         // Build chain
//         level1.setNext(level2);
//         level2.setNext(manager);

//         // Tickets
//         Ticket t1 = new Ticket("Alice", "password");
//         Ticket t2 = new Ticket("Bob", "software");
//         Ticket t3 = new Ticket("Charlie", "billing");
//         Ticket t4 = new Ticket("Dave", "network");

//         level1.handleRequest(t1);
//         level1.handleRequest(t2);
//         level1.handleRequest(t3);
//         level1.handleRequest(t4);
//     }    
// }
