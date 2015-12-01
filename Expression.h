#ifndef EXPRESSION_H
#define EXPRESSION_H

/* Includes */
#include <string> // string

/* Namespaces */
using namespace std; // Use the standard namespace

class Expression
{
    public:
        /** Default constructor */
        Expression();

        /** Default destructor */
        virtual ~Expression();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Expression(const Expression& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Expression& operator=(const Expression& other);

        virtual string evaluate(); // Evaluate expression and return string representation of the result
        virtual void print(); // Prints expression

    protected:
    private:
};

#endif // EXPRESSION_H
