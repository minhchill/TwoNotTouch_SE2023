// Testing out a design of a class to verify a solved puzzle 

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "manager.hpp"


// // Take a 10 x 10 grid with certain criteria as input and pass them into a list of vectors
// main driver

// // Pass that list of vectors into a list of sets to represent an irregular region
std::vector<std::string> setRegions(const ){
    std::vector<std::string> regions;
    return regions;
}

// // Check if 2 lower case letters (for 2 stars) are presented in a row or column (H)
// bool has2LowerCase(){
    
// }

// // Check if 2 lower case letters are presented in a bounded region (H)
// bool 

// // Correct solution 
// bool isCorrectSolution() {
//     return true;
// }

// Driver test
int main()
{
    std::ifstream puzzle ("testfilesolution.txt");
    std::string mystring;

    if (puzzle.is_open()){
        puzzle >> mystring;
        std::cout << mystring;
    }

}

// Driver
// int main()
// {
//     //open file, read contents to get puzzle
//     std::ifstream puzzle;
//     std::string line;
//     puzzle.open("testfilesolution.txt");
//     std::vector<std::string> g1;

//     if (puzzle.is_open()) {
//         while (std::getline(puzzle, line)) {
//             //std::cout << line << '\n';
//             g1.push_back(line);
//         }
//         puzzle.close();
//     }    

//     std::cout << isGridcharlegal(g1) << std::endl;

//     std::cout << "Output of vector: " << std::endl;
//     for (auto i = g1.begin(); i != g1.end(); i++)

//         std::cout << *i << std::endl;

//     std::cout << std::endl;
//     return 0;

// }
