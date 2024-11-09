# CodeAlpha_NumberGuessingGame.


Welcome to the **Number Guessing Game**! This is a simple console-based game where the player has to guess a randomly generated number within a given range. The game provides feedback on whether the guessed number is too high or too low, and it allows the player to try multiple times based on the selected difficulty level.

## Features
- **Difficulty Levels**: Choose from three difficulty levels:
  - **Easy**: Number range from 1 to 10, 5 attempts.
  - **Medium**: Number range from 1 to 50, 7 attempts.
  - **Hard**: Number range from 1 to 100, 10 attempts.
- **Input Validation**: The game handles invalid inputs, such as non-numeric characters, and provides feedback accordingly.
- **Replay Option**: After completing a game, the player is prompted to play again.
- **Countdown Timer**: After each invalid input, a countdown (3.. 2.. 1) is displayed before the screen is cleared and the user is asked to input again.

## How to Run the Game

### Prerequisites:
- C++ Compiler (e.g., GCC or MSVC).
- Windows environment (due to the use of `<windows.h>` for `Sleep()` and `system("cls")`).

### Steps to Run:
1. Clone the repository:
   ```bash
   git clone https://github.com/Umaimtahir/number-CodeAlpha_NumberGuessingGame.git
2.Navigate to the project directory:
cd number-guessing-game

3.Compile the C++ code:
g++ -o number_guessing_game main.cpp

4.Run the compiled program:
./number_guessing_game


