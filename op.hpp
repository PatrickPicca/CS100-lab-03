#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>
using namespace std;

class Op : public Base {
    private:
	double number;
    public:
	Op() : number(0) {}
        Op(double Number) : number(Number) {}
        virtual double evaluate() { return number; }
        virtual std::string stringify() { return to_string(number); }
};

#endif //__OP_HPP__
