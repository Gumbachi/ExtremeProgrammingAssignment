#include <iostream>
// For the generation of random numbers.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Types can be changed based on the judgement of the feture implementer.
int hotAndColdGuess();
int disvisibiltyCheck();

string processHighOrLowGuess(int num, int guess) {
    // TODO
    return "";
}

string showLastDigitOptions(int num) {
    // TODO
    return "Last digit is one of these: 7, 3, 5";
}

string processDivisibilty(int num, int input){
    // TODO; input is the divisor
    return "";
}

int generateNumber(){
    srand(time(0)); 
    int number;
    number = (rand() % UPPER) + 1;
    return number;
}

//Is called in every instance of the main loop.
void guessingGameLoop (int count){
    int playerChoice, divisibiltyOption;
    int lower, upper;
    int newRange = -1;
    bool validChoice = false;
    if (count == 0){
        cout << "I'm thinking of a number between " << LOWER << "and" << UPPER << endl << endl;
        cout << "How would you like to narrow it down? \n\t";
        lower = LOWER; upper = UPPER;
    }
    else
        cout << "Your current options:\n";
    cout << "1) Guess a number. If wrong, I'll tell ya 'hot' or 'cold'!\n" << "2) Check the number's divisibilty.\n";
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