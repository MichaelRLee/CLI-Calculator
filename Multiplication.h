#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "ArithmeticExpression.h"


class Multiplication : public ArithmeticExpression
{
    public:
        /** Default constructor */
        Multiplication();

        /** Default destructor */
        virtual ~Multiplication();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Multiplication(const Multiplication& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Multiplication& operator=(const Multiplication& other);

        /** \brief Evaluates the expression.
         * \return A string representation of the result of the evaluation of this expression.
         */
        string evaluate();

        /** \brief Prints left '*' right.
         */
        void print();
    protected:
    private:
};

#endif // MULTIPLICATION_H
