#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "Sub.hpp"

TEST(SubTest, subtraction) {
     //2 operators
     op* op1 = new op(5);
     op* op2  = new op(5);
     Sub* sub1 = new Sub(op1, op2);
     EXPECT_EQ(sub1->evaluate(), 0.0);
     EXPECT_EQ(sub1->stringify(), "5.0 - 5.0");

     //1 operator
     op* op3  = new op(5.5);
     Sub* sub2 = new Sub(op3);
     EXPECT_EQ(sub2->evaluate(), 5.5);
     EXPECT_EQ(sub2->stringify(), "5.5 - 0.0");

     //0 operator
     Sub* sub3 = new Sub();
     EXPECT_EQ(sub3->evaluate(), 0.0);
     EXPECT_EQ(sub3->stringify(), "0.000000 - 0.000000");


     // negative operator (1)
     op* op4  = new op(-3);
     Sub* sub4 = new Sub(op4);
     EXPECT_EQ(sub4->evaluate(), -3.0);
     EXPECT_EQ(sub4->stringify(), "-3.0 - 0.0");

     // negative operators (2)
     op* op5 = new op(-3);
     op* op6 = new op(-2);
     Sub* sub5 = new Sub(op5, op6);
     EXPECT_EQ(sub5->evaluate(), -1.0);
     EXPECT_EQ(sub5->stringify(), "-3.0 - -2.0");
               
               
     //children 
   op* op7 = new op(5);
   op* op8 = new op(8);
   op* op9 = new op(5);
   Mult* mult = new Mult(op7, op8);
   Sub* sub6 = new Sub(op9, mult);
   EXPECT_EQ(mult->evaluate(), -35.0);        
   EXPECT_EQ(sub6->stringify(), "5.0 - (5.0 * 8.0)");
               
   
    //children w/ neg
   op* op10 = new op(-3);
   op* op11 = new op(2);
   op* op12 = new op(-4);
   Add* add = new Add(op10, op11);
   Sub* sub7 = new Sub(op12, add);
   EXPECT_EQ(add->evaluate(), -3.0);        
   EXPECT_EQ(sub7->stringify(), "-4.0 - (-3.0 + 2.0)");


 }




 #endif //__SUB_TEST_HPP__



