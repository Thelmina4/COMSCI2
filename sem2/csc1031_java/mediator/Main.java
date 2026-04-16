// package mediator;

import java.util.Queue;
import java.util.LinkedList;

interface Mediator {

}

class Patient {
    // A patient arrives with a condition:
    // Print: Patient <name> arrived with <condition>.

    // variables
    private String name;
    private String injury;
    // constructor
    public Patient(String name) {
        this.name = name;
    }

    // getters
    public String getName() {return name;}

    public String getInjury() {return injury;}
    // setters

    // methods
    // arrive
    public void arrive(String injury, ERCoordinator er) {
        this.injury = injury;
        System.out.println("Patient " + name + " arrived with " + injury + ".");
        er.addPatient(this);
    }

}

class Doctor {
    // A doctor becomes available:
    // Print: Doctor <doctor-id> is now available.

    // A doctor can:

    // Accept a patient:
    //       Doctor <doctor-id> is treating <patient-name>.
    // Reject a patient (maybe too complex case):
    //       Doctor <doctor-id> cannot treat <patient-name>. Looking for another doctor...

    // variables
    private String id;
    private boolean available;
    private ERCoordinator er;
    private Patient patient;

    // constructor
    public Doctor(String id) {
        this.id = id;
    }

    // getters
    public String getID() {return id;}

    public Patient getPatient() {return patient;}

    // setters

    // methods
    // 
    public void setPatient(Patient p) {
        patient = p;
        available = false;
    }

    public void setER(ERCoordinator er) {this.er = er;}

    // setAvailable
    public void setAvailable(boolean bool) {
        available = bool;
        if (available) {
            System.out.println("Doctor " + id + " is now available.");
            er.addDoctor(this);
        }
    }

    // respondToPatient
    public void respondToPatient(boolean bool) {
        if (patient == null) {return;}
        if (available && bool) {
            System.out.println("Doctor " + patient.getName() + " is treating Mary.");
            patient = null;
        } else {
            System.out.println("Doctor " + id + " cannot treat " + patient.getName() + ". Looking for another doctor...");
            patient = null;
        }
    }
}

class ERCoordinator {
    // Assign a doctor when:

    // A patient arrives AND a doctor is available
    // A doctor becomes available AND patients are waiting

    // Coordinator assigned Doctor <doctor-id> to Patient <patient-name>.
    // 
    // 4. Rejection logic
    // If a doctor rejects:
    // Doctor goes to end of doctor queue
    // Patient goes to front of patient queue
    // Immediately try reassignment

    Queue<Patient> patientQueue = new LinkedList<>();
    Queue<Doctor> doctorQueue = new LinkedList<>();

    // getters

    // setters

    // registerDoctor
    public void registerDoctor(Doctor doc) {
        doc.setER(this);
    }
    
    public void addPatient(Patient p) {
        patientQueue.add(p);
        work();
    }

    public void addDoctor(Doctor d) {
        doctorQueue.add(d);
        work();    
    }

    private void work() {
        if (!patientQueue.isEmpty() && !doctorQueue.isEmpty()) {
            Doctor doc = doctorQueue.poll();
            Patient p = patientQueue.poll();
            System.out.println("Coordinator assigned Doctor " + doc.getID() + " to Patient " + p.getName() + ".");
            doc.setPatient(p);

        }
    }
    public void handleRejection(Doctor d, Patient p) {
        doctorQueue.add(d);

        Queue<Patient> tmp = new LinkedList<>();
        tmp.add(p);
        while (!patientQueue.isEmpty()) {
            tmp.add(patientQueue.poll());
        }
        patientQueue = tmp;
        work();
    }
}


public class Main {
    public static void main(String[] args) {
        ERCoordinator er = new ERCoordinator();

        Patient p1 = new Patient("John");
        Patient p2 = new Patient("Mary");

        Doctor d1 = new Doctor("Dr-01");
        Doctor d2 = new Doctor("Dr-02");
        Doctor d3 = new Doctor("Dr-03");

        er.registerDoctor(d1);
        er.registerDoctor(d2);
        er.registerDoctor(d3);

        p1.arrive("Broken Arm", er);
        p2.arrive("Head Injury", er);

        d1.setAvailable(true);
        d2.setAvailable(true);
        d3.setAvailable(true);

        d1.respondToPatient(true);   // accepts
        d2.respondToPatient(false);  // rejects
        d3.respondToPatient(true);   // takes reassigned patient
    }
}
