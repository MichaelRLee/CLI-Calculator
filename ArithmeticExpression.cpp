#include "ArithmeticExpression.h"

/** \brief  Constructs a new ArithmeticExpression by copying the given left and right halves to
 *          this ArithmeticExpression's left and right halves. This is done because an
 *          an ArithmeticExpression contains more ArithmeticExpressions - it is a recursive object.
 * \param   left The ArithmeticExpression to copy to this ArithmeticExpression's left half.
 * \param   right The ArithmeticExpression to copy to this ArithmeticExpression's right half.
 * \return  A new ArithmeticExpression.
 *
 */
ArithmeticExpression::ArithmeticExpression(Expression* left, Expression* right) : ArithmeticExpression(left, right)
{
    if (left != nullptr && right != nullptr) // Check for base case (Number at the bottom of the tree)
    {
        this->left = new Expression(*left); // Copy the given ArithmeticExpression to this ArithmeticExpression's left half
        this->right = new Expression(*right); // Copy the given Expression to this ArithmeticExpression's right half
    }

    else
    {
        left = nullptr; // Store a null pointer to indicate the end of the tree
        right = nullptr; // Store a null pointer to indicate the end of the tree
    }
}

/** \brief Destroys an ArithmeticExpression.
 */
ArithmeticExpression::~ArithmeticExpression()
{
    delete this->left; // Delete the left half
    delete this->right; // Delete the right half
}

/** \brief Copies a given ArithmeticExpression's left and right halves to this one.
 *
 * \param other The other ArithmeticExpression to copy from.
 * \return A new ArithmeticExpression containing the other one's left and right halves.
 *
 */
ArithmeticExpression::ArithmeticExpression(const ArithmeticExpression& other)
{
    this->left = new Expression(*(other).left); // Construct the left half of this expression
    this->right = new Expression(*(other).right); // Construct the right half of this expression
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
