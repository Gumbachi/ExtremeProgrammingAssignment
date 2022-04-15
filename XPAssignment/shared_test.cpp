#include "pch.h"
#include "shared_functions.h"
#include <string>

/*
Generate a random number in some predefined range.
Use the number for a variety of activities
*/

using namespace std;

// Test 1: Have the user guess the number, giving them the [adjusted] range to guess off of.
// Feature 1: Implementation of the Number Guessing test(s).

TEST(HighLowTests, TestHighLowGuessResult) {
	int num = 57;

	// Guess is lower than target
	int guess = 34;
	string expected = "Too Low.";
	string actual = processHighOrLowGuess(num, guess);

	EXPECT_EQ(expected, actual);

	// Guess is higher than target
	int guess = 98;
	string expected = "Too High.";
	string actual = processHighOrLowGuess(num, guess);

	EXPECT_EQ(expected, actual);

	// Guess is correct
	int guess = 57;
	string expected = "You Guessed The Number!";
	string actual = processHighOrLowGuess(num, guess);

	EXPECT_EQ(expected, actual);
}

// Test 2: Divisibilty by ___.  Input is taken from user.
// Feature 2: Implementation of the Divisibilty test(s).

TEST(DivisibilityTest, TestDivisibility){
	int num = 48;

	// Num is NOT divisible by the selected number
	int input = 7;
	string expected = "The number is not divisible by " + input;
	string actual = processDivisibilty(num, input);

	EXPECT_EQ(expected, actual);

	// Num IS divisible by the selected number
	int input = 6;
	string expected = "The number is divisible by " + input;
	string actual = processDivisibilty(num, input);

	EXPECT_EQ(expected, actual);
}