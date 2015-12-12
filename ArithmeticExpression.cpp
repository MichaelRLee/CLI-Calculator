#include "ArithmeticExpression.h"

ArithmeticExpression::ArithmeticExpression(Expression* left, Expression* right):left(left), right (right){}

ArithmeticExpression::ArithmeticExpression(Expression* finalExp):left(finalExp){}

ArithmeticExpression::~ArithmeticExpression()
{
    //dtor
}

ArithmeticExpression::ArithmeticExpression(const ArithmeticExpression& other)
{
    //copy ctor
}

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
    return left->evaluate(); // Evaluate the left half of the Expression
}

/** \brief Prints the evaluated expression.
*/
void ArithmeticExpression::print()
{
    left->print();
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
