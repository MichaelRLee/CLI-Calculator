#ifndef DIVISION_H
#define DIVISION_H

#include "ArithmeticExpression.h"

class Division : public ArithmeticExpression
{
    public:
        /** Default constructor */
        Division();

        /** Default destructor */
        virtual ~Division();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Division(const Division& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Division& operator=(const Division& other);

        /** \brief Evaluates the expression.
         * \return A string describing the result of the evaluation of the expression.
         */
        string evaluate();

        /** \brief Prints the expression.
         */
        void print();
    protected:
    private:
};

#endif // DIVISION_H
