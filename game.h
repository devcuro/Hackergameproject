#ifndef GAME_H  // If GAME_H is not defined
#define GAME_H  // Define GAME_H

#include "player.h"  // Include player header to use Player struct

// Function declarations
void showMenu();  // Function to display the main menu
void playGame(Player& player);  // Function to start and play the game, takes Player by reference
int attackSimulation(int level, int method);  // Function to simulate an attack with difficulty based on level and selected method
int attackSimulation();  // Overloaded function that simulates a default attack with level 1

#endif  // End of header guard for GAME_H
