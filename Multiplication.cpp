#include "Multiplication.h"

Multiplication::Multiplication()
{
    //ctor
}

Multiplication::~Multiplication()
{
    //dtor
}

Multiplication::Multiplication(const Multiplication& other)
{
    //copy ctor
}

Multiplication& Multiplication::operator=(const Multiplication& rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

string Multiplication::evaluate()
{
    string lNumStr = left->evaluate(); // Get the number from the left half of the expression
    string rNumStr = right->evaluate(); // Get the number from the right half of the expression
    float lNumF = this->convert(lNumStr); // Convert the left-hand side string to a float
    float rNumF = this->convert(rNumStr); // Convert the right-hand side string to a float
    stringstream ss; // The string stream used to convert the result of the floating-point addition to a string
    ss << lNumF*rNumF; // Place the product of the floats into the stringstream
    return ss.str(); // Return the string representation of the result of the evaluation
}

void Multiplication::print()
{
    cout << left->evaluate() + "*" + right->evaluate();
}
