#include <iostream>
#include <fstream>  // To handle file operations
#include "fileio.h"

using namespace std;

// Function to load player data from a file
void loadPlayerData(Player& player) {
    ifstream inFile("save.txt");  // Open the save file for reading
    if (inFile.is_open()) {
        getline(inFile, player.name);  // Read player's name
        inFile >> player.score >> player.lives;  // Read score and lives
        inFile.close();  // Close the file
        cout << "Loaded player data.\n";  // Notify the user
    } else {
        cout << "No save file found.\n";  // If file doesn't exist, notify the user
    }
}

// Function to save player data to a file
void savePlayerData(const Player& player) {
    ofstream outFile("save.txt");  // Open the save file for writing
    outFile << player.name << "\n" << player.score << " " << player.lives << endl;  // Write player data to file
    outFile.close();  // Close the file
    cout << "Game saved.\n";  // Notify the user that the game was saved
}

// Function to view logs from a log file
void viewLogs() {
    ifstream logFile("log.txt");  // Open the log file for reading
    string line;
    cout << "\n--- Logs ---\n";
    while (getline(logFile, line)) {  // Read each line from the log file
        cout << line << endl;  // Print the log to the console
    }
    logFile.close();  // Close the file
}
