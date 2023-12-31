1. Introduction:
Two Not Touch Game is a logic puzzle where you have to arrange stars in a grid, usually square shaped grids. The objective is to arrange the stars in each row, column, and area of the divided grid in accordance with predetermined guidelines.
There may be different rules, but generally speaking, there should be a certain amount of stars in each row and column, and no two stars should be in the same row, column, or area. The task is to figure out where the stars should go based on the hints given.
The goal of the Star Battle puzzle is to satisfy every requirement by constructing a solution that fills the full grid with stars in accordance with the regulations

Input :
1-  When the application launches, it will take a text file that is a single 10x10 square grid with 10 irregular containers inside of it. The 10x10 rows of different capital letters that make up the containers reflect the grid's cells.

2- When an empty puzzle is entered, indicated by the absence of any lowercase letters, the program will produce a workable solution and provide it to the user when it is finished.

3- The application will check to see if the suggested answer, which is shown by lowercase letters on the grid , is right when the input is a text file. When it's finished, the user will see the outcome.

Winning :
1- Two stars or fewer in a row or column:There can be no more than two stars in any row or column of the grid. By following this guideline, it is ensured that the stars are dispersed uniformly and are not gathered in one row or column.

2- Not Neighboring Stars: Stars cannot be positioned diagonally, vertically, or horizontally between neighboring cells. This regulation makes it impossible for stars to be arranged side by side, resulting in a distinct space between them.

3- Two stars in every region exactly:There must be precisely two stars in each of the regions that make up the grid. This rule maintains balance by distributing stars uniformly over the grid.

4- Stars in a Region Cannot Be in the Same Row or Column: Stars cannot be arranged in the same row or column inside a region that spans several rows or columns. The challenge becomes even more complex as a result of this rule.

5- Full Reporting:There must be a star or an empty cell covering every cell in the grid. No cells should be left exposed.


2. Class Documentation:


manager: 
* Contains functions for loading the puzzle, checking if it's a 10x10 grid, and verifying if the characters in the grid are legal.
* Defines various shapes and freebies for the puzzle.
* Provides some utility functions for output and manipulation of data.


solver:
* Defines classes for solving the puzzle, including Cell, Shape, Container, and Player.
* solvePuzzle, starPlacing, inaccessibleMarking, and toSolveorVerify // still in progress 


verifier:
* Contains functions to verify if a puzzle has the required characters (stars) in its rows and columns.
* Also includes some commented-out code in progress.


main.cpp:

The main entry point of the program.
It reads a puzzle from a file, checks its validity, and prints out the content.
Calls functions from manager.hpp to check if the grid is a 10x10 grid and if it's legal.

2. Installation
* Environment requirements: Visual Studio Code, C++ extension packages G++ compiler
* Step 1: Download the ZIP file on the main branch and extract it
* Step 2: Open the folder in VS Code and ensure there is no syntactical bugs
* Step 3: Run the following commands:
g++ -o main.exe main.cpp
./main.exe [test file]

3. Understanding the program
* So far, the working software takes a solved puzzle as an input and has two key functionalities:
* * Print out the puzzle and list out the number of the irregular regions that can be solved strategically
* * Check if each column/row/region has 2 lower-case letters (representing the stars). If the solved puzzle satisfies the above requirements, then the program returns the message
