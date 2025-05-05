# HackerSim Game

## Description

**HackerSim** is a text-based simulation game where players take on the role of a hacker, completing missions by choosing from different hacking methods. Players must navigate through multiple levels, earning points for successful attacks and losing lives for failed ones. The game includes a logging system for actions and offers a save/load feature for continued gameplay.

## Features

- **Multiple Hacking Methods**:
  - **Brute Force**: High risk, low chance of success.
  - **Social Engineering**: Safer but more challenging.
  - **Phishing Attack**: Balanced between risk and reward.
  
- **Difficulty Levels**: Three increasing difficulty levels.
- **Scoring**: Earn points for successful attacks and lose lives for failed ones.
- **Logging**: All actions are logged in a `log.txt` file.
- **Save/Load**: Save your progress and load it later.

## Getting Started in GitHub CodeSpaces

### Prerequisites

Make sure you have GitHub CodeSpaces setup and configured. This project uses the standard C++ libraries, so there are no additional dependencies required beyond CodeSpaces' default setup.

### Steps to Run the Game in CodeSpaces

1. **Open the repository in GitHub CodeSpaces:**
   - Click on the "Code" button in your GitHub repository.
   - Select "Open with CodeSpaces" and wait for the environment to set up.

2. **Compile the project:**
   In the terminal inside CodeSpaces, run the following command to compile the project:

   ```bash
   g++ -o HackerSim main.cpp game.cpp fileio.cpp -std=c++11

3. **Run the project:**
   In the terminal inside CodeSpaces, run the following command to run the project:

      ```bash
   ./Hackersim
