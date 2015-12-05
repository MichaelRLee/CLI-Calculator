#include "Number.h"
#include <iostream> // cout
#include <cstdlib> // atof
using namespace std;

Number::Number(string num) // Constructor
{
    this->value = num; // Store the number
}

Number::~Number() // Destructor
{
    delete &((*this).value); // Delete the value
}

Number::Number(const Number& other) // Copy constructor
{
    this->value = other.value; // Copy the other number's value to this one
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

float Number::convert() // Convert this number to a floating-point representation
{
    return atof(this->value.c_str()); // Convert it to a float
}
