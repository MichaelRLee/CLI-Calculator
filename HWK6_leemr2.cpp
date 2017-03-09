/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file runs the program
*/


// Standard C++ headers
#include <iostream> 
#include <limits> 
#include <math.h> 

// My header files
#include "Expression.h" // Expression class
#include "ArithmeticExpression.h" // ArithmeticExpression class
#include "Addition.h" // Addition class
#include "Subtraction.h" // Subtraction class
#include "Multiplication.h" // Multiplication class
#include "Division.h" // Division class

// Namespaces
using namespace std;

/* C includes */

// Standard C headers
#include <cstring> 

/* Forward declarations */
string nextToken(string toParse, int* startPos); 
bool isValidExpr(string expr); 
bool checkOpp(string exp); 
void removeBrackets(string& exp, size_t &strIndex); 
int bracketCount (string exp, bool retNum);  
string removeSpaces (string exp); 
Expression* strToExp(string& str);

int main()
{
    bool reading = true; 
    char input[256]; // The user input
    size_t bracketLoc=0; //stores location of first bracket in expression
    string curToken; // The current token in the expression
    string sInput; // String which represents the input
    Expression* oldExp =NULL; //the old expression
    Expression* newExp = NULL; //the new expression

    /*
    * This while loop will be the main interface of the program, it will run until the user decides to quit
    * Will ask user to enter an arithmetic expression which it will evaluate using a recursive algorithm
    */
    while (reading) 
    {
        //Get user input and convert to a string
        cout << "Please enter an expression: "; 
        cin.getline(input, sizeof(input)); 
        sInput.assign(input); 

        if (!strcmp(input, "#")) // Check for the input which terminates the program (#)
        {
            reading = false; 
            break;
        }
        else if (!strcmp(input,"@")) //if input is @ it will increment the expression then evaluate
        {
            if (oldExp==NULL){ //if @ is entered before an expression has been
                cout << "No expression has been entered. Please enter an expression first\n" << endl; 
            }
            else{ 
                newExp = new Expression(oldExp); 
                newExp->increment(); 
                newExp->print(); 
                cout << " = " << roundf(atof((newExp->evaluate()).c_str())*100)/100 << endl; 
                oldExp = new Expression(newExp); 
            }
        }

        /**
        * The user's input was not a message to quit, so we need to first validate and then parse the expression.
        */
        else
        {
            /* Check if the expression is valid */

            if (isValidExpr(sInput)) // The expression is valid go through each user input and parse using the parsing algorithm
            {
                while(bracketLoc<sInput.length()) 
                {
                    if (sInput[bracketLoc++]=='(')removeBrackets(sInput, bracketLoc); 
                }
                sInput=removeSpaces(sInput); 
                bracketLoc=0;
                if (oldExp != NULL) delete oldExp; 
                oldExp = new ArithmeticExpression(strToExp(sInput)); 
                oldExp->print(); 
                cout << " = " << roundf(atof((oldExp->evaluate()).c_str())*100)/100 << endl; xw
            }

            else // If the expression is invalid
            {
                clog << "Expression is not well formed" << endl; 
            }

        }
        cout << endl; 
    }
    if (oldExp!=NULL)delete oldExp; //if old expression is not null, delete oldExp which would also delete newExp
    return 0;//default ret val
}

/*
 * This method will return either return the number of opening/closing brackets or the difference between them
 */
int bracketCount(string exp, bool retNum)
{
    int numLBracket = 0; //Open Bracket Counter
    int numRBracket = 0; //Close Bracket Counter

    //iterate through expression and get the number of brackets
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
    if (retNum==true)//if we are returning the number of brackets
    {
        return numLBracket;//return number of brackets
    }
    else// if we are returning the difference
    {
        return numLBracket-numRBracket; //return difference
    }
}

/*
 * This method checks if the entered expression is made up of all spaces
 */
bool isAllSpaces(string toCheck)
{
    
    // Loop through the string and checl if there isn't whitespace
    for (size_t i = 0; i < toCheck.length(); i++) // Loop through the string
    {
        if (!isspace(toCheck[i])) 
        {
            
            return false; 
        }
    }

    return true; // If we got here, the string contained only whitespace characters
}



/*
 * This method checks if the entered expression is made up of only numeric numbers
 */
bool isNumericString(string toCheck)
{   
    //Check for empty string case
    if (toCheck == "") 
    {
        return false; 
    }

    // If the string isn't empty iterate through string and look for non-digits
    for (size_t i = 0; i < toCheck.length(); i++) 
    {
        if (!isdigit(toCheck[i])) 
        {
            return false; 
        }
    }

    return true; 
}

/*
* Determine if the the entered expression is a valid expression by checking the amount of tokens returned
* This method in cojuntion with checkOpp will loop through the expression making sure
* that every token(an element of the expression ex. a number or a '+' sign) makes mathematical sense
*/
bool isValidExpr(string expr)
{
    string curToken; // The current token in the string
    int curSPos = 0; // The current position in the string
    string prevToken = ""; // Holds the token from 1 parse ago
    string befPrevToken = ""; // Holds the token from 2 parses ago

    curToken = nextToken(expr, &curSPos); // Priming read - get the first token

    //This will loop through the expression making sure each token is properly placed
    while (curToken != "END") 
    {
        // Found an invalid token
        if (curToken == "INVALID") // Found an invalid token
        {
            return false; // No need to look further - the expression is invalid
            break; 
        }

        else if (isNumericString(befPrevToken) && isAllSpaces(prevToken) && isNumericString(curToken)) // A sequence of "(number)(space)(number)"
        {
            return false; // No need to look further - the expression is invalid
            break;
        }

        befPrevToken = prevToken; // Store the token from 2 parses ago for use in the next loop
        prevToken = curToken; // Store the old token for use in the next loop
        curToken = nextToken(expr, &curSPos); // Get the next token
    }
    return checkOpp(removeSpaces(expr)); // After first check is complete check the string again this time for arithmetical mistakes
}

/*
* This method will also check that the expression entered makes arithmetical sense
*/
bool checkOpp (string exp)
{
    //check if the first character is a number or an open bracket
    if (!(exp[0] == '(' || isdigit(exp[0] ))) 
    {
        return false; 
    }

    //check if the last character is a number or an close bracket
    if (!(exp[exp.length()-1] == ')' || isdigit(exp[exp.length()-1]))) 
    {
        return false; 
    }

    // go through the string checking the character at different indices for proper formatting
    for (size_t i = 0; i< exp.length()-1; i++){ 

        //if the character is an arithmetic opperation, the next character must be an open bracket or a number
        if ((exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') && !(exp [i+1] == '(' || isdigit (exp[i+1])))
                
        {
            return false; 
        }

        //if the character is an open bracket, the next character must be another open bracket, a number, or a - (for negatives)
        else if (exp [i] == '(' && !(exp [i+1] == '(' || isdigit (exp[i+1]) || exp [i+1] == '-'))                            
        {
            return false; 
        }
        //if the char is a closed bracket, next char can't be an open bracket or number
        else if (exp [i] == ')' && (exp [i+1] == '(' || isdigit (exp[i+1]))) 
        {
            return false;
        }
        //only numbers are left, and the next character can't be an open bracket
        else if (isdigit(exp[i]) && exp [i+1]== '(')
        {
            return false ; 
        }

        //check for negative numbers
        if (exp[i]=='('&&exp[i+1]=='-') 
        {
            size_t j = i+2; //where digits should start

            //if next char isn't a ) or j is bigger than the string
            while (!(exp[j]==')')&&j<exp.length()) 
            {
                //if the char is a number
                if (!isdigit(exp[j])) 
                {
                    return false; 
                }
                j++;
            }
            //if the digit after the - is a )
            if (j==i+2 || j==exp.length()) 
            {
                return false; 
            }
        }
    }
    return (bracketCount(exp, false)==0); //if the string passed all the tests, it is valid, and true is returned
}

/*
 * Gets the next token from the given arithmetic expression.
 */
string nextToken(string toParse, int* startPos)
{
    int sPos = *startPos; // Store the starting position internally, so as not to change it
    string tokStr; // The string containing the token - will be returned to the caller

    /* Simple case with just an arithmetic character */
    if (toParse[sPos] == '+' || toParse[sPos] == '-' || toParse[sPos] == '*' || toParse[sPos] == '/' || toParse[sPos] == '(' || toParse[sPos] == ')') // Operator or bracket
    {
        tokStr += toParse[sPos]; // Add the operator to the string to return
        (*startPos)++; // Increment the number which represents the starting position in the string for the next call of this function
        sPos++; 
        return tokStr; 
    }

    // Number
    else if (isdigit(toParse[sPos])) 
    {
        // Read characters until we don't see any more digits
        while (isdigit(toParse[sPos])) 
        {
            
            tokStr += toParse[sPos]; // Append the digit to the token string
           
            (*startPos)++; // Increment the starting position for the next call
            
            sPos++; 
        }
    }

    // We have reached the end of the string
    else if ((unsigned)sPos == toParse.length()) 
    {
        tokStr = "END"; // Signal the end of the string
    }

    // Space character
    else if (isspace(toParse[sPos])) 
    {
        /* Skip all spaces from the current position to the first non-space character after the current position */
        while (isspace(toParse[sPos])) // While the current character is a space
        {
            tokStr += toParse[sPos]; 
            sPos++; 
            (*startPos)++; 
        }
    }

    // Invalid token
    else 
    {
        tokStr = "INVALID"; // Indicate that the string is invalid
        (*startPos)++; // Increment string counter
    }

    return tokStr; // Return the token
}

/*
 *  This method will remove unnessicary brackets from the expression.
 */
void removeBrackets(string& exp, size_t& strIndex)
{
    bool hasOpp=false; //whether a set of brackets have an opperator in them
    size_t bracketIndex = strIndex-1; //index of openning bracket

    //while the index is less than the string's length and the next character isn't a ')'
    while (strIndex<exp.length() && exp[strIndex]!=')') 
    {
        //if the next character is an opperation
        if (exp[strIndex]=='+' || exp[strIndex]=='-' || exp[strIndex]=='*' || exp[strIndex]=='/') 
        {
            hasOpp=true; 
        }
        //if the next character is an open bracket
        else if (exp [strIndex]=='(') 
        {
            removeBrackets(exp, ++strIndex);//recurse starting at different index
        }
        strIndex++;
    }

    //if there was no opperator in the brackets replace them with a space
    if (!hasOpp)
    {
        exp[bracketIndex]=' ';
        exp[strIndex]=' ';
    }
}
/* 
* Will return the string with all unessesarry spaces removed
*/
string removeSpaces(string exp)
{
    string output=""; 

    //for each character in the string
    for (size_t i =0; i<exp.length();i++)
    {
        if (exp[i]!=' ')//if the character is not a space
        {
            output+=exp[i];
        }
    }
    return output;
}

// Convert the string to an expression that we can work with
Expression* strToExp(string& str){


    int level = 0;//inside parentheses check
    
    //case + or -
    //most right '+' or '-' (but not inside '()') search and split
    for(int i = str.size()-1;i>=0;--i){ //for each digit going backwards
        if(str[i] == ')'){ //ignore brackets
            ++level; //increase level of brackets
            continue; 
        }
        if(str[i] == '('){ //ignore brackets
            --level; //decrease level
            continue; 
        }

        //after ignoring brackets
        if(level>0) continue;

        // if addition merge left and right
        if (str[i] == '+'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Addition (strToExp(left),strToExp(right));//create expression by converting lhs and rhs to expressions
        } 
        //if subtraction merge left and right
        else if (str[i] == '-'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Subtraction (strToExp(left),strToExp(right));//convert recursively to expression
        }
    }

    //case * or /
    //most right '*' or '/' (but not inside '()') search and split
    for(int i= str.size()-1; i>=0;--i){
        if(str[i] == ')'){ //ignore brackets
            ++level; //increase level of brackets
            continue; 
        }
        if(str[i] == '('){ //ignore brackets
            --level; //decrease level
            continue; 
        }
        if(level>0) continue;//continue until not in brackets

        //multiply
        if(str[i] == '*'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Multiplication(strToExp(left), strToExp(right));//return expression recursively
        }
        //division
        else if(str[i] == '/'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Division(strToExp(left), strToExp(right));//return expression recursively
        }
    }

    //brackets apear next
    if(str[0]=='('){


    //case ()
    //pull out inside and to strToExp
        for(size_t i=0;i<str.size();++i){
            if(str[i]=='('){ //ingoring deeper levels of brackets
                ++level; //increment level
                continue;
            }
            if(str[i]==')'){//ignoring deeper levels of brackets
                --level;//decriment level

                //if we're at base level
                if(level==0){
                    if (str[1]=='-')//if it's a negative number (check opp will make sure of this)
                    {
                        return new Expression(str.substr(1,i-1));//return the negative number
                    }
                    string exp(str.substr(1, i-1));//else create expression with inside brackets
                    return strToExp(exp);//recurse without brackets
                }
                continue;//top of loop
            }
        }

    //if just a num
    } else{

        //case value
        return new Expression(str);//return num
    }
    cerr << "Error:never execute point" << endl; //error call
    return NULL; //never
}
