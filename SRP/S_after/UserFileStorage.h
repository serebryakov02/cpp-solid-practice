#pragma once
#include <vector>
#include <fstream>
#include "User.h"

class UserFileStorage {
public:
    static void saveToFile(const std::string& filename, const std::vector<User>& users) {
        std::ofstream file(filename);

        for (const auto& user : users) {
            file << user.id << ","
                << user.name << ","
                << user.email << "\n";
        }
    }
};