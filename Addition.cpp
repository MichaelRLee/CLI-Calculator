/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: This file runs the program
*/

#include "Addition.h"//header

Addition::Addition(Expression* left, Expression* right):ArithmeticExpression(left,right){} //constructor assigns left and right

Addition::~Addition()//deletes left and right
{
    delete left;//delete left
    delete right;//dealocate right
}

Addition::Addition(const Addition& other):ArithmeticExpression(other)//assigns arithmetic expression
{

}

Addition& Addition::operator=(const Addition& rhs) //copy constructor
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this; //return this
}

/** \brief Evaluates the expression.
* \return A string representing the result of the evaluation of the expression.
*/
string Addition::evaluate()
{
    string lEval = left->evaluate(); // Store the evaluated left half
    string rEval = right->evaluate(); // Store the evaluated right half
    float lNum = this->convert(lEval); // Convert the evaluated left half to a float
    float rNum = this->convert(rEval); // Convert the evaluated right half to a float
    stringstream ss; // Stringstream for converted a float to a string
    ss << lNum+rNum; // Store the sum of the 2 halves in the stringstream
    return ss.str(); // Convert the sum to a string and return it
}

/** \brief Prints the expression.
*/
void Addition::print()
{
    cout << "("; //bracket
    left -> print();//lhs
    cout << "+";//+
    right -> print();//rhs
    cout << ")";//bracket
    //cout << this->evaluate(); // Print the evaluated expression
}


void Addition::increment()//increase value of digits by 1
{
    left -> increment();//tell lhs to do it
    right -> increment();//tell hrs to do it
}
