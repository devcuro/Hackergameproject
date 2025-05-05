#ifndef PLAYER_H  // If PLAYER_H is not defined
#define PLAYER_H  // Define PLAYER_H

#include <string>  // Include string library for handling player names

// Define a Player struct to store player data
struct Player {
    std::string name;  // Player's alias or name
    int score;         // Player's score
    int lives;         // Player's remaining lives
};

#endif  // End of header guard for PLAYER_H
