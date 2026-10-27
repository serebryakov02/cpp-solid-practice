#include "NotificationService.h"

int main() {
    EmailSender email;
    SMSSender sms;

    NotificationService notifService(email);
    notifService.notify("Your report is ready.");

    return 0;
}
