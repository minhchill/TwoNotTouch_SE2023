#include <iostream>
using namespace std

// #include "manager.hpp"

// Minh: IMPLEMENTATION IDEA
// solvePuzzle(): Implement the algorithm to solve the puzzle. Parent method of starPlacing() and inaccessibleMarking()
// starPlacing(): Using all strategies to place each of the two stars
// inaccessibleMarking(): Using all strategies to determine inaccessible spots
// toSolveorVerify(): Call the isPuzzleSolved() from manager continuously. 


class Player {
private:
// Minh: since the human user of this software don't see anything happening as the puzzle is solved, we don't need these variables
    std::string name;
    int score;

public:
    Player(const std::string& playerName) : name(playerName), score(0) {
    }

//Set a Getter for player's name and score.

    std::string getName() const {
        return name;
    }

    int getScore() const {
        return score;
    }

//Keep incrementing the player's score and keep tracks of the move by the players.

    void updatedScore(int points) {
        score += points;
    }

    // Play a move in the game
    void playMove(Board& board, int x, int y) {
        // Implement the logic to play a move on the board
        // call appropriate methods from the Board class
    }
};

int main() {
    // Example usage of the Player class
    Player player1("");
    Player player2("");

    // Example game loop
    Board board; // Assuming you have created a Board object
    bool gameInProgress = true;

    while (gameInProgress) {
        // Get player input for the move
        int x, y;
        std::cout << "Enter the coordinates (x, y) for your move: ";
        std::cin >> x >> y;

        // Perform the move
        player1.playMove(board, x, y);

    return 0;
}

// void toSolveorVerify() {
    int i = 1;
//     if (i = 1) {
//         solvePuzzle();
//     }

//     else {
//         verifyPuzzle();
//     }
// }



