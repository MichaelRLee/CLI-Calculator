#ifndef NUMBER_H
#define NUMBER_H

#include "ArithmeticExpression.h"

class Number : public ArithmeticExpression
{
    public:
        /** Default constructor */
        Number(string num);

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

        /** Access value
         * \return The current value of value
         */
        string Getvalue() { return value; }

        /** Set value
         * \param val New value to set
         */
        void Setvalue(string val) { value = val; }

        string evaluate(); // Returns a string representation of this Number

        float convert(); // Converts this number to a floating-point representation

        void print(); // Prints this number
        void increment();
    protected:
    private:
        string value; // The value of this number
};

#endif // NUMBER_H
