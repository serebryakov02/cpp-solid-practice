#include "UserManager.h"

int main() {
    User user1{1, "Mykyta", "mykyta@example.com"};
    User user2{2, "Julie", "julie@example.com"};

    UserManager um;
    um.addUser(user1);
    um.addUser(user2);
    UserReportPrinter::printReport(um.getUsers());

    UserFileStorage::saveToFile("users.txt", um.getUsers());

    return 0;
}
