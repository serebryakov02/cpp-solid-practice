#include <stdexcept>

class BankAccount {
public:
    explicit BankAccount(double balance) : balance(balance) {}
    virtual ~BankAccount() = default;

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount > balance)
            throw std::runtime_error("Insufficient funds");
        balance -= amount;
    }

protected:
    double balance;
};

class SavingsAccount : public BankAccount {
public:
    using BankAccount::BankAccount;
};

class FixedDepositAccount : public BankAccount {
public:
    using BankAccount::BankAccount;

    void withdraw(double) override {
        throw std::runtime_error("Withdrawals are not allowed");
    }
};
