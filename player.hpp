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

