#include "pch.h"
#include "../Project/guessing_game.h"

using namespace std;

// Test 1: Have the user guess the number, giving them the [adjusted] range to guess off of.
// Feature 1: Implementation of the Number Guessing test(s).

TEST(HighLowTests, TestHighLowGuessResult) {
	int num = 57;

	// Guess is lower than target
	int guess = 34;
	string expected = "Too Low";
	string actual = processHighOrLowGuess(num, guess);

	EXPECT_EQ(expected, actual);

	// Guess is higher than target
	guess = 98;
	expected = "Too High";
	actual = processHighOrLowGuess(num, guess);

	EXPECT_EQ(expected, actual);

	// Guess is correct
	guess = 57;
	expected = "Correct";
	actual = processHighOrLowGuess(num, guess);

	EXPECT_EQ(expected, actual);
}

// Test 2: Divisibilty by ___.  Input is taken from user.
// Feature 2: Implementation of the Divisibilty test(s).

TEST(DivisibilityTest, TestDivisibility) {
	int num = 48;

	// Num is NOT divisible by the selected number
	int input = 7;
	string expected = "The number is not divisible by " + to_string(input);
	string actual = processDivisibilty(num, input);

	EXPECT_EQ(expected, actual);

	// Num IS divisible by the selected number
	input = 6;
	expected = "The number is divisible by " + to_string(input);
	actual = processDivisibilty(num, input);

	EXPECT_EQ(expected, actual);
}

// Jared Test
TEST(JaredTestSuite, ShowLastDigitOptions) {
	string result = showLastDigitOptions(57);

	cout << result << endl;

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

// Drew Tests
TEST(PrimeTestSuite, TestIsPrime) {
	EXPECT_TRUE(isPrime(17));
	EXPECT_TRUE(isPrime(3));
	EXPECT_TRUE(isPrime(5));
	EXPECT_TRUE(isPrime(7));

	EXPECT_FALSE(isPrime(4));
	EXPECT_FALSE(isPrime(64));
	EXPECT_FALSE(isPrime(57));
	EXPECT_FALSE(isPrime(18));
}


TEST(PrimeTestSuite, TestCheckForPrime) {
	int num = 57;
	string expected = "The number is not prime";
	string actual = determinePrime(num);
	EXPECT_EQ(expected, actual);

	num = 3;
	expected = "The number is prime";
	actual = determinePrime(num);
	EXPECT_EQ(expected, actual);

	num = 17;
	expected = "The number is prime";
	actual = determinePrime(num);
	EXPECT_EQ(expected, actual);

	num = 68;
	expected = "The number is not prime";
	actual = determinePrime(num);
	EXPECT_EQ(expected, actual);
}