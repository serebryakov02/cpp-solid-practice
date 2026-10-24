#include <iostream>

class Printer {
public:
    virtual ~Printer() = default;
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

class BasicPrinter : public Printer {
public:
    void print() override {
        std::cout << "Printing...\n";
    }

    void scan() override {
        // This printer cannot scan.
    }

    void fax() override {
        // This printer cannot fax.
    }
};
