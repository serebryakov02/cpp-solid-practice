#include <iostream>
#include <memory>
#include <typeinfo>
#include "PrinterDevices.h"


int main()
{
    std::unique_ptr<DocumentDevice> officePrinter = std::make_unique<OfficePrinter>();
    auto mfPrinter = std::make_unique<MultiFunctionPrinter>();
    std::cout << typeid(mfPrinter).name() << std::endl;

    Document doc{ "FINNALY it should be working now" };

    printDocument(*officePrinter, doc);
    printDocument(*mfPrinter, doc);

    mfPrinter->fax(doc, "5");

    return 0;
}