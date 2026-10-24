#include <iostream>
#include <string>

class PaymentProcessor {
public:
    void processPayment(const std::string& method, double amount) {
        if (amount <= 0) {
            std::cout << "Invalid amount\n";
            return;
        }

        if (method == "credit_card") {
            std::cout << "Processing credit card payment\n";
        } else if (method == "paypal") {
            std::cout << "Processing PayPal payment\n";
        } else if (method == "bank_transfer") {
            std::cout << "Processing bank transfer\n";
        } else {
            std::cout << "Unsupported payment method\n";
        }
    }
};
