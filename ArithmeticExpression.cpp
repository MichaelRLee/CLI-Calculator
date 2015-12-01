#include "ArithmeticExpression.h"

// Constructor
ArithmeticExpression::ArithmeticExpression()
{
}

// Destructor
ArithmeticExpression::~ArithmeticExpression()
{
}

// Copy constructor
ArithmeticExpression::ArithmeticExpression(const ArithmeticExpression& other)
{
}

ArithmeticExpression& ArithmeticExpression::operator=(const ArithmeticExpression& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string evaluate(); // Evaluates left and right side of the expression and returns a string representing the combination of the evaluated expressions using this expression's operator

void print(); // Prints the evaluated expression

float convert(string s); // Converts a string (as would be returned by evaluate) to a float
