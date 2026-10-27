#pragma once

#include <stdexcept>

class BankAccount {
public:
    explicit BankAccount(double balance)
        : balance(balance) {
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Invalid amount");
        }

        balance += amount;
    }

    double getBalance() const {
        return balance;
    }

    virtual ~BankAccount() = default;

protected:
    double balance;
};

class WithdrawableAccount : public BankAccount {
public:
    using BankAccount::BankAccount;

    virtual void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            throw std::invalid_argument("Invalid amount");
        }

        balance -= amount;
    }
};

class SavingsAccount : public WithdrawableAccount {
public:
    using WithdrawableAccount::WithdrawableAccount;
};

class FixedDepositAccount : public BankAccount {
public:
    using BankAccount::BankAccount;
};
