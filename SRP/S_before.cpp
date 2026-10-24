#include <iostream>
#include <string>
#include <vector>

struct User {
    int id;
    std::string name;
};

class UserManager {
public:
    void addUser(const User& user) {
        if (user.name.empty()) {
            std::cout << "Invalid user\n";
            return;
        }
        users.push_back(user);
        std::cout << "Added: " << user.name << '\n';
    }

    void printUsers() const {
        for (const auto& user : users)
            std::cout << user.id << ": " << user.name << '\n';
    }

    void saveUsers() const {
        std::cout << "Saving users to a file...\n";
    }

private:
    std::vector<User> users;
};
