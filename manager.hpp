#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/* Methods to have:
loadGrid(filename): Read the input text file, which contains the initial puzzle grid, and populate the game grid based on file content.
isGrid10x10(): check if grid is 10 x 10
isGridCharLegal(): return error if the grid has different than 10 unique lowercase letters.
isLegalRegion(): check for regions with a hanging letter and return error in that case
isLegalGrid(): check if a given puzzle is solvable; parent of isGrid10x10(), isGridCharLegal(), isLegalRegion()

isLegalPlacement(x, y, isStar): Given the coordinates (x, y) and whether you want to place a star or a cross, this method should check if the placement follows the game rules (maximum 2 stars in each row, column, and bounded region).
isPuzzleSolved(): Check if the puzzle is solved, meaning all the rules are met and the puzzle is complete.
*/

// bring the isGridCharLegal up here for vectorization and mapping
void loadGrid(const string& filename) {    
        cout << "works" << endl;
    }

// we can pass reference to the array or map contained the populated game grid for input parameter
bool isGrid10x10(const string& filename) {
    ifstream input(filename);
    if (!input) {
        cerr << "Error: Cannot open input file." << endl;
        return false;
    }

    vector<string> grid;
    string line;

    // Read the grid from the input file
    while (getline(input, line)) {
        grid.push_back(line);
    }

    // Check if the grid has 10 rows
    if (grid.size() != 10) {
        cerr << "Error: Grid does not have 10 rows. Submit another file" << endl;
        return false;
    }

    // Check if each row has 10 columns
    //i hate length()
    int acc = 1;
    for (const string& row : grid) {

        //check the last row first because this solution is dumb
        string& lastRow = grid[9];
        if (lastRow.length() == 11) {
            cerr << "Error: Grid does not have 10 columns in some rows. Submit another file" << endl;
            return false;
        }
        
        //for debug
        //cout << row.length() << endl;

        //since last row is the correct size we can check the other rows
        if  (row.length() != 11) {
            if (acc != grid.size()) {
                cerr << "Error: Grid does not have 10 columns in some rows. Submit another file" << endl;
                return false;
            }
            else {
                if (acc == grid.size() && lastRow.length() != 10) {
                    cerr << "Error: Grid does not have 10 columns in some rows. Submit another file" << endl;
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
bool isGridcharlegal(const string& filename) {
    map<char, int> map;
    for (const string& row : grid) {

        for (const char& i : row) {
            if (i != '\n') {
                map[i]++;
            }
        }
    }
    // Get an iterator pointing to the first element in the map
    map<char, int>::iterator it = map.begin();
 
    // Iterate through the map and print the elements
    while (it != map.end())
    {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        ++it;
    }
    return true;
}

bool isLegalRegion() {
    cout << "Hey there" << endl;
}

bool isLegalGrid() {
    cout << "Yo Legit" << endl;
}

isLegalPlacement(x, y, isStar) {
}

isPuzzleSolved() {
    
}



