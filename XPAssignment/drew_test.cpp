#include "pch.h"
#include <string>
#include "shared_functions.h"

TEST(DrewTestSuite, TestCheckForPrime) {
	int num = 210;  // Purposefully out-of-scope of the range.

	string expected = "Two is not a factor";
	string actual = determinePrime(num);

	EXPECT_EQ(expected, actual);

	string expected = "Three is not a factor";
	string actual = determinePrime(num);

	EXPECT_EQ(expected, actual);

	string expected = "Five is not a factor";
	string actual = determinePrime(num);

	EXPECT_EQ(expected, actual);

	string expected = "Seven is not a factor";
	string actual = determinePrime(num);

	EXPECT_EQ(expected, actual);
}