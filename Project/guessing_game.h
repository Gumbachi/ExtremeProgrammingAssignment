#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

// Generate random number in range. Inclusive params
int generateNumber(int low, int high) {
    srand(time(NULL)); // random seed
    return rand() % (high - low + 1) + low;
}

// Check if a number is prime
bool isPrime(int num) {
    // 0 and 1 are not prime numbers
    if (num == 0 || num == 1) {
        return false;
    }

    // loop to check if n is prime
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

string processHighOrLowGuess(int num, int guess) {
    if (num < guess)
        return "Too High";
    else if (num > guess)
        return "Too Low";
    else
        return "Correct";
}

string showLastDigitOptions(int num) {
    int lastDigit = num % 10;
    int fakeOption1 = lastDigit;
    int fakeOption2 = lastDigit;

    while (fakeOption1 == lastDigit) {
        fakeOption1 = generateNumber(0, 9);
    }
        
    while (fakeOption2 == lastDigit || fakeOption2 == fakeOption1) {
        fakeOption2 = generateNumber(0, 9);
    }
       
    string returnString = "Last digit is one of these: " + to_string(fakeOption1);
    returnString += ", " + to_string(lastDigit);
    returnString += ", " + to_string(fakeOption2);

    return returnString;
}

string processDivisibilty(int num, int divisor) {
    if (num % divisor == 0)
        return "The number is divisible by " + to_string(divisor);
    else
        return "The number is not divisible by " + to_string(divisor);
}

string processPrime(int num) {
    if (isPrime(num))
        return "The number is a prime number";
    else
        return "The number is not a prime number";
}

string determinePrime(int num) {
    if (isPrime(num))
        return "The number is prime";
    else
        return "The number is not prime";
}

