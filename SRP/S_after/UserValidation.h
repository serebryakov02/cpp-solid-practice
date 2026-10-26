#pragma once
#include <string>
#include "User.h"

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