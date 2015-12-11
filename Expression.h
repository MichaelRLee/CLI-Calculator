#ifndef EXPRESSION_H
#define EXPRESSION_H

// C++ includes
#include <string> // string
#include <iostream> //cout
#include <sstream> // stringstream

// C includes
#include <cstdlib> // atof
#include <cstdio> // printf

// Our classes

class ArithmeticExpression;
#include "ArithmeticExpression.h"

using namespace std;

class Expression
{
    public:
        /** Constructs an Expression containing an ArithmeticExpression. */
        Expression(ArithmeticExpression& contained);

        /** Default destructor */
        virtual ~Expression();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Expression(const Expression& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Expression& operator=(const Expression& other);

        virtual string evaluate(); // Evaluates the expression
        virtual void print(); // Prints the evaluated expression
    protected:
    private:
};

#endif // EXPRESSION_H
