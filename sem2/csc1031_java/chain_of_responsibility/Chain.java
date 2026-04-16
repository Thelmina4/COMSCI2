// // package chain_of_responsibility;

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
