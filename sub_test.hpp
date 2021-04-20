#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "Sub.hpp"
#include "Add.hpp"
#include "Mult.hpp"

TEST(SubTest, subtraction) {
     //2 operators
     Op* op1 = new Op(5);
     Op* op2  = new Op(5);
     Sub* sub1 = new Sub(op1, op2);
     EXPECT_EQ(sub1->evaluate(), 0.0);
     EXPECT_EQ(sub1->stringify(), "(5.0 - 5.0)");

     //1 operator
     Op* op3  = new Op(5.5);
     Sub* sub2 = new Sub(op3);
     EXPECT_EQ(sub2->evaluate(), 5.5);
     EXPECT_EQ(sub2->stringify(), "(5.5 - 0.0)");

     //0 operator
     Sub* sub3 = new Sub();
     EXPECT_EQ(sub3->evaluate(), 0.0);
     EXPECT_EQ(sub3->stringify(), "(0.00 - 0.00)");


     // negative operator (1)
     Op* op4  = new Op(-3);
     Sub* sub4 = new Sub(op4);
     EXPECT_EQ(sub4->evaluate(), -3.0);
     EXPECT_EQ(sub4->stringify(), "(-3.0 - 0.0)");

     // negative operators (2)
     Op* op5 = new Op(-3);
     Op* op6 = new Op(-2);
     Sub* sub5 = new Sub(op5, op6);
     EXPECT_EQ(sub5->evaluate(), -1.0);
     EXPECT_EQ(sub5->stringify(), "(-3.0 - -2.0)");
               
     //children 
   Op* op7 = new Op(5);
   Op* op8 = new Op(8);
   Op* op9 = new Op(5);
   Mult* mult = new Mult(op7, op8);
   Sub* sub6 = new Sub(op9, mult);
   EXPECT_EQ(mult->evaluate(), -35.0);        
   EXPECT_EQ(sub6->stringify(), "(5.0 - (5.0 * 8.0))");
               
   
    //children w/ neg
   Op* op10 = new Op(-3);
   Op* op11 = new Op(2);
   Op* op12 = new Op(-4);
   Add* add = new Add(op10, op11);
   Sub* sub7 = new Sub(op12, add);
   EXPECT_EQ(add->evaluate(), -3.0);        
   EXPECT_EQ(sub7->stringify(), "(-4.0 - (-3.0 + 2.0))");


 }




 #endif //__SUB_TEST_HPP__



