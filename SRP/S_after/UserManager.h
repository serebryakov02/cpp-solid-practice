#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct User {
    int id;
    std::string name;
    std::string email;
};

class UserValidation {
public:
    static bool isValid(const User& user) {
        if (user.name.empty() ||
            user.email.find('@') == std::string::npos) {
            return false;
        }
        return true;
    }
};

class UserManager {
public:
    bool addUser(const User& user) {
        if (UserValidation::isValid(user)) {
            int id = user.id;
            bool exists = std::any_of(users.begin(), users.end(), [id](const User& user) {
                return user.id == id;
            });

            if (!exists) {
                users.push_back(user);
                return true;
            }
        }
        return false; // The caller decides how to handle or report the failure.
    }

    void removeUser(int id) {
        std::erase_if(users, [id](const User& user) {
            return user.id == id;
        });
    }

    const std::vector<User>& getUsers() const {
        return users;
    }

private:
    std::vector<User> users;
};

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
