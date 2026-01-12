/*
 * File: number_guessing_game.cpp
 * Author: Kajetan Zelech-Alatarvas
 * Created: 2026-01-12
 * Version: 1.0
 *
 * Description:
 *   A simple console-based number guessing game. The program selects
 *   a random number in the range [1..maxnum]. The player attempts to
 *   guess the number, receiving feedback whether the guess is too high
 *   or too low, until the correct number is found. The total number of
 *   attempts is displayed at the end.
 *
 * Usage:
 *   Compile: g++ -std=c++17 -O2 -Wall -Wextra -o guess_game number_guessing_game.cpp
 *   Run:     ./guess_game
 *
 * Notes:
 *   - The random number generator is seeded with the current time.
 *   - Adjust the max range by changing the argument to game(maxnum) in main().
 *   - Input is read from standard input (std::cin).
 */



#include <iostream>   // Provides standard input/output stream objects: std::cout, std::cin
#include <cstdlib>    // Provides C standard library functions: rand(), srand()
#include <ctime>      // Provides time-related functions: time()

using namespace std;

int game(int maxnum){
    int RandomNumber = (rand() % maxnum) + 1;  // 1–maxnum

    // Print the introductory banner and instructions for the player.
    cout << "=======================================================" << endl;
    cout << "I have selected a number, please try to guess it (1-";
    cout << maxnum;
    cout << ")" << endl;
    cout << "=======================================================" << endl;

    int GuessedNumber;
    int Attempts = 0;

    // Use a do-while loop so the guessing prompt is shown at least once.
    // The loop continues until the user guesses the correct number.
    do {
        cout << "Please guess my number:" << endl;

        cin >> GuessedNumber;

        Attempts++; // count each iteration

        // Echo the user's input and provide feedback relative to the target number.
        cout << "You have provided: " << GuessedNumber << ", your number is: ";

        // Compare the guess against the random number and give hints.
        if (GuessedNumber > RandomNumber) {
            cout << "too HIGH (luku on pienempi)!" << endl;
        }
        else if (GuessedNumber < RandomNumber) {
            cout << "too LOW! (luku on suurempi)" << endl;
        }
        else { // GuessedNumber == RandomNumber
            cout << "CORRECT! (oikea vastaus)" << endl;
        }

    } while (GuessedNumber != RandomNumber); // Loop until the correct guess


    return Attempts;

 }

    int main()
    {
        // Seed the pseudo-random number generator with the current time.
        // This ensures a different sequence of numbers on each program run.
        // time(nullptr) returns the current time as seconds since epoch.
        // We cast to unsigned to match srand()'s expected parameter type.
        srand(static_cast<unsigned>(time(nullptr)));

        int attempts = game(40);

        cout << "*****************" << endl;
        cout << "You succeeded in: " << attempts << " attempts. Congratulations!" << endl;
        cout << "*****************" << endl;

        return 0;
    }



