
#include <iostream>
#include "BankAccount.h"


void processWithdrawal(WithdrawableAccount& account, double amount) {
    account.withdraw(amount);

    std::cout << "Withdrawal successful. Balance: "
        << account.getBalance() << '\n';
}

int main() {
    SavingsAccount savings(1000);
    FixedDepositAccount fixed(1000);

    processWithdrawal(savings, 200);

    return 0;
}
