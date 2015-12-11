#include "Expression.h"

/** \brief  Constructor. Creates a new Expression containing an ArithmeticExpression by
 *          assigning it to this Expression's private variable.
 */
Expression::Expression(ArithmeticExpression& contained)
{
    this->contained = new ArithmeticExpression(contained); // Copy the ArithmeticExpression to this Expression's container
}

/** \brief Destructor. Destroys an Expression object by deleting it's left and right halves.
 */
Expression::~Expression()
{
    delete this->contained; // Delete the contained ArithmeticExpression
}

/** \brief Copy constructor. Copies another Expression's ArithmeticExpression object to
 *         this one's object.
 * \param  other The other Expression to copy the ArithmeticExpression of.s
 */
Expression::Expression(const Expression& other)
{
    this->contained = new ArithmeticExpression(other->contained); // Copy the contained ArithmeticExpression from the other Expression to this one
}

Expression& Expression::operator=(const Expression& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** \brief Evaluates an Expression by evaluating its contained ArithmeticExpression.
 * \return A string containing the result of the evaluated Expression.
 */
string Expression::evaluate()
{
    return this->contained.evaluate(); // Return the result of the evaluated ArithmeticExpression
}

/** \brief Prints an Expression by printing it's contained ArithmeticExpression object.
 */
void Expression::print()
{
    cout << this->evaluate(); // Print the evaluated ArithmeticExpression
}
