# TwoNotTouch_SE2023

SYPNOSIS:
A game based on Star Battle Go mobile game, text interface
- Input: An unsolved puzzle or a solved puzzle. 10x10, 10 irregular regions.
- Output: Confirm if the solution is correct (for solved puzzles) or solution (for unsolved puzzles)

WINNING: 2 non-adjacent nor non-tangent stars in each column, row, irregular region. The rest are marked off with x

STRATEGIES:
- Same star-placing pattern for 3-grid region, 3x2 L shape (1 unknown), 3x3 rectangle (2 unknown), T shape, Z-ish, 
- Eliminate spots that cannot have a star (3-grid column, potential adjacent/tangent to star zone, a spot that would not permit 2 stars at once)

USER STORIES: (Violation of criteria for winning)
1. User supplies a blank grid 
   - Return error message if the grid does not follow layout rules

2. User supplies a correctly solved puzzle file 
   - Return "You solved it!" for correct solution

3. User supplies an incorrect solution 
   - Return "The solution is incorrect" and point out where for incorrect solution

4. User supplies a blank grid that matches layout requirement
   - Print out the correct solution
  
Player stories (Based on the mobile game):
- Start a new game
- Alright, first I scan for the smallest irregular regions to apply repeating star-placing patterns. (I scan for all the possible 1-row/column regions to x the rest of the row-column because 2 stars have to be within there already). The two columns/rows tangent to it have to be marked off with x too)
- I fill x in the columns/rows/regions that already have 2 stars (constant process)
- I guess where a star cannot be placed (possible collision with neighbor solution, repeating stars)
- I fill in rows/columns/regions with 2 blank grids or 3 adjacent grids

FUNTIONS:
- **Driver:** Take file input and return according message
- **checkGrid:** Scan the grid based on layout criteria
- **checkSolution:** Scan the grid based on the given criteria, detect any violations (# other than 2 stars)
- **placeStar:** Put a star in a designated grid, cross off the adjacent/tangent grids with x
- **fillBlank:** Scan for rows/columns/regions with 2 blank grid (not adjacent to each other to fill in stars or x accordingly

UI IDEA:

**Input:** 10 characters representing 10 irregular region members, abcdefghij

a b b c c c d d d i

a b b b c c d d d i

...... so on


**Output:**

#1: You solved it!

#2: Your solution is incorrect at [.]

#3: The grid does not meet puzzle requirements

#4: [Spit out a correct solution]


