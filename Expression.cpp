/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Stores top level expression or number
*/

#include "Expression.h" 

Expression::Expression() //empty constructor
{
    value="0";
    exp=NULL;
}


Expression::Expression(Expression* exp)//new constructor
{
    this->exp=exp;
}


Expression::Expression(string str):value(str),exp(NULL)//number constructor
{
}

Expression::~Expression()//destructor
{
    if (exp!=NULL) delete exp;//delete the pointer if it's there (will delete other new's)
}

Expression::Expression(const Expression& other)//blank copy constructor
{
}

//Copy whole constructor dependent on self assignment
Expression& Expression::operator=(const Expression& rhs)
{
    if (this == &rhs) return *this; 
    this->value = rhs.value;
    this ->exp = rhs.exp;
    return *this;
}

string Expression::evaluate() //evaluate expression and return value as a string
{
    if (exp!=NULL) return exp->evaluate();//if there's already an equation, compute otherwise return number
    else return value;
}

//print the expression
void Expression::print()
{
    if (exp!=NULL) exp->print();//if there's an expression stored, print
    else {
        if (convert()<0) cout << "(" << value << ")";//if negative print w/ brackets
        else cout << value;//otherwise just print numbers
    }
}

// Converts a string (as returned by evaluate) to a float.
float Expression::convert() 
{
    if (exp!=NULL) return exp->convert(); //if there's an expression, call convert on it
    else return atof(this->value.c_str()); // Convert it to a float
}

//Increases digits by one
void Expression::increment()
{
    if (exp!=NULL) exp->increment();//if expression, call it's increment
    else
    {
        stringstream temp;//temp string
        temp << atoi(value.c_str())+1;//add one to integer and convert to string
        value = temp.str();//return string
    }
}
