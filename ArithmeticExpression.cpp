#include "ArithmeticExpression.h"

ArithmeticExpression::ArithmeticExpression()
{
    //ctor
}

ArithmeticExpression::~ArithmeticExpression()
{
    delete this->left; // Delete the left half
    delete this->right; // Delete the right half
}

/*ArithmeticExpression::ArithmeticExpression(const ArithmeticExpression& other)
{
    this->left = new Expression(other->left); // Construct the left half of this expression
    this->right = new Expression(other->right); // Construct the right half of this expression
}*/

ArithmeticExpression& ArithmeticExpression::operator=(const ArithmeticExpression& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates left and right expression and combines them with the appropriate operator.
* \return A string representation of the result.
*/
string ArithmeticExpression::evaluate()
{
    return left->evaluate(); // Print the evaluated left half of the expression (that's the only part that contains the expression)
}

/** \brief Prints the evaluated expression.
*/
void ArithmeticExpression::print()
{
    left->print(); // Print the expression
}

/** \brief Converts a string (as returned by evaluate) to a float.
* \param s The string representing the value to convert to a floating-point number.
* \return A floating-point representation of the string.
*/
float ArithmeticExpression::convert(string s) //string s is passed through this function
{
    float input = atof (s.c_str()); //convert the string input into a float
    return input; //returns the string as a float.
}
