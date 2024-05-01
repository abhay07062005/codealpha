#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Generate a random secret number between 1 and 100
    srand(time(0));
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a secret number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    // Ask the user to select the level of difficulty
    cout << "Choose the level of difficulty:" << endl;
    cout << "1. Easy (10 chances)" << endl;
    cout << "2. Medium (7 chances)" << endl;
    cout << "3. Hard (5 chances)" << endl;
    int level;
    cin >> level;

    switch (level) {
        case 1:
            attempts = 10;
            break;
        case 2:
            attempts = 7;
            break;
        case 3:
            attempts = 5;
            break;
        default:
            cout << "Invalid choice. Exiting the game." << endl;
            return 0;
    }

    // Main game loop
    while (attempts > 0) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the correct number: " << secretNumber << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }

        attempts--;
    }

    if (attempts == 0) {
        cout << "Out of chances! The secret number was: " << secretNumber << endl;
    }

    return 0;
}
