# Factorial - Big Numbers Factorial Calculator

## Overview

This project demonstrates how to calculate the factorial of gigantic numbers using a simple and efficient algorithm. It can compute results with tens of thousands of digits, showcasing advanced big-number handling in C.

A mathematical trick is included to predict the "size" of the resulting number before computation, optimizing execution.

---

## Screenshot

![Factorial Calculator](https://github.com/engjango/fatorial/blob/main/screenshot.png?raw=true)

---

## Features

- Computes gigantic factorials (e.g., `10000!`).
- Displays real-time execution progress.
- Stores the result in an array to handle numbers larger than standard integer types.
- Simple, well-documented code for learning and experimentation.

---

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/engjango/fatorial.git
   cd fatorial
   ```
2. Compile the code:
   ```bash
   gcc big-fac.c -o big-fac
   ```
3. Run the program:
   ```bash
   ./big-fac
   ```
4. Enter a number when prompted (e.g., ```10000```) and wait for the calculation to complete.

## Requirements
- C Compiler (e.g., GCC or Clang)
- Windows, Linux, or macOS operating system
- Sufficient memory to handle the size specified in ```MAX_DIGITS_NUMBER```

## Important Note
To calculate even larger factorials, adjust the ```MAX_DIGITS_NUMBER``` constant in the source code to allocate enough space for the result.

## License
This project is in the Public Domain, allowing you to use, modify, and distribute it freely. For more details, see the [LICENSE](LICENSE.md) file.
