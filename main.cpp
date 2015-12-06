/* C++ includes */

// Standard C++ headers
#include <iostream> // cout, cin
#include <limits> // numeric_limits

// My header files
#include "Expression.h" // Expression class
#include "ArithmeticExpression.h" // ArithmeticExpression class
#include "Addition.h" // Addition class
#include "Subtraction.h" // Subtraction class
#include "Multiplication.h" // Multiplication class
#include "Division.h" // Division class
#include "Number.h" // Number class

// Namespaces
using namespace std;

/* C includes */

// Standard C headers
#include <cstring> // strcmp

/* Forward declarations */
string nextToken(string toParse, int* startPos); // Tokenizer function

int main()
{
    bool reading = true; // Controls input loop
    char input[256]; // The user input
    //ArithmeticExpression ae = new ArithmeticExpression(); // Create the top-level expression
    string curToken; // The current token in the expression
    int curSPos = 0; // Current position in the string
    int oldSPos = 0; // Old position in string
    string sInput; // String which represents the input

    while (reading) // Read until user quits
    {
        cout << "Please enter an expression: "; // Print the prompt for the user
        cin.getline(input, sizeof(input)); // Get a line from the user
        cout << "main: input = \"" << input << "\" after assignment" << endl;
        sInput.assign(input); // Convert the C string to a string
        cout << "main: sInput = \"" << sInput << "\" after assignment" << endl;

        if (!strcmp(input, "#")) // Check for the input which terminates the program (#)
        {
            reading = false; // End the input loop
        }

        /**
        * The user's input was not a message to quit, so we need to first validate and then parse the expression.
        **/
        else
        {
            /* DEBUGGING */
            curToken = nextToken(sInput, &curSPos); // Priming read - get the first token

            while (curToken != "") // We can only loop while we haven't reached the end of the string and we haven't encountered an invalid token
            {
                cout << "main: Token at position " << oldSPos << " = \"" << curToken << "\"" << endl; // Print the token
                oldSPos = curSPos; // Store old position in string for next loop
                cout << "main: After assignment, oldSpos = " << oldSPos << endl;
                curToken = nextToken(sInput, &curSPos); // Get the next token
                cout << endl << endl;
            }

            // Reset string position variables
            oldSPos = curSPos = 0;
        }
    }
}

/** \brief Gets the next token from the given arithmetic expression.
 *
 * \param toParse The string containing the arithmetic expression to parse
 * \param startPos A pointer to an integer, describing the position in the string at which to beging parsing.
 * \return The token.
 *
 */
string nextToken(string toParse, int* startPos)
{
    int sPos = *startPos; // Store the starting position internally, so as not to change it
    string tokStr; // The string containing the token - will be returned to the caller

    cout << "nextToken: sPos = " << sPos << " at start" << endl;

    /* Simple case */
    if (toParse[sPos] == '+' || toParse[sPos] == '-' || toParse[sPos] == '*' || toParse[sPos] == '/' || toParse[sPos] == '(' || toParse[sPos] == ')') // Operator or bracket
    {
        tokStr += toParse[sPos]; // Add the operator to the string to return
        (*startPos)++; // Increment the number which represents the starting position in the string for the next call of this function
        sPos++; // Increment position
        return tokStr; // Return the token
    }

    else if (isdigit(toParse[sPos])) // Number
    {
        while (isdigit(toParse[sPos])) // Read characters until we don't see any more digits
        {
            cout << "nextToken: toParse[" << sPos << "] = '" << toParse[sPos] << "'" << endl;
            tokStr += toParse[sPos]; // Append the digit to the token string
            cout << "nextToken: tokStr = \"" << tokStr << "\" after appending" << endl;
            (*startPos)++; // Increment the starting position for the next loop
            cout << "nextToken: startPos = " << *startPos << " after increment" << endl;
            sPos++; // Increment our counter
            cout << "nextToken: sPos = " << sPos << " after increment" << endl;
        }
    }

    else if (sPos == toParse.length()) // We have reached the end of the string
    {
        tokStr = ""; // Signal the end of the string
    }

    else // Invalid token
    {
        tokStr = ""; // Indicate that the string is invalid
    }

    return tokStr; // Return the token
}

/** \brief Returns the precedence of a node in the Expression.
 *
 * \param string node - The operator whose precedence the function will determine
 * \return An integer describing the precedence of the number.
 *
 */

int precedence(string node)
{
    if (!node.compare("(") || !node.compare(")")) // Brackets
    {
        return 3;
    }

    else if (!node.compare("*") || !node.compare("/")) // Division/Multiplication
    {
        return 2;
    }

    else if (!node.compare("+") || !node.compare("-")) // Addition/Subtraction
    {
        return 1;
    }
}
