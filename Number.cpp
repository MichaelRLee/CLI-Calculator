#include "Number.h"

/** \brief Constructs a number object with the given value as a string (for evaluate)
 *
 * \param The string representation of the value of this number.
 *
 */
Number::Number(string sVal)
{
    this.val = sVal; // Store the number's value as a string
    /**
    *   TODO:
    *   -----
    *   1) Add a check to ensure that the string represents a valid integer?
    **/
}

// Destructor
Number::~Number()
{
    delete val; // De-allocate memory for this number's value
}

// Copy constructor
Number::Number(const Number& other)
{
}

Number& Number::operator=(const Number& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
