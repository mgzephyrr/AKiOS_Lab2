#include "pch.h"
#include "..//AKiOS_Lab2/includes.h"

TEST(TestCaseName, TestTest) {
	LIFOElem* tail = nullptr;
	tail = AddToLIFO(tail, 1);
	tail = AddToLIFO(tail, 2);
	tail = AddToLIFO(tail, 3);
	tail = AddToLIFO(tail, 4);
	tail = AddToLIFO(tail, 5);

	EXPECT_EQ(tail->value, 5);
}

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}