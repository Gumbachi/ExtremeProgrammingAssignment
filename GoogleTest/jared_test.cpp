#include "pch.h"
#include <string>
#include "../Project/guessing_game.h"

TEST(JaredTestSuite, ShowLastDigitOptions) {
	string result = showLastDigitOptions(57);
	auto unexpected = string::npos;
	auto actual = result.find('7');
	EXPECT_NE(unexpected, actual);

	result = showLastDigitOptions(13);
	unexpected = string::npos;
	actual = result.find('3');
	EXPECT_NE(unexpected, actual);

	result = showLastDigitOptions(90);
	unexpected = string::npos;
	actual = result.find('0');
	EXPECT_NE(unexpected, actual);
}