#include "Number.h"
#include <iostream> // cout
#include <cstdlib> // atof
using namespace std;

// Constructor
Number::Number(string num) : ArithmeticExpression(nullptr, nullptr) // Null pointers are used to indicate the end of the Expression
{
    //value = new string(); // Allocate memory for the string
    //value.assign(num); // Store the contents of the number in the new string
    value = num; // Store string
}

Number::~Number() // Destructor
{
    //delete &((*this).value); // Delete the value
    delete &value; // Delete the string which represents the number
}

// Copy constructor
Number::Number(const Number& other) : ArithmeticExpression(nullptr, nullptr) // Null pointers are used to indicate the end of the Expression
{
    //value = new string(other.value); // Copy the other number's value to this one
    value = other.value; // Copy the other number's value
}

Number& Number::operator=(const Number& rhs) // Assignment
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string Number::evaluate() // Returns a string which represents this number
{
    return this->value; // Return the value of this number
}

void Number::print() // Print a string representation of this Number
{
    cout << this->value; // Print the value of this number
}
