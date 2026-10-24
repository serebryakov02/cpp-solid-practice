#include <iostream>
#include <string>

class EmailSender {
public:
    void send(const std::string& message) {
        std::cout << "Email: " << message << '\n';
    }
};

class NotificationService {
public:
    void notify(const std::string& message) {
        sender.send(message);
    }

private:
    EmailSender sender;
};
