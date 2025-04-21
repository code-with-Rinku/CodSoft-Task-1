#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGame(int min, int max, int attempts) {
    int guess;
    int secretNumber = rand() % (max - min + 1) + min;

    cout << "\nYou have " << attempts << " attempts to guess the number between " << min << " and " << max << ". Good luck!\n";

    for (int i = 1; i <= attempts; i++) {
        cout << "\nAttempt " << i << ": Enter your guess: ";
        cin >> guess;

        if (guess == secretNumber) {
            cout << " Well played! You guessed the number: " << guess << "\n";
            cout << "\t\tThanks for playing!\n";
            return;
        } else {
            cout << " Nope! " << guess << " is not the correct number.\n";
            if (guess > secretNumber)
                cout << "Hint: The secret number is smaller.\n";
            else
                cout << "Hint: The secret number is greater.\n";
        }
    }

    cout << " Oops! You're out of attempts. The secret number was: " << secretNumber << "\n";
    cout << "Play again if you want to try your luck!\n\n";
}

int main() {
    int min, max, choice;

    cout << "\n\t\t Welcome to the Number Guessing Game! ??\n";

    // Get range
    cout << "\nEnter the minimum value: ";
    cin >> min;
    cout << "Enter the maximum value: ";
    cin >> max;

    srand(time(0)); // Seed random generator

    while (true) {
        cout << "\nChoose Difficulty Level:\n";
        cout << "1. Easy   (10 attempts)\n";
        cout << "2. Medium (7 attempts)\n";
        cout << "3. Hard   (5 attempts)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                playGame(min, max, 10);
                break;
            case 2:
                playGame(min, max, 7);
                break;
            case 3:
                playGame(min, max, 5);
                break;
            case 4:
                cout << "Thanks for playing! Goodbye!\n";
                exit(0);
            default:
                cout << " Invalid choice! Please select a valid option.\n";
        }
    }
    return 0;
}
