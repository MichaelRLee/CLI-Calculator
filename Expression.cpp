/*
* Name: Michael Robert Lee, Victor Carri, Shilp Pancholi
* MacID: leemr2, carriva, panchosm
* Student Number: 1406823, 001406904, 1419055
* Description: Stores top level expression or number
*/

#include "Expression.h" //header

Expression::Expression() //blank constructor
{
    value="0";//zero
    exp=NULL;//null
}


Expression::Expression(Expression* exp)//new constructor
{
    this->exp=exp;//assign pointer
}


Expression::Expression(string str):value(str),exp(NULL)//number constructor
{
}

Expression::~Expression()//delete
{
    if (exp!=NULL) delete exp;//delete the pointer if it's there (will delete other new's)
}

Expression::Expression(const Expression& other)//blank copy constructor
{
    //copy ctor
}

Expression& Expression::operator=(const Expression& rhs)//other copy constructor
{
    if (this == &rhs) return *this; // handle self assignment
    this->value = rhs.value;//assign value
    this ->exp = rhs.exp;//assign value
    return *this;//ret val
}

string Expression::evaluate() //evaluate expression
{
    if (exp!=NULL) return exp->evaluate();//if there's already an equation, compute
    else return value;//otherwise return number
}

void Expression::print()//print
{
    if (exp!=NULL) exp->print();//if there's an expression stored, print
    else {//otherwise
        if (convert()<0) cout << "(" << value << ")";//if negative print w/ brackets
        else cout << value;//otherwise just print numbers
    }
}

float Expression::convert() // Convert this number to a floating-point representation
{
    if (exp!=NULL) return exp->convert(); //if there's an expression, call convert on it
    else return atof(this->value.c_str()); // Convert it to a float
}

void Expression::increment()//increment digit
{
    if (exp!=NULL) exp->increment();//if expression, call it's increment
    else//otherise
    {
        stringstream temp;//temp string
        temp << atoi(value.c_str())+1;//add one to integer and convert to string
        value = temp.str();//return string
    }
}
