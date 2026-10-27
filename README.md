# C++ SOLID Practice

A collection of practical C++ exercises exploring the five SOLID principles of object-oriented design.

The goal is to understand how these principles apply to real code through hands-on refactoring.

> **NOTE: THESE EXAMPLES FOCUS ON SOLID PRINCIPLES.**
> They use `double` for monetary values and simplify validation and file error handling to keep the focus on design.

## Principles

### SRP — Single Responsibility Principle

**Problem:** `UserManager` handles too many responsibilities: managing users, validating their data, generating reports, and saving information to files.

**Solution:** I separated these responsibilities into dedicated classes: `UserValidation`, `UserReportPrinter`, and `UserFileStorage`. Now each class has a clear purpose, and changes to validation, reporting, or file storage do not require modifying the other components.

### OCP — Open/Closed Principle

**Problem:** `PaymentProcessor` uses conditional statements to handle different payment methods. Adding a new payment method requires modifying the existing implementation.

**Solution:** I introduced a common payment-processing interface through an abstract base class and moved payment-specific behavior into derived classes. Now new payment methods can be introduced without modifying the existing processing logic.

### LSP — Liskov Substitution Principle

**Problem:** `FixedDepositAccount` inherits `withdraw()` from `BankAccount`, even though fixed deposit accounts do not support withdrawals. As a result, it cannot safely replace its base class in code that expects withdrawals to work.

**Solution:** I separated withdrawal functionality into `WithdrawableAccount`. Only accounts that support withdrawals inherit from it, while `FixedDepositAccount` retains the common account functionality. This ensures that every account passed to withdrawal-related code actually supports the operation.

### ISP — Interface Segregation Principle

**Problem:** `BasicPrinter` is forced to implement `scan()` and `fax()`, even though it does not support these operations.

**Solution:** I split the original interface into smaller, focused interfaces: `DocumentDevice`, `ScannerDevice`, and `FaxDevice`. Now each device implements only the functionality it supports, and clients depend only on the interfaces they actually need.

### DIP — Dependency Inversion Principle

**Problem:** `NotificationService` depends directly on `EmailSender`, making it tightly coupled to one notification method. Supporting SMS or another implementation would require changing the service.

**Solution:** I introduced the `INotification` abstraction and made `NotificationService` depend on it instead of a concrete sender. The required implementation is provided through the constructor, allowing different notification methods to be used without modifying the service.

## Repository Structure

Each principle has its own directory:

| Principle | Before | After |
| --- | --- | --- |
| SRP | [S_before.cpp](SRP/S_before.cpp) | [S_after/](SRP/S_after/) |
| OCP | [O_before.cpp](OCP/O_before.cpp) | [O_after/](OCP/O_after/) |
| LSP | [L_before.cpp](LSP/L_before.cpp) | [L_after/](LSP/L_after/) |
| ISP | [I_before.cpp](ISP/I_before.cpp) | [I_after/](ISP/I_after/) |
| DIP | [D_before.cpp](DIP/D_before.cpp) | [D_after/](DIP/D_after/) |

The `*_before.cpp` files are code snippets without a `main()` function. Each `*_after/` directory contains a header with the refactored classes and a runnable `main.cpp`.

## How to Use

1. Start by examining a before snippet and identifying potential design problems.
2. Try refactoring the code yourself.
3. Compare your solution with the header in the corresponding after directory.
4. Run its `main.cpp` demo and consider how the changes affect maintainability, extensibility, and coupling.

## Build and Run

A C++ compiler with C++20 support is required.

From the repository root, build the examples:

```sh
mkdir -p build
c++ -std=c++20 SRP/S_after/main.cpp -o build/srp
c++ -std=c++20 OCP/O_after/main.cpp -o build/ocp
c++ -std=c++20 LSP/L_after/main.cpp -o build/lsp
c++ -std=c++20 ISP/I_after/main.cpp -o build/isp
c++ -std=c++20 DIP/D_after/main.cpp -o build/dip
```

Run the examples from the build directory:

```sh
cd build
./srp
./ocp
./lsp
./isp
./dip
```

The SRP demo creates `users.txt` in its working directory.

The examples are intended for learning and experimentation rather than production use.
