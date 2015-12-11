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
bool isValidExpr(string expr); // Determines whether an expression is valid, using the tokenizer
bool checkOpp(string exp); //check if expression is arithmetically correct
void removeBrackets(string& exp, size_t &strIndex); //removes unnessicary brackets from expression
int bracketCount (string exp, bool retNum);  //counts brackets and returns based on boolean;
string removeSpaces (string exp); //removes spaces from expression

int main()
{
    bool reading = true; // Controls input loop
    char input[256]; // The user input
    size_t bracketLoc=0; //used to store location of first bracket in expression
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
                while(sInput[bracketLoc++]!='('&&bracketLoc<sInput.length()); //gets the index after the first bracket
                removeBrackets(sInput, bracketLoc); //function to remove unnessicary brackets
                sInput=removeSpaces(sInput);
                bracketLoc=0;
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

/** \brief Counts the number of openning and closing brackets in a string.  Can return either the difference between the two or the number of openning brackets
 *
 * \param expr: The string containing the expression to test. retNum: whenther to return the number of openning brackets or the difference
 * \return Number of openning brackets or difference between the number of openning and closing brackets
 *
 */
int bracketCount(string exp, bool retNum)
{
    int numLBracket = 0;
    int numRBracket = 0;
    for (size_t i = 0; i<exp.length(); i++)
    {
        if (exp[i]=='(')
        {
            numLBracket++;
        }
        else if (exp [i] == ')')
        {
            numRBracket++;
        }
    }
    if (retNum==true)
    {
        return numLBracket;
    }else
    {
        return numLBracket-numRBracket;
    }
}

/** \brief Determines whether a string contains only spaces.
 *
 * \param toCheck - The string to check.
 * \return True if the string contains only whitespace, false otherwise
 *
 */
bool isAllSpaces(string toCheck)
{
    int i; // Current position in the string

    cout << "toCheck = \"" << toCheck << "\"" << endl;

    for (i = 0; i < toCheck.length(); i++) // Loop through the string
    {
        if (!isspace(toCheck[i])) // If the current character isn't whitespace, we can stop looking
        {
            cout << "isAllSpaces: found non-whitespace character at position " << i << endl;
            return false; // The string doesn't contain only whitespace characters
        }
    }

    cout << "isAllSpaces - returning true" << endl;
    return true; // If we got here, the string contained only whitespace characters
}

/** \brief Determines whether a given string contains only numeric characters (i.e. it is a valid integer)
 *
 * \param toCheck - The string to check the characters of.
 * \return True if the string contains only numeric characters, false otherwise.
 *
 */
bool isNumericString(string toCheck)
{
    int i; // Loop counter

    if (toCheck == "") // Empty string
    {
        return false; // An empty string isn't a valid number
    }

    // If we got here, the string isn't empty
    for (i = 0; i < toCheck.length(); i++) // Loop through the string
    {
        if (!isdigit(toCheck[i])) // If the current character isn't a digit, the string doesn't represent a numeric string
        {
            return false; // No need to look further
        }
    }

    return true; // If we got here, the string contained only numeric characters
}

/** \brief Determines whether an expression is valid by checking the tokens returned.
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
    string prevToken = ""; // Holds the token from 1 parse ago
    string befPrevToken = ""; // Holds the token from 2 parses ago

    curToken = nextToken(expr, &curSPos); // Priming read - get the first token

    while (curToken != "END") // Loop until we reach the end of the string
    {
        if (curToken == "INVALID") // Found an invalid token
        {
            clog << "Found invalid token" << endl;
            return false; // No need to look further - the expression is invalid
            break;
        }

        else if (isNumericString(befPrevToken) && isAllSpaces(prevToken) && isNumericString(curToken)) // A sequence of "(number)(space)(number)"
        {
            cout << "Returning false in if 2" << endl << "isNumericString(" << befPrevToken << ") = " << isNumericString(befPrevToken) << endl << "isAllSpaces(\"" << prevToken << "\") = " << isAllSpaces(prevToken) << endl << "isNumericString(" << curToken << ") = " << isNumericString(curToken) << endl;
            return false; // No need to look further
        }

        else
        {
            // DEBUGGING
            cout << "isValidExpr: Token at position " << oldSPos << " = \"" << curToken << "\"" << endl; // Print the token

            // DEBUGGING
            cout << "isValidExpr: After assignment, oldSpos = " << oldSPos << endl;

            // DEBUGGING
            cout << endl << endl;
        }

        oldSPos = curSPos; // Store old position in string for next loop
        befPrevToken = prevToken; // Store the token from 2 parses ago for use in the next loop
        prevToken = curToken; // Store the old token for use in the next loop
        curToken = nextToken(expr, &curSPos); // Get the next token
        clog << "isValidExpr: befPrevToken = \"" << befPrevToken << "\", prevToken = \"" << prevToken << "\", curToken = \"" << curToken << "\" at the end of the loop" << endl;
    }
    cout << "checkOpp(\"" << expr << "\") = " << checkOpp(expr) << endl;
    return checkOpp(expr); // Check the string
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
        cout << "Invalid Start";
        return false; //return false if it isn't
    }

    if (!(exp[exp.length()-1] == ')' || isdigit(exp[exp.length()-1]))) //check if the last character is a number or an close bracket
    {
        cout << "Invalid end"<<endl;
        return false; //return false if it isn't
    }

    for (size_t i = 0; i< exp.length()-1; i++){ // go through the string checking the character at the index and at the index++ for proper formatting
        if ((exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') && !(exp [i+1] == '(' || isdigit (exp[i+1])))
                //if the character is an arithmetic opperation, the next character must be an open bracket or a number
        {
            cout << "Invalid token after opperator"<<endl;
            return false; //return false if the next character is not
        }
        else if (exp [i] == '(' && !(exp [i+1] == '(' || isdigit (exp[i+1]) || exp [i+1] == '-')) //if the character is an open bracket, the next character
                              //must be another open bracket, a number, or a - (for negatives)
        {
            cout << "Invalid token after open bracket"<<endl;
            return false; //return false if the next character isn't
        }
        else if (exp [i] == ')' && (exp [i+1] == '(' || isdigit (exp[i+1]))) //if the char is a closed bracket, next char can't be an open bracket or number
        {
            cout << "invalid token after end bracket" << endl;
            return false;//return false if it is
        }
        else if (isdigit(exp[i]) && exp [i+1]== '(')//only numbers are left, and the next character can't be an open bracket
        {
            cout << "invalid token after number"<<endl;
            return false ; //return false if it is
        }
    }
    return (bracketCount(exp, false)==0); //if the string passed all the tests, it is valid, and true is returned
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
            (*startPos)++; // Increment the starting position for the next call
            // DEBUGGING
          //  cout << "nextToken: startPos = " << *startPos << " after increment" << endl;
            sPos++; // Increment our counter
            // DEBUGGING
            //cout << "nextToken: sPos = " << sPos << " after increment" << endl;
        }
    }

    else if ((unsigned)sPos == toParse.length()) // We have reached the end of the string
    {
        tokStr = "END"; // Signal the end of the string
    }

    else if (isspace(toParse[sPos])) // Space character
    {
        /* Skip all spaces from the current position to the first non-space character after the current position */
        while (isspace(toParse[sPos])) // While the current character is a space
        {
            tokStr += toParse[sPos]; // Add the space to the token string to return
            sPos++; // Increment position in the string
            (*startPos)++; // Increment the counter passed to us for the next call
        }
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
    /*if (isnum(node)) // A number has the highest precedence
    {
        return 3;
    }

    else*/ if (!node.compare("(") || !node.compare(")")) // Brackets
    {
        return 2;
    }

    else if (!node.compare("*") || !node.compare("/")) // Division/Multiplication
    {
        return 1;
    }

    else if (!node.compare("+") || !node.compare("-")) // Addition/Subtraction
    {
        return 0;
    }
    return -1;
}

/** \brief Removes unnessicary brackets from the expression.
 *
 * \param exp: expression to evaluate (pass by reference), strIndex: current location we are examining the string at.
 */
void removeBrackets(string& exp, size_t& strIndex)
{
    bool hasOpp=false; //whether a set of brackets have an opperator in them
    size_t bracketIndex = strIndex-1; //index of openning bracket
    while (strIndex<exp.length() && exp[strIndex]!=')') //while the index is less than the string's length and the next character isn't a ')'
    {
        if (exp[strIndex]=='+' || exp[strIndex]=='-' || exp[strIndex]=='*' || exp[strIndex]=='/') //if the next character is an opperation
        {
            hasOpp=true; //the brackets have an opperation in them
        }
        else if (exp [strIndex]=='(') //if the next character is an open bracket
        {
            removeBrackets(exp, ++strIndex);//recurse starting at different index
        }
        strIndex++;//incriment the index by one
    }
    if (!hasOpp)//if there was no opperator in the brackets
    {
        exp[bracketIndex]=' ';//replace the openning bracket with a space
        exp[strIndex]=' ';//replace the closing brackets with a space
    }
}

string removeSpaces(string exp)
{
    string output="";
    for (size_t i =0; i<exp.length();i++)
    {
        if (exp[i]!=' ')
        {
            output+=exp[i];
        }
    }
    return output;
}
