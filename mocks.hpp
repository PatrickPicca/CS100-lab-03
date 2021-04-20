ifndef __MOCKS_HPP__
#define __MOCKS_HPP__

#include <string>



// testing double

class SevenOpMock: public Base {
    public:
 	SevenOpMock() { }

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
}


//testing negative value 

class NegativeOpMock: public Base {
    public:
        NegativeOpMock() { }

        virtual double evaluate() { return -4.0; }
        virtual string stringify() { return "-4.0"; }
}

//testing zero 

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { }

        virtual double evaluate() { return 0.0; }
        virtual string stringify() { return "0.0"; }
}




#endif //__MOCKS_HPP__











