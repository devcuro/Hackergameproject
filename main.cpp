//******************************************************************** */
//Author.....: Andrew Hathaway
//Assignment.: Hacker Game Project
//Description: This program emulates a simple hacking game where the player
//             can choose different hacking methods to attack a target. The game includes
//             a scoring system, lives, and the ability to save and load player data.
//******************************************************************** */

#include <iostream>
#include <limits>  // Used for numeric limits (needed for clearing input buffer)
#include "game.h"
#include "fileio.h"

using namespace std;

// Function to get validated user input within a specific range (min, max)
int getValidInput(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;  // Get user input for choice
        if (cin.fail()) {
            cin.clear();  // Clear input error flag if user enters non-numeric value
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid characters from the input buffer
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else if (choice < min || choice > max) {
            // If input is outside the valid range, prompt the user again
            cout << "Invalid choice. Please enter a number between " << min << " and " << max << ": ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear any extra characters in input buffer after valid input
            return choice;  // Return valid choice
        }
    }
}

int main() {
    Player player;  // Declare player object
    int choice;
    
    // Loop for menu options
    do {
        showMenu();  // Display the game menu
        cout << "Enter choice: ";
        choice = getValidInput(1, 4);  // Get valid user input between 1 and 4

        switch (choice) {
            case 1:
                // Start a new game
                cout << "Enter your hacker alias: ";
                getline(cin, player.name);  // Get player alias from user input
                player.score = 0;  // Initialize score
                player.lives = 3;  // Initialize lives
                playGame(player);  // Start the game
                break;
            case 2:
                // Load saved game
                loadPlayerData(player);  // Load saved player data
                playGame(player);  // Start the game with loaded data
                break;
            case 3:
                // View logs
                viewLogs();  // Display the logs
                break;
            case 4:
                // Exit game
                cout << "Exiting game. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";  // This will never happen due to validation
        }
    } while (choice != 4);  // Continue until the user selects option 4 (Exit)

    return 0;  // Exit the program
}
