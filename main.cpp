#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "manager.hpp"
//#include "solver.hpp"
#include "verifier.cpp"

int main(int argc, char* argv[])
{  
    //open file, read contents to get puzzle
    std::ifstream myfile;
    std::string line;
    myfile.open(argv[1]);
    std::vector<std::string> g1;

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            //std::cout << line << '\n';
            g1.push_back(line);
        }
        std::cout << isGrid10x10(argv[1]) << std::endl;
        myfile.close();
    } 
    //if file is not found, exit with error message   
    else {
        std::cerr << "Error: no file" << std::endl;
        exit(1);
    }
    
    //next, check that a file is a valid puzzle
    std::cout << isGridcharlegal(g1) << std::endl;

    //if a puzzle is valid, begin solving OR checking solutions
    //defineFreebies();


    //lastly, output the vector of the solution if found
    std::cout << "Output of vector: " << std::endl;
    for (auto i = g1.begin(); i != g1.end(); i++)

        std::cout << *i << std::endl;

    std::cout << std::endl;

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
