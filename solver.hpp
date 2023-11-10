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

struct Shape {
    
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
    bool has2LowerCaseRow(const std::vector<std::string>& puzzle) {
    for (const std::string& row : puzzle) {
        int lowercaseCount = 0; // Initialize the count of lowercase letters to 0

            // Iterate through each character in the row
            for (char c : row) {
                if (std::islower(c)) {
                    lowercaseCount++;
                    if (lowercaseCount == 2) {
                        break; // No need to continue checking if we already found 2 lowercase letters
                    }
                }
            }

            // Check if the row contains exactly 2 lowercase letters
            if (lowercaseCount != 2) {
                return false; // If not, return false
            }
        }

        // If all rows contain exactly 2 lowercase letters, return true
        return true;
    }

    // Check if 2 lower case letters (for 2 stars) are presented in a column
    bool has2LowerCaseColumn(const std::vector<std::string>& puzzle) {
        int rowCount = puzzle.size();
        int colCount = puzzle[0].size(); // Assuming all rows have the same length

        for (int col = 0; col < colCount; col++) {
            int lowercaseCount = 0; // Initialize the count for lowercase letters in the current column

            for (int row = 0; row < rowCount; row++) {  
                char c = puzzle[row][col]; // Get the character in the current column and row

                if (std::islower(c)) {
                    lowercaseCount++;
                    if (lowercaseCount == 2) {
                        break; // No need to continue checking if we already found 2 lowercase letters
                    }
                }
            }

        if (lowercaseCount != 2) {
            return false; // If the column doesn't contain exactly 2 lowercase letters, return false
        }
    }
    return true; // If all columns contain exactly 2 lowercase letters, return true
    }



    // Need more work on this one
    // Function to verify the solution from a file

    bool verifySolutionFromFile(const std::string& filename) {
        return true;
    }
};