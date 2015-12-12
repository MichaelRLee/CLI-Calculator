#include "Addition.h"

/** \brief  Constructor.Creates a new Addition by copying two Expressions to its left and right
 *          halves.
 * \param left A pointer to the left half of the new Expression to create.
 * \param right A pointer to the right half of the new Expression to create.
 *
 */
Addition::Addition(ArithmeticExpression* left, ArithmeticExpression* right) : ArithmeticExpression(left, right)
{
    /*this->left = new ArithmeticExpression(*left); // Copy the given Expression to this Addition's left half
    this->right = new ArithmeticExpression(*right); // Copy the given Expression to this Addition's right half*/
}

/** \brief Destructor. Deletes this Addition and it's left and right halves
 */
Addition::~Addition()
{
    delete this->left; // Delete the left Expression
    delete this->right; // Delete the right Expression
}

/** \brief  Copy constructor. Copies another Addition's left and right halves to this one.
 *
 * \param   other The other Additiown to copy.
 *
 */
Addition::Addition(const Addition& other) : ArithmeticExpression(other)
{
}

/** \brief Assignment operator.
 *
 * \param rhs The other Addition to assign.
 * \return A reference to an Addition.
 *
 */
Addition& Addition::operator=(const Addition& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates the expression.
* \return A string representing the result of the evaluation of the expression.
*/
string Addition::evaluate()
{
    /**
    *   Since the left and right halves are themselves Expressions, we need to evaluate them before
    *   returning the result/
    **/
    //return left->evaluate() + "+" + right->evaluate();
    string lNumStr = left->evaluate(); // Get the number from the left half of the expression
    string rNumStr = right->evaluate(); // Get the number from the right half of the expression
    float lNumF = this->convert(lNumStr); // Convert the left-hand side string to a float
    float rNumF = this->convert(rNumStr); // Convert the right-hand side string to a float
    stringstream ss; // The string stream used to convert the result of the floating-point addition to a string
    ss << lNumF+rNumF; // Place the sum of the floats into the stringstream
    return ss.str(); // Return the string representation of the result of the evaluation
}

/** \brief Prints the expression.
*/
void Addition::print()
{
    left->print(); // Print the left half of the expression
    cout << "+"; // Print the plus sign
    right->print(); // Print the right half of the expression
}
