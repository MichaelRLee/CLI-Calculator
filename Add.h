#ifndef ADD_H
#define ADD_H

#include "ArithmeticExpression.h"


class Add : public ArithmeticExpression
{
    public:
        /** Default constructor */
        Add();

        /** Default destructor */
        virtual ~Add();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Add(const Add& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Add& operator=(const Add& other);

        /** \brief Evaluates the addition and returns the result as a string.
         *
         * \return A string representing the result of the addition.
         *
         */

        string evaluate();

        void print(); // Prints leftExpr '+' rightExpr

    protected:
    private:
};

#endif // ADD_H
