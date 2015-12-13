#ifndef EXPRESSION_H
#define EXPRESSION_H

// C++ includes
#include <string> // string
#include <iostream> //cout
#include <sstream> // Stringstream

// C includes
#include <cstdlib> // atof
#include <cstdio> // printf

using namespace std;

class Expression
{
    public:
        /** Constructor */
        //Expression(ArithmeticExpression* ae); // Copies a given arithmeticExpression into this one
        Expression();

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
        //ArithmeticExpression myAE;
};

#endif // EXPRESSION_H
