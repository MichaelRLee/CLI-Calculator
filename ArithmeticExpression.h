#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include "Expression.h"

class ArithmeticExpression : public Expression
{
    public:

        /** Default constructor */
        ArithmeticExpression () {}

        ArithmeticExpression(Expression* left, Expression* right);

        ArithmeticExpression(Expression* finalExp);

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
        Expression* Getleft() { return left; }

        /** Set left
         * \param val New value to set
         */
        void Setleft(Expression* val) { left = val; }

        /** Access right
         * \return The current value of right
         */
        Expression* Getright() { return right; }

        /** Set right
         * \param val New value to set
         */
        void Setright(Expression* val) { right = val; }

        /** \brief Evaluates left and right expression and combines them with the appropriate operator.
         * \return A string representation of the result.
         */
        string evaluate();

        /** \brief Prints the evaluated expression.
         */
        void print();

        /** \brief Converts a string (as returned by evaluate) to a float.
         *
         * \param s The string representing the value to convert to a floating-point number.
         * \return A floating-point representation of the string.
         */
        float convert(string s);
        void increment();
    protected:
        Expression *left; //!< Member variable "left"
        Expression *right; //!< Member variable "right"
    private:
};

#endif // ARITHMETICEXPRESSION_H
