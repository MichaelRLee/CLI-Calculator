#include "Division.h"

/** \brief Constructor. Builds a new Division expression by adding 2 expressions to its left and right.
 *
 * \param left A pointer to the Expression which will become this Division's left half.
 * \param right A pointer to the Expression which will become this Division's right half.
 *
 */
Division::Division(Expression& left, Expression& right)
{
    this->left = new Expression(left); // Copy the left Expression to this Division's left half
    this->right = new Expression(right); // Copy the right Expression to this Division's right half
}

/** \brief Destroys this Division object.
 *
 * \return
 *
 */
Division::~Division()
{
    delete this->left; // Deletes the left half of this Division
    delete this->right; // Deletes the right half of this Division
}

/** \brief Copy constructor. Copies another Division's left and right halves to this one.
 *
 * \param
 * \param
 * \return
 *
 */
Division::Division(const Division& other)
{
    this->left = new Expression(other->left); // Copy the left half of the other Expression to this Division
    this->right = new Expression(other->right); // Copy the right half of the other Expression to this one
}

Division& Division::operator=(const Division& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression.
* \return A string describing the result of the evaluation of the expression.
*/
string Division::evaluate()
{
    string lNumStr = left->evaluate(); // Get the number from the left half of the expression
    string rNumStr = right->evaluate(); // Get the number from the right half of the expression
    float lNumF = this->convert(lNumStr); // Convert the left-hand side string to a float
    float rNumF = this->convert(rNumStr); // Convert the right-hand side string to a float
    stringstream ss; // The string stream used to convert the result of the floating-point addition to a string
    ss << lNumF/rNumF; // Place the quotient of the division of the floats into the stringstream
    return ss.str(); // Return the string representation of the result of the evaluation
}

/** \brief Prints the expression.
*/
void Division::print()
{
    cout << left->print() + "/" + right->print(); // Print the left and right halves, separated by a '/'
}
