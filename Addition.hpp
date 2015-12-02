#ifndef ADDITION_H
#define ADDITION_H

#include "ArithmeticExpression.hpp"


class Addition : public ArithmeticExpression
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

        /** \brief Evaluates the expression.
         * \return A string representing the result of the evaluation of the expression.
         */
        string evaluate();

        /** \brief Prints the expression.
         */
        void print();
    protected:
    private:
};

#endif // ADDITION_H
