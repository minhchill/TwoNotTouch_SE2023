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
