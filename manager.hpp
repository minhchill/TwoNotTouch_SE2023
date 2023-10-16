#include <iostream>

/* 
SPECIFICATION

Check for grid layout:
- If the grid is not 10 x 10, return error
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
