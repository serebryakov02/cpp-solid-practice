#include <memory>

#include "PrinterDevices.h"

int main() {
    std::unique_ptr<DocumentDevice> officePrinter = std::make_unique<OfficePrinter>();
    auto mfPrinter = std::make_unique<MultiFunctionPrinter>();

    Document doc{"Quarterly report"};

    printDocument(*officePrinter, doc);
    printDocument(*mfPrinter, doc);

    mfPrinter->fax(doc, "555-0100");

    return 0;
}
