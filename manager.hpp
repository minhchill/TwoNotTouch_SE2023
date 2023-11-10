// THIS MODULE IS REPONSIBLE FOR KEEPING TRACK OF THE GAME'S LOGIC

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

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
            std::cerr << "Error: Grid does not have 10 columns in some rows. Submit another file (1)" << std::endl;
            return false;
        }
        
        //for debug
        std::cout << row.length() << std::endl;

        //since last row is the correct size we can check the other rows
        /*
        if  (row.length() != 11) {
            if (acc != grid.size()) {
                std::cout << acc << std::endl;
                std::cerr << "Error: Grid does not have 10 columns in some rows. Submit another file (3)" << std::endl;
                return false;
            }
            else {
                if (acc == grid.size() && lastRow.length() != 10) {
                    std::cerr << "Error: Grid does not have 10 columns in some rows. Submit another file (2)" << std::endl;
                    return false;
                }
            }
        }
        */
        acc++;
    }

    // If the grid is 10x10, it's valid
    return true;
}

//to place stars
char change_case(char c) {
    if (std::isupper(c)) 
        return std::tolower(c); 
    else
        return std::toupper(c); 
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

// Some rename needed, maybe loadGrid is more appropriate which is up there
bool isGridcharlegal(std::vector<std::string>& grid) {
    std::map<char, int> map;
    std::map<char, placeholderCell> coords;
    
    auto placeholderGrid = grid;
    int acc = 0;

    for (std::string& row : placeholderGrid) {
        std::string::iterator it = row.begin();

        for (auto it = row.begin(); it < row.end(); ++it) {

            if (*it != '\n') {
                if (islower(*it)) {
                    change_case(*it);
                }

                placeholderCell newCell;
                newCell.x = std::distance(row.begin(), it);
                std::cout << *it << std::endl;
                newCell.y = acc;
                coords[*it] = newCell;
                
            }
        }
        acc++;
    }
    // Get an iterator pointing to the first element in the map
    //std::map<char, int>::iterator it = map.begin();
    /*
    // Iterate through the map and print the elements
    while (it != map.end()) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
    */
    std::map<char, placeholderCell>::iterator it;

    while (it != coords.end()) {
        std::cout << "Key: " << it->first << std::endl;
        it++;
    }

    return true;
}

// saving coordinates as a new vector, and check if they are adjacent to each other, return true for yes, return false


void placeStar(int x, int y, std::vector<std::string>& grid) {
    //std::cout << grid[x][y] << std::endl;
    grid[x][y] = change_case(grid[x][y]);
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
/*
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

*/
