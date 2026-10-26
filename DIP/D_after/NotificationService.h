#pragma once
#include <iostream>
#include <string>

class INotification {
public:
    virtual void send(const std::string& message) const = 0;

    virtual ~INotification() = default;
};

class EmailSender : public INotification {
public:
    void send(const std::string& message) const override {
        std::cout << "Email: " << message << '\n';
    }
};

class SMSSender : public INotification {
public:
    void send(const std::string& message) const override {
        std::cout << "SMS: " << message << '\n';
    }
};

class NotificationService {
public:
    NotificationService(const INotification& notification) : m_notif(notification) {

    }

    void notify(const std::string& message) {
        m_notif.send(message);
    }

private:
    const INotification& m_notif;
};