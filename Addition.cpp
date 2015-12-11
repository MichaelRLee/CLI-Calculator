#include "Addition.h"

Addition::Addition()
{
    this->left = new Expression(); // Allocate memory for an Expression
    this->right = new Expression(); // Allocate memory for an expression
}

Addition::~Addition()
{
    delete this->left; // Delete the left Expression
    delete this->right; // Delete the right Expression
}

/*Addition::Addition(const Addition& other)
{
    this->left = new Expression(other.left); // Copy the left half of the other Expression to this one
    this->right = new Expression(other.right); // Copy the right half of the other Expression to this one
}*/

Addition& Addition::operator=(const Addition& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression.
* \return A string representing the result of the evaluation of the expression.
*/
string Addition::evaluate()
{
    /**
    *   Since the left and right halves are themselves Expressions, we need to evaluate them before
    *   combining them with an addition sign.
    *
    *   TODO: For each evaluate: check if it returns a number. If they do, convert the numbers to strings, add them, convert the result back to a string, and return that.
    **/
    //return left->evaluate() + "+" + right->evaluate();
    string lNumStr = left->evaluate(); // Get the number from the left half of the expression
    string rNumStr = right->evaluate(); // Get the number from the right half of the expression
    float lNumF = this->convert(lNumStr); // Convert the left-hand side string to a float
    float rNumF = this->convert(rNumStr); // Convert the right-hand side string to a float
    stringstream ss; // The string stream used to convert the result of the floating-point addition to a string
    ss << lNumF+rNumF; // Place the sum of the floats into the stringstream
    return ss.str(); // Return the string representation of the result of the evaluation
}

/** \brief Prints the expression.
*/
void Addition::print()
{
    cout << left->evaluate() + "+" + right->evaluate(); // Print the evaluated left and right halves, separated by a '+'
}
