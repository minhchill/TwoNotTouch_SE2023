#include <iostream>
#include <vector>
#include <map>


// Minh: IMPLEMENTATION IDEA
// solvePuzzle(): Implement the algorithm to solve the puzzle. Parent method of starPlacing() and inaccessibleMarking()
// starPlacing(): Using all strategies to place each of the two stars
// inaccessibleMarking(): Using all strategies to determine inaccessible spots
// toSolveorVerify(): Call the isPuzzleSolved() from manager continuously. 


class Cell {
public:
    int x;
    int y;
    int container;
    bool accessible;
    bool hasStar;

    Cell(int x, int y, int container)
        : x(x), y(y), container(container), accessible(true), hasStar(false) {}
};

class Container {
public:
    Shape shape;
    std::vector<Cell> cells;
    int starCount;

    Container(Shape shape)
        : shape(shape), starCount(0) {}
};


class Player {
private:
    std::vector<Container> containers;
    std::vector<std::vector<Cell>> grid;
    std::map<int, int> containerCounts;

public:
    Player() {
        // Initialize grid and containers here
        grid.resize(10, std::vector<Cell>(10, Cell(-1, -1, -1)));
        containers.clear();
    }


// Function to verify the condition of having 2 stars in both a a row and a column
    bool verifyTwoStarsInRowAndColumn() {
        for (int x = 0; x < 10; x++) {
            int starsInRow = 0;
            int starsInColumn = 0;
            for (int y = 0; y < 10; y++) {
                if (grid[x][y].hasStar) {
                    starsInRow++;
                }
                if (grid[y][x].hasStar) {
                    starsInColumn++;
                }
            }
            if (starsInRow == 2 && starsInColumn == 2) {
                return true;
            }
        }
        return false;
    }

