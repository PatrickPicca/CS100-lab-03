#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "Div.hpp"
#include "Add.hpp"


 TEST(DivTest, DivEvaluateNonZero) {
      Op* op1 = new Op(10);
      Op* op2 = new Op(2);
      Div* div = new Div(op1, op2);
      EXPECT_EQ(div->evaluate(), 5.0);
      EXPECT_EQ(div->stringify(), "(10.0 / 2.0)");
 }


 TEST(DivTest, DivEvaluateNonZero2) {
      Op* op1 = new Op(11);
      Op* op2 = new Op(2);
      Div* div = new Div(op1, op2);
      EXPECT_EQ(div->evaluate(), 5.5);
      EXPECT_EQ(div->stringify(), "(11.0 / 2.0)");
 }


 TEST(DivTest, DivEvaluateOneOp) {
      Op* op1 = new Op(3);
      Div* div = new Div(op1);
      EXPECT_EQ(div->evaluate(), 3.0);
      EXPECT_EQ(div->stringify(), "(3.0 / 1.0)");
 }

 TEST(DivTest, DivEvaluateZeroOp) {
      Op* op1 = new Op();
      EXPECT_EQ(op1->evaluate(), 0.0);
      EXPECT_EQ(op1->stringify(), "(0.0 / 1.0)");
 }


TEST(DivTest, DivEvaluateNegOp) {
      Op* op1 = new Op(-7);
      Div* div = new Div(op1);
      EXPECT_EQ(div->evaluate(), -7.0);
      EXPECT_EQ(div->stringify(), "(-7.0 / 1.0)");
 }

TEST(DivTest, DivEvaluateNegOps) {
      Op* op1 = new Op(-10);
      Op* op2 = new Op(-2);
      Div* div = new Div(op1, op2);
      EXPECT_EQ(div->evaluate(), 5.0);
      EXPECT_EQ(div->stringify(), "(-10.0 / -2.0)");
 }

TEST(DivTest, DivEvaluateNegPosOps) {
      Op* op1 = new Op(-10);
      Op* op2 = new Op(2);
      Div* div = new Div(op1, op2);
      EXPECT_EQ(div->evaluate(), -5.0);
      EXPECT_EQ(div->stringify(), "(-10.0 / 2.0)");
 }

TEST(DivTest, DivEvaluateByZero) {
      Op* op1 = new Op(7);
      Op* op2 = new Op(0);
      Div* div = new Div(op1, op2);
      EXPECT_EQ(div->evaluate(), -1);
      EXPECT_EQ(div->stringify(), "Undefined");
 }

TEST(DivTest, DivEvaluateChildren){
   Op* op1 = new Op(5);
   Op* op2 = new Op(5);
   Op* op3 = new Op(2);
   Add* add = new Add(op1, op2);
   Div* div = new Div(add, op3);
   EXPECT_EQ(div->evaluate(), 5.0);        
   EXPECT_EQ(div->stringify(), "((5.0 + 5.0) / 2.0)");
}

   TEST(DivTest, DivEvaluateChildrenNeg){
   Op* op1 = new Op(8);
   Op* op2 = new Op(-2);
   Op* op3 = new Op(12);
   Add* add = new Add(op1, op2);
   Div* div = new Div(op3, add);
   EXPECT_EQ(div->evaluate(), 2.0);        
   EXPECT_EQ(div->stringify(), "(12.0 / (8.0 + -2.0))");
}

 #endif //__DIV_TEST_HPP__








