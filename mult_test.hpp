#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "Mult.hpp"



TEST(MultTest, MultEvaluateNonZero) {
     Op* op1 = new Op(3);
     Op* op2 = new Op(2);
     Mult* mult = new Mult(op1, op2);
     EXPECT_EQ(mult->evaluate(), 6.0);
     EXPECT_EQ(mult->stringify(), "(3.00 * 2.00)");
}


TEST(MultTest, MultEvaluateOneOp) {
     Op* op1 = new Op(3);
     Mult* mult = new Mult(op1);
     EXPECT_EQ(mult->evaluate(), 3.0);
     EXPECT_EQ(mult->stringify(), "(3.00 * 1.00)");
}

TEST(MultTest, MultEvaluateZeroOp) {
     Op* op1 = new Op();
     EXPECT_EQ(op1->evaluate(), 0.0);
     EXPECT_EQ(op1->stringify(), "(0.00 * 1.00)");
}

TEST(MultTest, MultEvaluateNegOp) {
     Op* op1 = new Op(-4);
     Mult* mult = new Mult(op1);
     EXPECT_EQ(mult->evaluate(), -4.0);
     EXPECT_EQ(mult->stringify(), "(-4.00 * 1.00)");
}


TEST(MultTest, MultEvaluateNegOps){
     Op* op1 = new Op(-3);
     Op* op2 = new Op(-5);
     Mult* mult = new Mult(op1, op2);
     EXPECT_EQ(mult->evaluate(), 15.0);
     EXPECT_EQ(mult->stringify(), "(-3.00 * -5.00)");
}

TEST(MultTest, MultEvaluateNegPosOps){
     Op* op1 = new Op(-3);
     Op* op2 = new Op(4);
     Mult* mult = new Mult(op1, op2);
     EXPECT_EQ(mult->evaluate(), -12.0);
     EXPECT_EQ(mult->stringify(), "(-3.00 * 4.00)");
}

TEST(MultTest, MultEvaluateChildren){
   op* op1 = new op(7);
   op* op2 = new op(2);
   op* op3 = new op(3);
   Add* add = new Add(op1, op2);
   Mult* mult = new Mult(op3, add);
   EXPECT_EQ(mult->evaluate(), 27.0);        
   EXPECT_EQ(add->stringify(), "(3.00 * (7.00 + 2.00))");
}

   TEST(MultTest, MultEvaluateChildrenNeg){
   op* op1 = new op(8);
   op* op2 = new op(-5);
   op* op3 = new op(5);
   Add* add = new Add(op1, op2);
   Mult* mult = new Mult(op3, add);
   EXPECT_EQ(mult->evaluate(), 15.00);        
   EXPECT_EQ(add->stringify(), "(5.00 * (8.00 + -5.00))");
}



#endif //__MULT_TEST_HPP__
