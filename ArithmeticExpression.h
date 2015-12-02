#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include "Expression.h"


class ArithmeticExpression : public Expression
{
    public:
        /** Default constructor */
        ArithmeticExpression();
        /** Default destructor */
        virtual ~ArithmeticExpression();
        /** Copy constructor
         *  \param other Object to copy from
         */
        ArithmeticExpression(const ArithmeticExpression& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        ArithmeticExpression& operator=(const ArithmeticExpression& other);
        /** Access left
         * \return The current value of left
         */
        Expression Getleft() { return left; }
        /** Set left
         * \param val New value to set
         */
        void Setleft(Expression val) { left = val; }
        /** Access right
         * \return The current value of right
         */
        Expression Getright() { return right; }
        /** Set right
         * \param val New value to set
         */
        void Setright(Expression val) { right = val; }
    protected:
    private:
        Expression left; //!< Member variable "left"
        Expression right; //!< Member variable "right"
};

#endif // ARITHMETICEXPRESSION_H
