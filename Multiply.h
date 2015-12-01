#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "ArithmeticExpression.h"


class Multiply : public ArithmeticExpression
{
    public:
        /** Default constructor */
        Multiply();

        /** Default destructor */
        virtual ~Multiply();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Multiply(const Multiply& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Multiply& operator=(const Multiply& other);

        /** \brief Evaluates the expression and returns the result as a string.
         *
         * \return A string representation of the result of the evaluation of this expression
         *
         */
        string evaluate();

        /** \brief Prints leftExpr '*' rightExpr.
         */
        void print();
    protected:
    private:
};

#endif // MULTIPLY_H
