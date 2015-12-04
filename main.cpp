#include <iostream> // cout, cin
#include <string.h> // strcmp

using namespace std;

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
 * \return The arithmetic expression.
 *
 */
ArithmeticExpression buildExpression(string expr, int startIndex, int recursionLevel)
{
    ArithmeticExpression curExp; // The expression which will be returned by this function.
    int i = startIndex; // Current index in the string

    for (i; i < expr.length; i++) // Loop through the string
    {
        switch (expr[i]) // Check what character this is
        {
            case '(': // Left bracket
            {
                // A left bracket is valid if the character before it was an operator
                // Therefore, it is invalid if the character before it is a number.
                if (isOperator(expr[i]))
                {

                }
            }
        }
    }
}
