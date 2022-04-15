#include "pch.h"
#include "shared_functions.h"
#include <string>

/*
Generate a random number in some predefined range.
Use the number for a variety of activities
*/

// Test 1: Have the user guess the number, giving them the [adjusted] range to guess off of.


// Feature 1: Implementation of the Number Guessing test(s).


// Test 2: Divisibilty by ___.  Input is taken from user.


// Feature 2: Implementation of the Divisibilty test(s).

using namespace std;

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



