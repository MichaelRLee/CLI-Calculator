/* C++ includes */

// Standard C++ headers
#include <iostream> // cout, cin
#include <limits> // numeric_limits
//#include <iomanip> //rounding decimal places
#include <math.h> //for rounding

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
//Expression* strToExp(string& str); // Builds the ArithmeticExpression object, given a string
ArithmeticExpression* strToExp(string& str);

int main()
{
    bool reading = true; // Controls input loop
    char input[256]; // The user input
    size_t bracketLoc=0; //used to store location of first bracket in expression
    //ArithmeticExpression ae = new ArithmeticExpression(); // Create the top-level expression
    string curToken; // The current token in the expression
    string sInput; // String which represents the input
    Expression* aExp;

    while (reading) // Read until user quits
    {
        cout << "Please enter an expression: "; // Print the prompt for the user
        cin.getline(input, sizeof(input)); // Get a line from the user
        sInput.assign(input); // Convert the C string to a string

        if (!strcmp(input, "#")) // Check for the input which terminates the program (#)
        {
            reading = false; // End the input loop
        }

        /**
        * The user's input was not a message to quit, so we need to first validate and then parse the expression.
        */
        else
        {
            /* Check if the expression is valid */

            if (isValidExpr(sInput)) // The expression is valid
            {
                while(bracketLoc<sInput.length()) //going through each character of the output...
                {
                    if (sInput[bracketLoc++]=='(')removeBrackets(sInput, bracketLoc); //find brackets and remove them if the ayre unnessicary
                }
                sInput=removeSpaces(sInput); //remove spaces
                bracketLoc=0; //reset bracketLoc value
                aExp = new ArithmeticExpression(strToExp(sInput)); // Convert the string to an Expression
                aExp->print(); // Print the Expression
                cout << " = " << roundf(atof((aExp->evaluate()).c_str())*100)/100 << endl;
                //printf("=%0.2f\n",atof((aExp->evaluate()).c_str()));
                delete aExp; // Free the memory allocated to aExp a
            }

            else // The expression is invalid
            {
                // DEBUGGING - Print negative statement
                clog << "Expression is not well formed" << endl;
            }

            clog << endl;
        }
    }
    return 0;
}

/** \brief Counts the number of openning and closing brackets in a string.  Can return either the difference between the two or the number of openning brackets
 *
 * \param expr: The string containing the expression to test. retNum: whenther to return the number of openning brackets or the difference
 * \return Number of openning brackets or difference between the number of openning and closing brackets
 *
 */
int bracketCount(string exp, bool retNum)
{
    int numLBracket = 0; //number of openning brackets
    int numRBracket = 0; //numberof closing brackets
    for (size_t i = 0; i<exp.length(); i++) //for each character in exp
    {
        if (exp[i]=='(') //if the char is a '('
        {
            numLBracket++; //add 1
        }
        else if (exp [i] == ')')//if char is ')'
        {
            numRBracket++;//add 1
        }
    }
    if (retNum==true)//if we are returning the number of brackets
    {
        return numLBracket;//return number of brackets
    }
    else//otherwise
    {
        return numLBracket-numRBracket; //return difference
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
    //cout << "toCheck = \"" << toCheck << "\"" << endl;

    for (size_t i = 0; i < toCheck.length(); i++) // Loop through the string
    {
        if (!isspace(toCheck[i])) // If the current character isn't whitespace, we can stop looking
        {
            //cout << "isAllSpaces: found non-whitespace character at position " << i << endl;
            return false; // The string doesn't contain only whitespace characters
        }
    }

    //cout << "isAllSpaces - returning true" << endl;
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
    if (toCheck == "") // Empty string
    {
        return false; // An empty string isn't a valid number
    }

    // If we got here, the string isn't empty
    for (size_t i = 0; i < toCheck.length(); i++) // Loop through the string
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
    //int oldSPos = 0; // The old position in the string
    string prevToken = ""; // Holds the token from 1 parse ago
    string befPrevToken = ""; // Holds the token from 2 parses ago

    curToken = nextToken(expr, &curSPos); // Priming read - get the first token

    while (curToken != "END") // Loop until we reach the end of the string
    {
        if (curToken == "INVALID") // Found an invalid token
        {
            //clog << "Found invalid token" << endl;
            return false; // No need to look further - the expression is invalid
            break;
        }

        else if (isNumericString(befPrevToken) && isAllSpaces(prevToken) && isNumericString(curToken)) // A sequence of "(number)(space)(number)"
        {
            //cout << "Returning false in if 2" << endl << "isNumericString(" << befPrevToken << ") = " << isNumericString(befPrevToken) << endl << "isAllSpaces(\"" << prevToken << "\") = " << isAllSpaces(prevToken) << endl << "isNumericString(" << curToken << ") = " << isNumericString(curToken) << endl;
            return false; // No need to look further
        }

        else
        {
            // DEBUGGING
            //cout << "isValidExpr: Token at position " << oldSPos << " = \"" << curToken << "\"" << endl; // Print the token

            // DEBUGGING
            //cout << "isValidExpr: After assignment, oldSpos = " << oldSPos << endl;

            // DEBUGGING
            //cout << endl << endl;
        }

        //oldSPos = curSPos; // Store old position in string for next loop
        befPrevToken = prevToken; // Store the token from 2 parses ago for use in the next loop
        prevToken = curToken; // Store the old token for use in the next loop
        curToken = nextToken(expr, &curSPos); // Get the next token
        //clog << "isValidExpr: befPrevToken = \"" << befPrevToken << "\", prevToken = \"" << prevToken << "\", curToken = \"" << curToken << "\" at the end of the loop" << endl;
    }
    //cout << "checkOpp(\"" << expr << "\") = " << checkOpp(expr) << endl;
    return checkOpp(removeSpaces(expr)); // Check the string
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
        //clog << "Invalid Start";
        return false; //return false if it isn't
    }

    if (!(exp[exp.length()-1] == ')' || isdigit(exp[exp.length()-1]))) //check if the last character is a number or an close bracket
    {
        //clog << "Invalid end"<<endl;
        return false; //return false if it isn't
    }

    for (size_t i = 0; i< exp.length()-1; i++){ // go through the string checking the character at the index and at the index++ for proper formatting
        if ((exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') && !(exp [i+1] == '(' || isdigit (exp[i+1])))
                //if the character is an arithmetic opperation, the next character must be an open bracket or a number
        {
            //clog << "Invalid token after opperator"<<endl;
            return false; //return false if the next character is not
        }
        else if (exp [i] == '(' && !(exp [i+1] == '(' || isdigit (exp[i+1]) || exp [i+1] == '-')) //if the character is an open bracket, the next character
                              //must be another open bracket, a number, or a - (for negatives)
        {
            //clog << "Invalid token after open bracket"<<endl;
            return false; //return false if the next character isn't
        }
        else if (exp [i] == ')' && (exp [i+1] == '(' || isdigit (exp[i+1]))) //if the char is a closed bracket, next char can't be an open bracket or number
        {
            //clog << "invalid token after end bracket" << endl;
            return false;//return false if it is
        }
        else if (isdigit(exp[i]) && exp [i+1]== '(')//only numbers are left, and the next character can't be an open bracket
        {
            //clog << "invalid token after number"<<endl;
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
/** \brief Returns a string with all spaces removed from it.
 *
 * \param string exp - input string to be stripped of spaces
 * \return String exp with all space characters removed.
 *
 */
string removeSpaces(string exp)
{
    string output=""; //output string
    for (size_t i =0; i<exp.length();i++)//for each character in the string
    {
        if (exp[i]!=' ')//if the character is not a space
        {
            output+=exp[i];//add the character to the output string
        }
    }
    return output;//return the output string
}

//Expression* strToExp(string &str){
ArithmeticExpression* strToExp(string& str){
    int level = 0;//inside parentheses check
    //case + or -
    //most right '+' or '-' (but not inside '()') search and split
    for(int i = str.size()-1;i>=0;--i){
        if(str[i] == ')'){
            ++level;
            continue;
        }
        if(str[i] == '('){
            --level;
            continue;
        }
        if(level>0) continue;
        if (str[i] == '+'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Addition (strToExp(left),strToExp(right));
        } else if (str[i] == '-'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Subtraction (strToExp(left),strToExp(right));
        }
    }

    //case * or /
    //most right '*' or '/' (but not inside '()') search and split
    for(int i= str.size()-1; i>=0;--i){
        if(str[i] == ')'){
            ++level;
            continue;
        }
        if(str[i] == '('){
            --level;
            continue;
        }
        if(level>0) continue;
        if(str[i] == '*'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Multiplication(strToExp(left), strToExp(right));
        }else if(str[i] == '/'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Division(strToExp(left), strToExp(right));
        }
    }
    if(str[0]=='('){
    //case ()
    //pull out inside and to strToExp
        for(size_t i=0;i<str.size();++i){
            if(str[i]=='('){
                ++level;
                continue;
            }
            if(str[i]==')'){
                --level;
                if(level==0){
                    string exp(str.substr(1, i-1));
                    return strToExp(exp);
                }
                continue;
            }
        }
    } else{
        //case value
        return new Number(str);
    }
    cerr << "Error:never execute point" << endl;
    return NULL;//never
}
