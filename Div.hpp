#ifndef __DIV_HPP__
#define __DIV_HPP__
#include "base.hpp"
#include <string>
using namespace std;

class Div : public Base {
    private:
         Base* Base1;
         Base* Base2;

    public:
	Div(): Base1(0), Base2(0) {}
	Div(Base* theBase1) : Base1(theBase1), Base2(0) {}
	Div(Base* theBase1, Base* theBase2) : Base1(theBase1), Base2(theBase2) {}

    double evaluate(){
	if(!Base1 && !Base2)
	{ 
		return 0.0;
	} 
        else if(Base1 && !Base2)
	{
		 return Base1->evaluate();
	} 
        else 
	{
		if(Base2->evaluate() == 0)
		{
			return -1; //Divide by 0 error.
		}
		else 
		{
		    return Base1->evaluate() /  Base2->evaluate();
	        }
        }
    }
};
#endif
