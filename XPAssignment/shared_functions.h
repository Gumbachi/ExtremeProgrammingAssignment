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

// Types can be changed based on the judgement of the feture implementer.
bool disvisibiltyCheck(int num, int divisor) {
    return num % divisor == 0;
}

string processHighOrLowGuess(int num, int guess) {
    // TODO
    return "";
}

string showLastDigitOptions(int num) {
    // TODO
    return "Last digit is one of these: 7, 3, 5";
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
        if (playerChoice == 1){
            newRange = hotAndColdGuess(); // Just a placeholder name for your test that I'll implement.
        }
        else if (playerChoice == 2){
            disvisibiltyCheck();
        }
        else if (playerChoice == 3){
            drewSpecialFeature();
        }
        else if (playerChoice == 4){
            jaredSpecialFeature();
        }
        else
            validChoice = false;
    }
}