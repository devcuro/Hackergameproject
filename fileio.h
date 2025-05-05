#ifndef FILEIO_H  // If FILEIO_H is not defined
#define FILEIO_H  // Define FILEIO_H

#include "player.h"  // Include player header to use Player struct

// Function declarations
void loadPlayerData(Player& player);  // Load player data from a file
void savePlayerData(const Player& player);  // Save player data to a file
void viewLogs();  // View the game logs

#endif  // End of header guard for FILEIO_H
