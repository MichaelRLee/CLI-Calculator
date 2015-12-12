#include "Addition.h"

Addition::Addition(Expression* left, Expression* right):ArithmeticExpression(left,right){}

Addition::~Addition()
{
    delete left;
    delete right;
}

Addition::Addition(const Addition& other):ArithmeticExpression(other)
{

}

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
    *   combining them with an addition sign.
    **/
    return left->evaluate() + "+" + right->evaluate();
}

/** \brief Prints the expression.
*/
void Addition::print()
{
    cout << this->evaluate(); // Print the evaluated expression
}
