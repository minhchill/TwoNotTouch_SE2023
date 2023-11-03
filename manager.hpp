#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

/* Methods to have:
loadGrid(filename): Read the input text file, which contains the initial puzzle grid, and populate the game grid based on file content.
isGrid10x10(): check if grid is 10 x 10
isGridCharLegal(): return error if the grid has different than 10 unique lowercase letters.
isLegalRegion(): check for regions with a hanging letter and return error in that case
isLegalGrid(): check if a given puzzle is solvable; parent of isGrid10x10(), isGridCharLegal(), isLegalRegion()

isLegalPlacement(x, y, isStar): Given the coordinates (x, y) and whether you want to place a star or a cross, this method should check if the placement follows the game rules (maximum 2 stars in each row, column, and bounded region).
isPuzzleSolved(): Check if the puzzle is solved, meaning all the rules are met and the puzzle is complete.
*/

//placeholder until using class Cell
struct placeholderCell {
    int x;
    int y;
};

// bring the isGridCharLegal up here for vectorization and mapping
void loadGrid(const std::string& filename) {    
    std::cout << "works" << std::endl;
}

// we can pass reference to the array or map contained the populated game grid for input parameter
bool isGrid10x10(const std::string& filename) {
    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return false;
    }

    std::vector<std::string> grid;
    std::string line;

    // Read the grid from the input file
    while (std::getline(input, line)) {
        grid.push_back(line);
    }

    // Check if the grid has 10 rows
    if (grid.size() != 10) {
        std::cerr << "Error: Grid does not have 10 rows. Submit another file" << std::endl;
        return false;
    }

    // Check if each row has 10 columns
    //i hate length()
    int acc = 1;
    for (const std::string& row : grid) {

        //check the last row first because this solution is dumb
        std::string& lastRow = grid[9];
        if (lastRow.length() == 11) {
            std::cerr << "Error: Grid does not have 10 columns in some rows. Submit another file" << std::endl;
            return false;
        }
        
        //for debug
        //cout << row.length() << endl;

        //since last row is the correct size we can check the other rows
        if  (row.length() != 11) {
            if (acc != grid.size()) {
                std::cerr << "Error: Grid does not have 10 columns in some rows. Submit another file" << std::endl;
                return false;
            }
            else {
                if (acc == grid.size() && lastRow.length() != 10) {
                    std::cerr << "Error: Grid does not have 10 columns in some rows. Submit another file" << std::endl;
                    return false;
                }
            }
        }
        acc++;
    }

    // If the grid is 10x10, it's valid
    return true;
}

// Some rename needed, maybe loadGrid is more appropriate which is up there
bool isGridcharlegal(const std::vector<std::string>& grid) {
    std::map<char, int> map;
    for (const std::string& row : grid) {

        for (const char& i : row) {
            if (i != '\n') {
                map[i]++;
            }
        }
    }
    // Get an iterator pointing to the first element in the map
    std::map<char, int>::iterator it = map.begin();
 
    // Iterate through the map and print the elements
    while (it != map.end()) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
    return true;
}

void isLegalRegion() {
    std::cout << "Hey there" << std::endl;
}

void isLegalGrid() {
    std::cout << "Yo Legit" << std::endl;
}

void isLegalPlacement(int x, int y, bool isStar) {

}

void isPuzzleSolved() {
    
}

//to place stars
char change_case(char c) {
    if (std::isupper(c)) 
        return std::tolower(c); 
    else
        return std::toupper(c); 
}

void placeStar(int x, int y, std::vector<std::string>& grid) {
    //std::cout << grid[x][y] << std::endl;
    grid[x][y] = change_case(grid[x][y]);
}

//overload operator to output vector
std::ostream& operator<<(std::ostream& os, const placeholderCell& cell) {
    os << "x coordinate: " << cell.x << std::endl << "y coordinate: " << cell.y << std::endl;
    return os;
}

template<typename T>
void show(const T& container) {
    for(const auto& item : container) {
        std::cout<<item<<std::endl;
    }
}

/*
//use this to get shapes of given text input
std::vector<std::vector<placeholderCell>> getShapes(std::vector<std::string>& grid) {
    //create vector(s)
    std::vector<std::vector<placeholderCell>> shapes;

    std::vector<placeholderCell> A;
    std::vector<placeholderCell> B;
    std::vector<placeholderCell> C;
    std::vector<placeholderCell> D;
    std::vector<placeholderCell> E;
    std::vector<placeholderCell> F;
    std::vector<placeholderCell> G;
    std::vector<placeholderCell> H;
    std::vector<placeholderCell> I;
    std::vector<placeholderCell> J;
    
    //???
    for (std::string& row : grid) {

        
        for (char& i : row) {
            switch(i) {
                case 'J': {
                    placeholderCell newCell;
                    newCell.x = i;
                    J.push_back()
                    break;
                }
                case 'j': {
                    break;
                }

                
            }
        }
    }

    // (y)
    return shapes;
}
*/

void defineFreebies() {
    //three strip
    std::vector<placeholderCell> threeStrip;
    for (size_t i = 0; i < 3; i++) {
        placeholderCell newCell;
        newCell.x = i;
        newCell.y = 0;
        threeStrip.push_back(newCell);
    }

    std::cout << "Three Strip: " << std::endl;
    show(threeStrip);

    //tetromino t
    std::vector<placeholderCell> tetrominoT;
    for (size_t i = 0; i < 3; i++) {
        placeholderCell newCell;
        newCell.x = i;
        newCell.y = 0;
        tetrominoT.push_back(newCell);
    }

    placeholderCell newCell;
    newCell.x = 1;
    newCell.y = 1;
    tetrominoT.push_back(newCell);

    std::cout << "Tetromino T: " << std::endl;
    show(tetrominoT);

    //tetromino z

    //tetromino l
    std::vector<placeholderCell> tetrominoL;
    for (size_t i = 0; i < 3; i++) {
        placeholderCell newCell;
        newCell.x = i;
        newCell.y = 1;
        tetrominoL.push_back(newCell);
    }
    newCell.x = 2;
    newCell.y = 0;
    tetrominoL.push_back(newCell);
    std::cout << "Tetromino L: " << std::endl;
    show(tetrominoL);

}


