#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "ArithmeticExpression.h"

// Subtracts 2 expressions
class Subtract : public ArithmeticExpression
{
    public:
        /** Default constructor */
        Subtract();

        /** Default destructor */
        virtual ~Subtract();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Subtract(const Subtract& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Subtract& operator=(const Subtract& other);

        string evaluate(); // Evaluates the expression and returns the result as a string

        void print(); // Prints leftExpr '-' rightExpr
    protected:
    private:
};

#endif // SUBTRACT_H
