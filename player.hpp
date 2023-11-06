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
        for (int x = 0; x < 10; x++) {  // used to loop through rows of a 2D grid.
            int starsInRow = 0;
            int starsInColumn = 0;   // will be used to count the number of stars in the current column And row
            for (int y = 0; y < 10; y++) {     //loop through the columns of the grid within the current row.
                if (grid[x][y].hasStar) {      // checks if current row&Cololum has a star
                    starsInRow++;              // if true, increase number of star by 1.
                }
                if (grid[y][x].hasStar) { 
                    starsInColumn++;
                }
            }
            if (starsInRow == 2 && starsInColumn == 2) { // check there are exactly 2 stars in both the current row and column
                return true;                            // returns true if condition met or false otherwise
            }
        }
        return false;
    }


// Need more work on this one
    // Function to verify the solution from a file
    bool verifySolutionFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open the file: " << filename << std::endl;
            return false;
        }

