#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "manager.hpp"
//#include "player.hpp"

int main()
{  
    //open file, read contents to get puzzle
    std::ifstream myfile;
    std::string line;
    myfile.open("testfile.txt");
    std::vector<std::string> g1;

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            //std::cout << line << '\n';
            g1.push_back(line);
        }
        std::cout << isGridLegal("testfile.txt");
        myfile.close();
    }    
    
    std::cout << "Output of vector: " << std::endl;
    for (auto i = g1.begin(); i != g1.end(); i++)

        std::cout << *i << std::endl;

    std::cout << std::endl;
    return 0;
}
