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
        Op(double value) : Base() { }
        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return ""; }
};

#endif //__OP_HPP__
