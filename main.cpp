
#include <iostream>   // Provides standard input/output stream objects: std::cout, std::cin
#include <cstdlib>    // Provides C standard library functions: rand(), srand()
#include <ctime>      // Provides time-related functions: time()

using namespace std;

int game(int maxnum){
    // Generate a random number in the range [1..20].
    // rand() % 20 gives a number in [0..19]; adding 1 shifts it to [1..20].
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



