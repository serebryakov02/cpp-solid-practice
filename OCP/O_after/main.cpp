#include <memory>
#include <vector>

#include "PaymentProcessing.h"

int main() {
    Payment payment{200};

    std::vector<std::unique_ptr<PaymentProcessor>> payments;

    payments.emplace_back(std::make_unique<CreditCardPayment>());
    payments.emplace_back(std::make_unique<PayPalPayment>());
    payments.emplace_back(std::make_unique<BankTransferPayment>());
    payments.emplace_back(std::make_unique<CryptoPayment>());

    for (const auto& p : payments) {
        p->process(payment);
    }

    return 0;
}
