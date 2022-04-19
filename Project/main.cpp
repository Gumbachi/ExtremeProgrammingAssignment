#include <iostream>
#include "guessing_game.h"
#include <Windows.h>

using namespace std;

int secretNumber = generateNumber(1, 100);
string guess;
int wrongGuessCount = 0;
bool showPrimaryHints = false;
bool showAllHints = false;

int getInput(string prompt = "Guess A Number >> ", bool includeHints = true) {
    cout << endl << prompt;
    cin >> guess;

    if (includeHints) {
        // hint guessed
        if (guess == "h1") {
            return -1;
        }
        else if (guess == "h2") {
            return -2;
        }
        else if (guess == "h3") {
            return -3;
        }
        else if (guess == "h4") {
            return -4;
        }
    }
    
    
    // number guessed
    int numberGuess;
    while (true) {
        try {
            numberGuess = stoi(guess);
            if (numberGuess > 100 || numberGuess < 1) {
                throw 20;
            }
            return numberGuess;
        }
        catch (...) {
            cout << "Try Again >> ";
            cin >> guess;
        }
    }
}


int main() {

    int finalGuess;
    cout << "For Testing Purposes:" << secretNumber << endl;

    while (true) {

        if (showPrimaryHints) {
            cout << "\nh1: High/Low\n";
            cout << "h2: Check Divisibility\n";            
        }
        if (showAllHints) {
            cout << "h3: Check Prime\n";
            cout << "h4: Reveal Second Digit\n";
        }

        
        finalGuess = getInput();

        // Hint Handler
        if (finalGuess == -1) {
            finalGuess = getInput("Guess A Number >> ", false); // get High/Low Guess
            cout << processHighOrLowGuess(secretNumber, finalGuess) << endl;
            continue;
        }
        else if (finalGuess == -2) {
            finalGuess = getInput("Divisor >> ", false); // get Divisor
            cout << processDivisibilty(secretNumber, finalGuess) << endl;
            continue;
        }
        else if (finalGuess == -3) {
            cout << processPrime(secretNumber) << endl;
            continue;
        }
        else if (finalGuess == -4) {
            cout << showLastDigitOptions(secretNumber) << endl;
            continue;
        }
        

        // Guess Handler
        if (wrongGuessCount == 0) {
            if (finalGuess == secretNumber) {
                cout << "That was correct" << endl;
                Sleep(1000);
                cout << "You haven't won though" << endl;
                Sleep(1000);
                cout << "I knew you would cheat so I switched the number right before you guessed" << endl;
                Sleep(1000);
                cout << "so you're actually wrong." << endl << endl;
                secretNumber = generateNumber(1, 100);
            }
            else {
                cout << "Embarassing..." << endl;
                wrongGuessCount++;
            }
        } 
        else if (wrongGuessCount == 1) {
            if (finalGuess == secretNumber) {
                cout << "That was correct but it took you surprisingly long" << endl;
                break;
            }
            else {
                cout << "Have you tried thinking about it harder?" << endl;
                Sleep(2000);
                cout << "Clearly not." << endl;
                Sleep(1000);
                cout << "Here are some hints you can use to make me think less of you." << endl << endl;
                wrongGuessCount++;
                showPrimaryHints = true;
            }
        }
        else if (wrongGuessCount == 2 || wrongGuessCount == 3) {
            if (finalGuess == secretNumber) {
                cout << "Finally." << endl;
                Sleep(1000);
                cout << "Good thing you had those hints, I didn't think you would ever win" << endl;
                break;
            }
            else {
                wrongGuessCount++;
            }
        }
        else if (wrongGuessCount == 4) {
            if (finalGuess == secretNumber) {
                cout << "Finally." << endl;
                Sleep(1000);
                cout << "Good thing you had those hints, I didn't think you would ever win" << endl;
                break;
            }
            else {
                cout << "Big fan of crayons?" << endl;
                Sleep(2000);
                cout << "I figured as much" << endl;
                Sleep(1000);
                cout << "Have some extra hints for your troubles." << endl << endl;
                wrongGuessCount++;
                showAllHints = true;
            }
        }
        else if (wrongGuessCount == 5 || wrongGuessCount == 6) {
            if (finalGuess == secretNumber) {
                cout << "Its about time, I was about to lose more hope in you" << endl;
                Sleep(1000);
                cout << "If that is even possible" << endl;
                break;
            }
            else {
                wrongGuessCount++;
            }
        }
        else if (wrongGuessCount == 7) {
            if (finalGuess == secretNumber) {
                cout << "Its about time, I was about to lose more hope in you" << endl;
                Sleep(1000);
                cout << "If that is even possible" << endl;
                break;
            }
            else {
                cout << "Alirght you're clearly lost, I give up" << endl;
                Sleep(1000);
                cout << "You're on your own from now on" << endl;
                wrongGuessCount++;
            }
        }
        else {
            if (finalGuess == secretNumber) {
                cout << "ZZZ..." << endl;
                Sleep(1000);
                cout << "zzz..." << endl;
                Sleep(1000);
                cout << "ZZZ..." << endl;
                Sleep(1000);
                cout << "zzz..." << endl;
                Sleep(1000);
                cout << "Oh looks like you finally got it" << endl;
                Sleep(1000);
                cout << "Only took like " << wrongGuessCount <<" billion attempts" << endl;
                Sleep(6000);
                cout << "You can leave now, im trying to sleep" << endl;
                break;
            }
            else {
                wrongGuessCount++;
            }
        }
    }

	return 0;
}