#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "Mult.hpp"


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
     EXPECT_EQ(mult->evaluate(), 0.0);
     EXPECT_EQ(mult->stringify(), "0.0 * 1.0");
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






#endif //__MULT_TEST_HPP__
