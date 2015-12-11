#include "Subtraction.h"

Subtraction::Subtraction()
{
    this->left = new Expression(); // Create the left half
    this->right = new Expression(); // Create the right half.
}

Subtraction::~Subtraction()
{
    delete this->left; // Free the left half
    delete this->right; // Free the right half
}

Subtraction::Subtraction(const Subtraction& other)
{
    //this = new ArithmeticExpression(); // Initialise the base class
    this->left = other.left; // Copy the left half
    this->right = other.right; // Copy the right half
}

Subtraction& Subtraction::operator=(const Subtraction& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression.
* \return A string representation of the result.
*/
string Subtraction::evaluate()
{
    string lNumStr = left->evaluate(); // Get the number from the left half of the expression
    string rNumStr = right->evaluate(); // Get the number from the right half of the expression
    float lNumF = this->convert(lNumStr); // Convert the left-hand side string to a float
    float rNumF = this->convert(rNumStr); // Convert the right-hand side string to a float
    stringstream ss; // The string stream used to convert the result of the floating-point addition to a string
    ss << lNumF-rNumF; // Place the sum of the floats into the stringstream
    return ss.str(); // Return the string representation of the result of the evaluation
}

/** \brief Prints the expression.
*/
void Subtraction::print()
{
    cout << this->evaluate(); //prints evaluated expression
}
