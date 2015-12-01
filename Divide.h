#ifndef DIVIDE_H
#define DIVIDE_H

#include "ArithmeticExpression.h"


class Divide : public ArithmeticExpression
{
    public:
        /** Default constructor */
        Divide();

        /** Default destructor */
        virtual ~Divide();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Divide(const Divide& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Divide& operator=(const Divide& other);

        /** \brief Evaluates the expression and returns a string containing the result.
         * \return A string representation of the result of the division.
         */
        string evaluate();

        /** \brief Prints leftExpr '/' rightExpr.
         */
        void print();
    protected:
    private:
};

#endif // DIVIDE_H
