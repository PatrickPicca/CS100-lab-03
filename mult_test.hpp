#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "Mult.hpp"
#include "Add.hpp"


TEST(MultTest, MultEvaluateNonZero) {
     Op* op1 = new Op(3);
     Op* op2 = new Op(2);
     Mult* mult = new Mult(op1, op2);
     EXPECT_EQ(mult->evaluate(), 6.0);
     EXPECT_EQ(mult->stringify(), "3.0 * 2.0");
}


TEST(MultTest, MultEvaluateOneOp) {
     Op* op1 = new Op(3);
     Mult* mult = new Mult(op1);
     EXPECT_EQ(mult->evaluate(), 3.0);
     EXPECT_EQ(mult->stringify(), "3.0 * 1.0");
}

TEST(MultTest, MultEvaluateZeroOp) {
     Op* op1 = new Op();
     EXPECT_EQ(op1->evaluate(), 0.0);
     EXPECT_EQ(op1->stringify(), "0.0 * 1.0");
}

TEST(MultTest, MultEvaluateNegOp) {
     Op* op1 = new Op(-4);
     Mult* mult = new Mult(op1);
     EXPECT_EQ(mult->evaluate(), -4.0);
     EXPECT_EQ(mult->stringify(), "-4.0 * 1.0");
}


TEST(MultTest, MultEvaluateNegOps){
     Op* op1 = new Op(-3);
     Op* op2 = new Op(-5);
     Mult* mult = new Mult(op1, op2);
     EXPECT_EQ(mult->evaluate(), 15.0);
     EXPECT_EQ(mult->stringify(), "-3.0 * -5.0");
}

TEST(MultTest, MultEvaluateNegPosOps){
     Op* op1 = new Op(-3);
     Op* op2 = new Op(4);
     Mult* mult = new Mult(op1, op2);
     EXPECT_EQ(mult->evaluate(), -12.0);
     EXPECT_EQ(mult->stringify(), "-3.0 * 4.0");
}

TEST(MultTest, MultEvaluateChildren){
   Op* op1 = new Op(7);
   Op* op2 = new Op(2);
   Op* op3 = new Op(3);
   Add* add = new Add(op1, op2);
   Mult* mult = new Mult(op3, add);
   EXPECT_EQ(mult->evaluate(), 27.0);        
   EXPECT_EQ(add->stringify(), "3.0 * (7.0 + 2.0)");
}

   TEST(MultTest, MultEvaluateChildrenNeg){
   Op* op1 = new Op(8);
   Op* op2 = new Op(-5);
   Op* op3 = new Op(5);
   Add* add = new Add(op1, op2);
   Mult* mult = new Mult(op3, add);
   EXPECT_EQ(mult->evaluate(), 15.0);        
   EXPECT_EQ(add->stringify(), "5.0 * (8.0 + -5.0)");
}



#endif //__MULT_TEST_HPP__
