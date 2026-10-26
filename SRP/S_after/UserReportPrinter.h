#pragma once
#include <iostream>
#include <vector>
#include "User.h"

class UserReportPrinter {
public:
    static void printReport(const std::vector<User>& users) {
        std::cout << "=== User Report ===\n";

        for (const auto& user : users) {
            std::cout << user.id << ": "
                << user.name << " ("
                << user.email << ")\n";
        }
    }
};