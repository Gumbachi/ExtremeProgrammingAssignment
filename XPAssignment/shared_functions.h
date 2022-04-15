#include <iostream>
// For the generation of random numbers.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

const int LOWER = 0, UPPER = 100;
// Prototypes of functions used in multiple files

// Sample names, as to not give away the 'suprise'.
void drewTextDisplay();
void jaredTextDisplay();

// Can change the type of function depending on what you think my thing should do.
bool drewSpecialFeature();
// Can change the type of function depending on what your thing does.
bool jaredSpecialFeature();

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
    // TODO
    return "";
}

string showLastDigitOptions(int num) {
    // TODO
    return "Last digit is one of these: 7, 3, 5";
}

string processDivisibilty(int num, int divisor){
    if (num % divisor == 0)
        return "The number is divisible by " + divisor;
    else
        return "The number is not divisible by " + divisor;
}

string processPrime(int num) {
    if (isPrime(num))
        return "The number is a prime number";
    else
        return "The number is not a prime number";
}

string determinePrime(int num){
    // TODO; input is the divisor
    return "The number is (prime or not)";
}

int generateNumber(){
    srand(time(0)); 
    int number;
    number = (rand() % UPPER) + 1;
    return number;
}

int getNumberInput(string prompt) {
    int guess = -1;

    while (true) {
        cout << prompt << " >> ";

        try {
            cin >> guess;
        } catch (int e) {
            continue;
        }
        break;
    }
    return guess;
}

//Is called in every instance of the main loop.
void guessingGameLoop (int count){
    int playerChoice, divisibiltyOption;
    int lower, upper;
    int newRange = -1;
    int count = 0;

    int numberToGuess = generateNumber();

    bool validChoice = false;
    if (count == 0){
        cout << "I'm thinking of a number between " << LOWER << "and" << UPPER << endl << endl;
        cout << "How would you like to narrow it down? \n\t";
    }
    else {
        cout << "Your current options:\n";
    }

    cout << "1) Guess a number. If wrong, I'll tell ya 'higher' or 'lower'!\n";
    cout << "2) Check the number's divisibilty.\n";
    cout << "3) Check if the number is prime.\n";
    cout << "4) Reveal possible last digits of the number.\n";
    cout << "Currently Known Info: \n" << "Known Range: " << LOWER << " to " << UPPER;
        
    

    if (count >= 4)
        drewTextDisplay();
    // if (count >= 4)  -->  In case you want to limit when your text shows up like I do.
        jaredTextDisplay();

    cin >> playerChoice;
    while (validChoice == false){
        validChoice = true;

        // High Low
        if (playerChoice == 1) {
            int guess = getNumberInput("Input you guess >> ");
            cout << processHighOrLowGuess(numberToGuess, guess) << endl;
        }

        // Divisibility
        else if (playerChoice == 2){
            int divisor = getNumberInput("Enter the divisor you want to check >> ");
            cout << processDivisibilty(numberToGuess, divisor) << endl;
        }

        // Prime Check
        else if (playerChoice == 3){
            cout << processPrime(numberToGuess) << endl;
        }

        // Last Digit
        else if (playerChoice == 4){
            cout << showLastDigitOptions(numberToGuess) << endl;
        }

        // Quit
        else {
            validChoice = false;
        }
            
    }
}