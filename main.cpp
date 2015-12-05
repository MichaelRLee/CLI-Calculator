#include <iostream> // cout, cin
#include <string.h> // strcmp

using namespace std;

enum
{

};

/* Forward declarations */
bool validate(string toCheck); // Declare the prototype so that it can be used in main

int main()
{
    bool reading = true; // Controls input loop
    char input[256]; // The user input
    ArithmeticExpression ae = new ArithmeticExpression(); // Create the top-level expression

    while (reading) // Read until user quits
    {
        cout << "Please enter an expression: "; // Print the prompt for the user
        cin.getline(input, 256); // Get a line from the user

        if (!strcmp(input, "#")) // Check for the input which terminates the program (#)
        {
            reading = false; // End the input loop
        }

        /**
        * The user's input was not a message to quit, so we need to first validate and then parse the expression.
        **/
        else
        {
            /* Only proceed if the input is valid */

            if (validate(input)) // The expression is valid
            {
                cout << "Your expression is valid!" << endl; // Test code
            }

            else // The expression is invalid
            {
                cout << "Error: your expression is invalid!" << endl; // Test code
            }
        }
    }
}

/** \brief Parses a string into an ArithmeticExpression.
 *
 * \param expr The expression to parse.
 * \param startIndex The current index in the expression
 * \param recursionLevel The recursion level at which this function is.
 * \param mode The current BEDMAS mode { 0 = Brackets, 1 = D/M, 2 = A/S }
 * \return The arithmetic expression.
 *
 *  ALGORITHM
 *  ---------
 *  1) Handle brackets by recursing every time you see a '('. (B of BEDMAS)
 *      a) After reading '(', while we haven't read a ')':
 *          i) Read characters until you see a ')'. Check for invalid characters (Work this out later).
 *  2) Handle multiplication and division by recursing and parsing the string generated in 1a). Use a similar algorithm to 1a). (D & M of BEDMAS)
 *  3) Handle addition and subtraction by recursing and parsing the string generated in 2a). Use a similar algorithm to 1a). (A & S o BEDMAS)
 */
ArithmeticExpression buildExpression(string expr, int startIndex, int recursionLevel, int mode)
{
    ArithmeticExpression x;
    return x;
}

/** \brief Determines whether a given character is an operator.
 *
 * \param toCheck The character to check
 * \return True if the character is an operator, false otherwise.
 *
 */

bool isOperator(char toCheck)
{
    return toCheck == '+' || toCheck == '-' || toCheck == '*' || toCheck == '/'; // The character is an operator if one of these conditions is true
}
