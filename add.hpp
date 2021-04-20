#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "base.hpp"

using namespace std;
#include <string>


class Add : public Base {
	private:		
	   Base* Base1;
	   Base* Base2;
	public:
	   Add(): Base1(0), Base2(0) {}
	   Add(Base* theBase1) : Base1(thebase1), Base2(0) {}
	   Add(Base* theBase1, Base* theBase2) : Base1(thebase1), Base2(theeBase2) {}
	

	double evaluate() {
			//if both don't exist return 0 
		if (!(Base1 && Base2)){
			return 0.0;
		} 
			//if one exists and not the other
		else if (Base1 && !Base2){
			return Base1->evaluate();
		}
		else {
			return Base1->evaluate() + Base2->evaluate();
		}
	}

	string stringify() {
		if (!(Base1 && Base2)){
			return to_string(0.0) <<  " + " << to_string(0.0);
		}
		else if(Base1 && !Base2) {
			return Base1->stringify() << " + " << to_string(0.0);























