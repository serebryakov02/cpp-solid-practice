#include <iostream>
#include "UserManager.h"
#include "UserReportPrinter.h"
#include "UserFileStorage.h"

int main()
{
    std::cout << "Test\n";

    User user1{ 1, "Mykyta", "mykyta@email.com" };
    User user2{ 2, "Julie", "julie@email.com" };

    UserManager um;
    um.addUser(user1);
    um.addUser(user2);
    UserReportPrinter::printReport(um.getUsers());

    UserFileStorage::saveToFile("users.txt", um.getUsers());

    return 0;
}