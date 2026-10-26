#include <iostream>
#include <vector>
#include "NotificationService.h"

int main()
{
    EmailSender email;
    SMSSender sms;


    NotificationService notifService(email);
    notifService.notify("Hi!");

    return 0;
}