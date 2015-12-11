#include "Multiplication.h"

/** \brief Constructor. Creates a new Multiplication expression by copying two Expressions to its
 *          left and right halves.
 * \param   left The Expression to copy to this Multiplication's LHS.
 * \param   right The Expression to copy to this Multiplication's RHS.
 * \return
 *
 */
Multiplication::Multiplication(Expression& left, Expression& right)
{
    this->left = new Expression(left); // Copy the given Expression to this Multiplication's LHS
    this->right = new Expression(right); // Copy the given Expression to this Multiplication's RHS
}

/** \brief Destructor. Frees this Multiplication's memory
 *
 * \return
 *
 */
Multiplication::~Multiplication()
{
    delete this->left; // Delete the left half of this Multiplication
    delete this->right; // Delete the right half of this Multiplication
}

/** \brief Copy constructor. Copies a given Multiplication object's left and right halves to this
 *          Multiplications'.
 * \param   other The other Multiplication to copy.
 * \param
 * \return
 *
 */
Multiplication::Multiplication(const Multiplication& other)
{
    this->left = new Expression(other->left); // Copy the LHS of the other Multiplication
    this->right = new Expression(other->right); // Copy the RHS of the other Multiplication
}

/** \brief Assignment operator.
 *
 * \param
 * \param
 * \return A reference to a new Multiplication
 *
 */
Multiplication& Multiplication::operator=(const Multiplication& rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

/** \brief Evaluates this Multiplication.
 *
 * \param
 * \param
 * \return A string representing the result of the evaluation.
 *
 */
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

/** \brief Prints this Multiplication.
 *
 * \param
 * \param
 * \return
 *
 */
void Multiplication::print()
{
    cout << left->print() + "*" + right->print(); // Print the left and right halves, separated by an asterisk
}
