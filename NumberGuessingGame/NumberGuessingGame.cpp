#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#define NOMINMAX 
#include<windows.h>
#include<limits>

using namespace std;

class NumberGuessingGame {
public:
    void play(int maxNumber, int maxAttempts) {
        int randomNumber = rand() % maxNumber + 1;
        string guess;
        int attempts = 0;
        cout << "Guess the number between 1 and " << maxNumber << "!" << endl;

        while (attempts < maxAttempts) {
            cout << "Attempt " << attempts + 1 << " of " << maxAttempts << ": ";
            getline(cin, guess);

            try {
                int guessNum = stoi(guess); 
                attempts++;

                if (guessNum == randomNumber) {
                    cout << "Congratulations! You guessed the number!" << endl;
                    return;
                }
                else if (guessNum > randomNumber)
                    cout << "Too high!" << endl;
                else
                    cout << "Too low!" << endl;
            }
            catch (const invalid_argument&) {
                cout << "Invalid input. Please enter a number." << endl;
                countdownAndClear();
            }
            catch (const out_of_range&) {
                cout << "Input is out of range. Please enter a smaller number." << endl;
                countdownAndClear();
            }
        }
        cout << "Sorry, you've used all your attempts. The number was " << randomNumber << "." << endl;
    }

    bool selectLevel() {
        string choice;
        cout << "Select a difficulty level:\n";
        cout << "1. Easy (Range: 1-10, Max Attempts: 5)\n";
        cout << "2. Medium (Range: 1-50, Max Attempts: 7)\n";
        cout << "3. Hard (Range: 1-100, Max Attempts: 10)\n";
        cout << "4. To exit the game\n";
        cout << "Enter your choice: ";
        getline(cin, choice);

        if (choice == "1")
            play(10, 5);
        else if (choice == "2")
            play(50, 7);
        else if (choice == "3")
            play(100, 10);
        else if (choice == "4") {
            cout << "Exiting\n";
            return false;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            Sleep(800);
            system("cls");
        }
        return true;
    }

    bool askToPlayAgain() {
        char playAgain;
        while (true) {
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  

            if (playAgain == 'y' || playAgain == 'Y')
                return true;
            else if (playAgain == 'n' || playAgain == 'N') {
                cout << "Thank you for playing!" << endl;
                return false;
            }
            else {
                cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
                countdownAndClear();
            }
        }
    }

private:
    void countdownAndClear() {
        for (int i = 3; i > 0; --i) {
            cout << "Input again in " << i << "..." << endl;
            Sleep(1000);
        }
        system("cls");
    }
};
int main() {
    srand((time(0)));
    NumberGuessingGame game;
    cout << "Welcome to the Number Guessing Game!" << endl;
    do {
        if (!game.selectLevel()) 
            break;
    } while (game.askToPlayAgain());
}
