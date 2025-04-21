#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int min, max, guess;

    cout << "\n\t\t\tWelcome to the Number Guessing Game\n";

    // Ask for the range of the secret number
    cout << "\nEnter the minimum value: ";
    cin >> min;
    cout << "Enter the maximum value: ";
    cin >> max;

    // Seed the random number generator
    srand(time(0));

    // Generate the secret number
    int secretnumber = rand() % (max - min + 1) + min;

    while (true) {
        cout << "\nEnter the difficulty level:\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Exit\n";
        cout << "You have limited chances based on the level you choose. Good luck!\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        int attempt = 0;
        if (choice == 1) attempt = 10;
        else if (choice == 2) attempt = 7;
        else if (choice == 3) attempt = 5;
        else if (choice == 4) exit(0);
        else {
            cout << "Wrong choice, enter a valid choice to play the game.\n";
            continue;
        }

        cout << "You have " << attempt << " chances to find the secret number.\n";

        for (int i = 0; i < attempt; i++) {
            cout << "\nEnter your guess: ";
            cin >> guess;

            if (guess == secretnumber) {
                cout << "Well played! You won with the number " << guess << "!\n";
                cout << "\t\t\tThanks for playing!\n";
                cout << "Play the game again with us if you want.\n";
                break;
            } else {
                cout << "No, " << guess << " is not the right number.\n";

                if (guess > secretnumber) {
                    cout << "The secret number is smaller than the number you chose.\n";
                } else {
                    cout << "The secret number is greater than the number you chose.\n";
                }

                int attemptsLeft = attempt - i - 1;
                cout << attemptsLeft << " attempt(s) remaining.\n";

                if (attemptsLeft == 0) {
                    cout << "Oops! You couldn't find the right number. It was " << secretnumber << ".\n";
                    cout << "Play the game again if you want!\n\n";
                }
            }
        }
    }

    return 0;
}
