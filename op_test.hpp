#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

#include "Rand.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}
//zero value
TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

//negative value 
TEST(OpTest, OpEvaluateNegative) {
    Op* test = new Op(-2);
    EXPECT_EQ(test->evaluate(), -2);
}

//rand

TEST(RandTest, OpEvaluateNonZero) {
    Rand* test = new Rand();
    EXPECT_GE(test->evaluate(), 0);
}







#endif //__OP_TEST_HPP__
