#ifndef NUMBER_H
#define NUMBER_H

#include "ArithmeticExpression.h"


class Number : public ArithmeticExpression
{
    public:

        /** Default constructor */
        Number();

        /** Default destructor */
        virtual ~Number();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Number(const Number& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Number& operator=(const Number& other);

        /** \brief Returns this Number's value as a string
         * \return The Number's value as a string.
         */

        string evaluate();

        /** \brief Prints this number's value.
         */
        void print();
    protected:
    private:
        string val; // The value of this number
};

#endif // NUMBER_H
