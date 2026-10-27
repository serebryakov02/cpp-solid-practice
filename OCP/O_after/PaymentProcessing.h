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

    virtual ~PaymentProcessor() = default;

protected:
    virtual void processPaymentImpl(const Payment& payment) = 0;
};

class CreditCardPayment : public PaymentProcessor {
protected:
    void processPaymentImpl(const Payment& payment) override {
        std::cout << "Processing credit card payment: "
            << payment.amount << '\n';
    }
};

class PayPalPayment : public PaymentProcessor {
protected:
    void processPaymentImpl(const Payment& payment) override {
        std::cout << "Processing PayPal payment: "
            << payment.amount << '\n';
    }
};

class BankTransferPayment : public PaymentProcessor {
protected:
    void processPaymentImpl(const Payment& payment) override {
        std::cout << "Processing bank transfer: "
            << payment.amount << '\n';
    }
};

class CryptoPayment : public PaymentProcessor {
protected:
    void processPaymentImpl(const Payment& payment) override {
        std::cout << "Processing crypto payment: "
            << payment.amount << '\n';
    }
};
