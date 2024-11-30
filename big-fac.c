/*************************************************************************
 * big-fac.c
 * 
 * Project: Big-Positive-Numbers Factorial Calculator
 * Author: @jndgomes
 * 
 * Description:
 * This program calculates the factorial of very large numbers, capable of
 * handling results with tens of thousands of digits. The number of digits
 * is estimated using Stirling's approximation.
 * 
 * Disclaimer:
 * THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND.
 * 
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    // Variable to store the estimated maximum number of digits
    int MAX_DIGITS_NUMBER;

    // Auxiliary variables
    int i, j, number, dcounter, carry, tmp;

    // User input
    printf("Large Number Factorial Calculator\n\n");
    printf("Enter a number (e.g., 1993): ");
    scanf("%d", &number);

    // Estimate the number of digits in the factorial using Stirling's formula
    MAX_DIGITS_NUMBER = (int)(
        (log(2 * M_PI) / 2 + log(number) / 2 + number * (log(number) - 1)) / log(10)
    ) + 1;

    // Allocate an array to hold the digits of the result
    char result[MAX_DIGITS_NUMBER];

    // Initialize the result with the value 1 (the factorial of 0 or 1)
    result[0] = 1;

    // Initialize the digit counter and carry-over variable
    dcounter = 1;
    carry = 0;

    // Print an empty line for formatting
    puts("");

    // Main factorial computation loop
    for (i = 1; i <= number; i++) {
        for (j = 0; j < dcounter; j++) {
            // Multiply the current digit by i and add the carry
            tmp = result[j] * i + carry;
            // Update the current digit
            result[j] = tmp % 10;
            // Update the carry for the next digit
            carry = tmp / 10;
        }

        // Add remaining carry digits to the result array
        while (carry > 0) {
            result[dcounter] = carry % 10;
            carry /= 10;
            dcounter++;
        }

        // Display progress (number of digits calculated so far)
        printf("\r%d digits calculated...", dcounter);
    }

    // Print an empty line for formatting
    puts("");

    // Display the factorial result
    printf("\nFactorial of %d is:\n\n", number);
    for (i = dcounter - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }

    // Exit the program successfully
    return 0;
}
