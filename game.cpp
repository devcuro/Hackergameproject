#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>  // Added for file writing
#include "game.h"
#include "fileio.h"  // Included to handle file I/O for saving player data

using namespace std;

// Function to simulate an attack with difficulty based on level and selected method
int attackSimulation(int level, int method) {
    int baseChance = 7 - level; // base gets harder each level

    // Modify chance based on method
    switch (method) {
        case 1: baseChance -= 1; break; // Brute Force = more risky
        case 2: baseChance += 1; break; // Social Engineering = safer
        case 3: /* no change */ break; // Phishing = balanced
    }

    int chance = rand() % 10;
    return (chance < baseChance);
}


void logAction(const string& action) {
    ofstream logFile("log.txt", ios::app);  // Open log file in append mode
    if (logFile.is_open()) {
        logFile << action << endl;  // Write the action to the log file
        logFile.close();            // Close the file after writing
    } else {
        cout << "Error opening log file.\n";  // If there is an error opening the file
    }
}

void showMenu() {
    cout << "\n--- HackerSim Console ---\n";
    cout << "1. Start New Game\n";
    cout << "2. Load Game\n";
    cout << "3. View Logs\n";
    cout << "4. Exit\n";
}

void playGame(Player& player) {
    srand(time(0));  // Seed random number generator with current time to ensure randomness in attack outcomes
    cout << "\nWelcome, " << player.name << ". Your mission begins...\n";

    // Loop through levels with a check for lives
    for (int level = 1; level <= 3 && player.lives > 0; ++level) {
        int method;
        cout << "\nLevel " << level << ": Choose your hacking method:\n";
        cout << "1. Brute Force\n";
        cout << "2. Social Engineering\n";
        cout << "3. Phishing Attack\n";
        cout << "Enter choice (1-3): ";
        cin >> method;

        while (method < 1 || method > 3) {  // Validate method choice
            cout << "Invalid method. Choose again (1-3): ";
            cin >> method;
        }

        // Call the attackSimulation function with both level and method as arguments
        int result = attackSimulation(level, method);  // Simulate the attack for the current level and method

        if (result) {
            cout << "Success! +10 points.\n";
            player.score += 10;
            logAction("Level " + to_string(level) + ": Success! +10 points.");
        } else {
            cout << "Attack failed. -1 life.\n";
            player.lives--;
            logAction("Level " + to_string(level) + ": Attack failed. -1 life.");
        }
    }

    cout << "Game Over. Final Score: " << player.score << ", Lives: " << player.lives << "\n";
    logAction("Game Over. Final Score: " + to_string(player.score) + ", Lives: " + to_string(player.lives));

    // Save player data after game ends
    savePlayerData(player);  // Save the player's progress to a file (added functionality to save progress)
}

