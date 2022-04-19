#include "pch.h"
#include <string>
#include "../Project/guessing_game.h"

TEST(DrewTestSuite, TestCheckForPrime) {
	int num = 210;  // Purposefully out-of-scope of the range.

	string expected = "Two is not a factor";
	string actual = determinePrime(num);

	EXPECT_EQ(expected, actual);

	expected = "Three is not a factor";
	actual = determinePrime(num);

	EXPECT_EQ(expected, actual);

	expected = "Five is not a factor";
	actual = determinePrime(num);

	EXPECT_EQ(expected, actual);

	expected = "Seven is not a factor";
	actual = determinePrime(num);

	EXPECT_EQ(expected, actual);
}