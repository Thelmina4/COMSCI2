interface PaymentProcessor {
    void processPayment(Double amount);
}

class PayPal implements PaymentProcessor {
    // always public
    public void processPayment(Double amount) {
        System.out.println("process PayPal payment of :" + 10L);
    }
}

class CreditCard implements PaymentProcessor {
    // always public
    public void processPayment(Double amount) {
        System.out.println("process CreditCard payment of :" + 10L);
    }
}