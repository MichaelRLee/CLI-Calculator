/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Stores equations
*/

#include "ArithmeticExpression.h"//header

ArithmeticExpression::ArithmeticExpression()//blank constructor
{
    left=NULL;//null val
    right=NULL;//null val
}

ArithmeticExpression::ArithmeticExpression(Expression* left, Expression* right):left(left), right (right){}//assigns left and right

ArithmeticExpression::ArithmeticExpression(Expression* finalExp):left(finalExp), right(NULL){}//if equation

ArithmeticExpression::~ArithmeticExpression()//doesn't need to delete, children will do it for it
{
}

ArithmeticExpression::ArithmeticExpression(const ArithmeticExpression& other)//"copy" constructor
{
    this->left = new ArithmeticExpression(other.left); // Copy the other Expression to this one
    this->right = new ArithmeticExpression(other.right); // Copy the other Expression to this one
}

ArithmeticExpression& ArithmeticExpression::operator=(const ArithmeticExpression& rhs)//real copy constructor
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;//return this
}

/** \brief Evaluates left and right expression and combines them with the appropriate operator.
* \return A string representation of the result.
*/
string ArithmeticExpression::evaluate()
{
    return left->evaluate(); // Evaluate the left half of the Expression
}

/** \brief Prints the evaluated expression.
*/
void ArithmeticExpression::print()
{
    left->print();//print expression
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


void ArithmeticExpression::increment()//increases digits by one
{
    left -> increment();//tell left hand to do it
    if (right!=NULL)right -> increment();//tell right hand to do it if it's delcared
}

