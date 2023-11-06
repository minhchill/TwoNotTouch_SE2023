// Testing out a design of a class to verify a solved puzzle 

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "manager.hpp"


// // Take a 10 x 10 grid with certain criteria as input and pass them into a list of vectors

// // Pass that list of vectors into a list of sets to represent an irregular region
// std::vector<std::string> setRegions(const ){
//     std::vector<std::string> regions;
//     return regions;
// }


// Check if 2 lower case letters (for 2 stars) are presented in a row
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

//

int main(int argc, char* argv[]) {
    // Open file, read contents to get the puzzle
    std::ifstream myfile;
    std::string line;
    myfile.open(argv[1]);
    std::vector<std::string> g1;

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            g1.push_back(line);
        }
        myfile.close();
    } else {
        std::cerr << "Error: No file" << std::endl;
        return 1; // Use "return 1" instead of "exit(1)" to gracefully exit the program
    }

    if (has2LowerCaseRow(g1)) {
        std::cout << "The puzzle has 2 lowercase letters in each row." << std::endl;
    } else {
        std::cout << "The puzzle does not have 2 lowercase letters in each row." << std::endl;
    }

    if (has2LowerCaseColumn(g1)) {
        std::cout << "The puzzle has 2 lowercase letters in each column." << std::endl;
    } else {
        std::cout << "The puzzle does not have 2 lowercase letters in each column." << std::endl;
    }


    return 0;
}
