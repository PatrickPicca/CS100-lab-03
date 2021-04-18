#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "Add.hpp"


TEST(AddTest, addition) {
    //2 operators
    op* op1 = new op(5);
    op* op2  = new op(5);
    Add* add1 = new Add(op1, op2);
    EXPECT_EQ(add1->evaluate(), 10.0);
    EXPECT_EQ(add1->stringify(), "5.0 + 5.0");

   //1 operator
        op* op3  = new op(5.5);
        Add* add2 = new Add(op3);
        EXPECT_EQ(add2->evaluate(), 5.5);
        EXPECT_EQ(add2->stringify(), "5.5 + 0.0");

    //0 operator
        Add* add3 = new Add();
        EXPECT_EQ(add3->evaluate(), 0.0);
        EXPECT_EQ(add3->stringify(), "0.000000 + 0.000000");

    // negative operator (1)
    op* op4  = new op(-3);
        Add* add4 = new Add(op4);
        EXPECT_EQ(add4->evaluate(), -3.0);
        EXPECT_EQ(add4->stringify(), "-3.0 + 0.0");


    // negative operators (2)
    op* op5 = new op(-3);
    op* op6 = new op(-3);
    Add* add5 = new Add(op5, op6);
    EXPECT_EQ(add5->evaluate(), -6.0;
    EXPECT_EQ(add5->stringify(), "-3.0 + -3.0");

   //children 
   op* op7 = new op(4);
   op* op8 = new op(3);
   op* op9 = new op(6);
   Mult* mult1 = new Mult(op7, op8);
   Add* add6 = new Add(op9, mult1);
   EXPECT_EQ(mult1->evaluate(), 18.0);        
   EXPECT_EQ(add1->stringify(), "6.0 + 4.0 * 3.0");
    
   // children with negatives           
   op* op10 = new op(5);
   op* op11 = new op(-2);
   op* op12 = new op(6);
   Mult* mult2 = new Mult(op10, op11);
   Add* add7 = new Add(op12, mult2);
   EXPECT_EQ(mult1->evaluate(), -4.0);        
   EXPECT_EQ(add1->stringify(), "6.0 + 5.0 * -2.0");           
              
             
              
}




#endif //__ADD_TEST_HPP__
