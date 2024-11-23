/*************************************************************************
 * big-fac.c
 *
 * Project:	Big-Numbers Factorial Simple Calculator
 * Author:	Janderson Gomes
 * Blog:	artientista.blogspot.com
 * E-mail:	dparicarana@gmail.com
 * 
 * Description:
 * A simple program to calculate the factorial of very large numbers,
 * capable of handling results with tens of thousands of digits.
 *
 * Disclaimer:
 * THIS SOFTWARE IS PROVIDED BY AUTHORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE. 
 ************************************************************************/

#include <stdio.h>

// Maximum number of digits the result can hold (e.g., up to 10,000!)
#define MAX_DIGITS_NUMBER 40000 /* Adjust based on README instructions */

/* Note: This algorithm is not optimized for calculating the factorial 
 * of arbitrary numbers. The variable MAX_DIGITS_NUMBER must be adjusted 
 * to ensure enough memory is allocated for the result.
 */

int main()
{
    // Array to store the digits of the result
    char result[MAX_DIGITS_NUMBER]; 

    // Auxiliary variables
    int i, j, number, dcounter, carry, tmp;

    // User input
    printf("Factorial Simple Calculator\n\n");
    printf("Enter a number (e.g., 10000): ");
    scanf("%d", &number);

    // Initialize the result array with the first digit (1)
    result[0] = 1;

    // Initialize the digit counter (starting with 1 digit)
    dcounter = 1;

    // Initialize the carry to zero
    carry = 0;

    // Empty line for clarity
    puts("");

    // Loop through numbers from 1 to the input number
    for (i = 1; i <= number; i++)
    {
        // Multiply each digit in the result array by the current number
        for (j = 0; j < dcounter; j++)
        {
            tmp = result[j] * i + carry; // Multiply and add carry
            result[j] = tmp % 10;        // Store the single digit
            carry = tmp / 10;            // Update the carry
        }

        // Handle any leftover carry
        while (carry > 0)
        {
            result[dcounter] = carry % 10;
            carry /= 10;
            dcounter++;
        }

        // Display progress to the user
        printf("\r%d digits calculated...", dcounter);
    }

    // Empty line for output formatting
    puts("");

    // Display the factorial result
    printf("\nFactorial of %d is:\n\n", number);
    for (i = dcounter - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }

    // Return successful exit code
    return 0;
}
