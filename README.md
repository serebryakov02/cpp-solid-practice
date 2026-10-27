# C++ SOLID Practice

A collection of practical C++ exercises exploring the five SOLID principles of object-oriented design.

The goal is to understand how these principles apply to real code through hands-on refactoring.

> **NOTE: THESE EXAMPLES FOCUS ON SOLID PRINCIPLES.**
> They use `double` for monetary values and simplify validation and file error handling to keep the focus on design.

## Principles

- **S** - Single Responsibility Principle (SRP)
- **O** - Open/Closed Principle (OCP)
- **L** - Liskov Substitution Principle (LSP)
- **I** - Interface Segregation Principle (ISP)
- **D** - Dependency Inversion Principle (DIP)

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
