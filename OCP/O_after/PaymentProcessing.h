#pragma once


#include <iostream>

struct Payment {
    double amount;
};

class PaymentProcessor {
public:
    bool process(const Payment& payment) {
        if (payment.amount <= 0) {
            std::cout << "Invalid payment amount\n";
            return false;
        }

        processPaymentImpl(payment);

        return true;

    }
    
    virtual ~PaymentProcessor() {}

protected:
    virtual void processPaymentImpl(const Payment& payment) = 0;
};

class CreditCardPayment : public PaymentProcessor {
protected:
    void processPaymentImpl(const Payment& payment) override {
        std::cout << "Processing CreditCardPayment : "
                    << payment.amount << '\n';
    }
};

class PayPalPayment : public PaymentProcessor {
protected:
    void processPaymentImpl(const Payment& payment) override {
        std::cout << "ProcessingPayPalPayment : "
            << payment.amount << '\n';
    }
};

class BankTransferPayment : public PaymentProcessor {
protected:
    void processPaymentImpl(const Payment& payment) override {
        std::cout << "BankTransferPayment : "
            << payment.amount << '\n';
    }
};

class CryptoPayment : public PaymentProcessor {
protected:
    void processPaymentImpl(const Payment& payment) override {
        std::cout << "CryptoPayment : "
            << payment.amount << '\n';
    }
};