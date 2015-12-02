#ifndef EXPRESSION_H
#define EXPRESSION_H


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
    protected:
    private:
};

#endif // EXPRESSION_H
