#pragma once

#include <iostream>
#include <string>

struct Document {
    std::string content;
};

class DocumentDevice {
public:
    virtual void print(const Document& doc) = 0;

    virtual ~DocumentDevice() = default;
};

class FaxDevice {
public:

    virtual void fax(const Document& doc, const std::string& number) = 0;

    virtual ~FaxDevice() = default;
};

class ScannerDevice {
public:

    virtual  void scan(Document& doc) = 0;
    virtual ~ScannerDevice() = default;
};

class OfficePrinter : public DocumentDevice {
public:
    void print(const Document& doc) override {
        std::cout << "Printing: " << doc.content << '\n';
    }
};

class MultiFunctionPrinter : public DocumentDevice, public FaxDevice, public ScannerDevice {
public:
    void print(const Document& doc) override {
        std::cout << "Printing: " << doc.content << '\n';
    }

    void scan(Document& doc) override {
        doc.content = "Scanned document";
    }

    void fax(const Document& doc, const std::string& number) override {
        std::cout << "Faxing to " << number << '\n';
    }
};

// Avoid duplicate symbols when included in multiple .cpp files.
inline void printDocument(DocumentDevice& device, const Document& doc) {
    device.print(doc);
}
