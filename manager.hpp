#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

/* 
SPECIFICATION

Check for grid layout:
- If a blank grid is represented 
- If we have different-from-10 lower-case letters, return error
- If we find a diagonal space, or fewer-than-3 spaces for a region, return error
- If a grid has 10 unique lowercase letters abcdefghij, we proceed with solving the blank grid
- If a grid has * and - only, we proceed with checking the solution correctness

Check for solution correctness of a solved grid
- Each column, row, region has 2 * with each star not touching in legal fashion with correct syntax. The rest are represented with -
- 


Check for violations, such as:
- When a star is played *, replace all adjacent grid with a -
- When a column/line/region has a number of stars different from 2, return error

Check
*/

// If grid is not 10 x 10, return error/false
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
        //std::cout << row.length() << std::endl;

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

// If grid contains < 100 characters, return error
bool isGridcharlegal(const std::string& filename) {
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
    while (it != map.end())
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
    return true;
}

void solvePuzzle() {
    std::cout << "works" << std::endl;
}

void verifyPuzzle() {
    std::cout << "no grid" << std::endl;
}

// If grid meets all the requirement, begin evaluating to either solve it or to verify it
void toSolveorVerify() {

    if (isGrid10x10("testfile.txt")) {
        solvePuzzle();
    }

    else {
        verifyPuzzle();
    }
}



