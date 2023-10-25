#include <iostream>
// Include the Board class header

class Player {
private:
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
        // You can call appropriate methods from the Board class
    }
};

int main() {
    // Example usage of the Player class
    Player player1("habiba");
    Player player2("Memo");

    // Example game loop
    Board board; // Assuming you have created a Board object
    bool gameInProgress = true;

    while (gameInProgress) {
        // Get player input for the move (you can use your own logic)
        int x, y;
        std::cout << "Enter the coordinates (x, y) for your move: ";
        std::cin >> x >> y;

        // Perform the move
        player1.playMove(board, x, y);

    return 0;
}
