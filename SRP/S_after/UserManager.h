#pragma once
#include <algorithm>
#include <vector>
#include "User.h"
#include "UserValidation.h"

class UserManager {
public:
    bool addUser(const User& user) {
        if (UserValidation::isValid(user)) {
            int id = user.id;
            bool exists = std::any_of(users.begin(), users.end(), [id](const User& user) {
                return user.id == id;
                }
            );

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
        return users;;
    }

private:
    std::vector<User> users;
};