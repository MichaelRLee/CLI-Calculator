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
#include <cctype> // for is digit

/* Forward declarations */
string nextToken(string toParse, int* startPos); // Tokenizer function
bool isValidExpr(string expr); // Determines whether an expression is valid, using the tokenizer
bool checkOpp(string exp); //determines if the expression is arethmetically valid

int main()
{
    bool reading = true; // Controls input loop
    char input[256]; // The user input
    //ArithmeticExpression ae = new ArithmeticExpression(); // Create the top-level expression
    string curToken; // The current token in the expression
    string sInput; // String which represents the input

    while (reading) // Read until user quits
    {
        cout << "Please enter an expression: "; // Print the prompt for the user
        cin.getline(input, sizeof(input)); // Get a line from the user
        clog << "main: input = \"" << input << "\" after assignment" << endl; // DEBUGGING
        sInput.assign(input); // Convert the C string to a string
        clog << "main: sInput = \"" << sInput << "\" after assignment" << endl; // DEBUGGING

        if (!strcmp(input, "#")) // Check for the input which terminates the program (#)
        {
            reading = false; // End the input loop
        }

        /**
        * The user's input was not a message to quit, so we need to first validate and then parse the expression.
        **/
        else
        {
            /* Check if the expression is valid */

            if (isValidExpr(sInput)) // The expression is valid
            {
                // DEBUGGING - Print affirmative statement
                clog << "The expression \"" << sInput << "\" is valid" << endl;
            }

            else // The expression is invalid
            {
                // DEBUGGING - Print negative statement
                clog << "Expression is not well formed" << endl;
            }

            clog << endl;
        }
    }
}

/** \brief Determines whether an expression is valid by checking the tokens returned for any INVALID ones.
 *
 * \param expr The string containing the expression to test.
 * \return True if the expression is valid, false otherwise
 *
 */

bool isValidExpr(string expr)
{
    string curToken; // The current token in the string
    int curSPos = 0; // The current position in the string
    int oldSPos = 0; // The old position in the string

    curToken = nextToken(expr, &curSPos); // Priming read - get the first token

    while (curSPos < expr.length()) // Loop until we reach the end of the string
    {
        if (curToken == "INVALID") // Found an invalid token
        {
            return false; // No need to look further - the expression is invalid
        }

        else
        {
            // DEBUGGING
            //cout << "isValidExpr: Token at position " << oldSPos << " = \"" << curToken << "\"" << endl; // Print the token
            oldSPos = curSPos; // Store old position in string for next loop
            // DEBUGGING
            //cout << "isValidExpr: After assignment, oldSpos = " << oldSPos << endl;
            curToken = nextToken(expr, &curSPos); // Get the next token
            // DEBUGGING
            //cout << endl << endl;
        }
    }
    return checkOpp(expr); // If we have reached here, the expression is valid
}

/** \brief Check if the expression is arethmetically valid.
 *
 * \param expr The string containing the expression to test.
 * \return True if the expression is valid, false otherwise
 */

bool checkOpp (string exp)
{
    if (!(exp[0] == '(' || isdigit(exp[0] ))) //check if the first character is a number or an open bracket
    {
        return false; //return false if it isn't
    }

    if (!(exp[exp.length()-1] == ')' || isdigit(exp[exp.length()-1]))) //check if the last character is a number or an close bracket
    {
        return false; //return false if it isn't
    }

    for (size_t i = 0; i< exp.length()-1; i++){ // go through the string checking the character at the index and at the index++ for proper formatting
        if ((exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') && !(exp [i+1] = '(' || isdigit (exp[i+1])))
                //if the character is an arithmetic opperation, the next character must be an open bracket or a number
        {
            return false; //return false if the next character is not
        }
        else if (exp [i] == '(' && !(exp [i+1] = '(' || isdigit (exp[i+1]) || exp [i+1] == '-')) //if the character is an open bracket, the next character
                              //must be another open bracket, a number, or a - (for negatives)
        {
            return false; //return false if the next character isn't
        }
        else if (exp [i] == ')' && (exp [i+1] = '(' || isdigit (exp[i+1]))) //if the char is a closed bracket, next char can't be an open bracket or number
        {
            return false;//return false if it is
        }
        else if (exp [i+1]== '(')//only numbers are left, and the next character can't be an open bracket
        {
            return false; //return false if it is
        }
    }
    return true; //if the string passed all the tests, it is valid, and true is returned
}

/** \brief Gets the next token from the given arithmetic expression.
 *
 * \param toParse The string containing the arithmetic expression to parse
 * \param startPos A pointer to an integer, describing the position in the string at which to begin parsing.
 * \return The token.
 *
 */
string nextToken(string toParse, int* startPos)
{
    int sPos = *startPos; // Store the starting position internally, so as not to change it
    string tokStr; // The string containing the token - will be returned to the caller

    // DEBUGGING
    //cout << "nextToken: sPos = " << sPos << " at start" << endl;

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
            // DEBUGGING
      //      cout << "nextToken: toParse[" << sPos << "] = '" << toParse[sPos] << "'" << endl;
            tokStr += toParse[sPos]; // Append the digit to the token string
            // DEBUGGING
        //    cout << "nextToken: tokStr = \"" << tokStr << "\" after appending" << endl;
            (*startPos)++; // Increment the starting position for the next loop
            // DEBUGGING
          //  cout << "nextToken: startPos = " << *startPos << " after increment" << endl;
            sPos++; // Increment our counter
            // DEBUGGING
            //cout << "nextToken: sPos = " << sPos << " after increment" << endl;
        }
    }
    else if (sPos == toParse.length()) // We have reached the end of the string
    {
        tokStr = "END"; // Signal the end of the string
    }
    else if (isspace(toParse[sPos])) // Space character
    {
        (*startPos)++; // Increment counter for next loop
        tokStr = "SPACE"; // Indicate a space token
    }
    else // Invalid token
    {
        tokStr = "INVALID"; // Indicate that the string is invalid
        (*startPos)++; // Increment string counter
    }

    return tokStr; // Return the token
}

/** \brief Returns the precedence of a node in the Expression.
 *
 * \param string node - The node whose precedence the function will determine
 * \return An integer describing the precedence of the node.
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

    // else if (isnumber(node)) // Need to write this later
}
