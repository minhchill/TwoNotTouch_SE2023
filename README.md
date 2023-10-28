# TwoNotTouch_SE2023

SYPNOSIS:
A game based on Star Battle Go mobile game, text interface
- Input: An unsolved puzzle or a solved puzzle. 10x10, 10 irregular regions.
- Output: Confirm if the solution is correct (for solved puzzles) or solution (for unsolved puzzles)

WINNING: 2 non-adjacent nor non-tangent stars in each column, row, irregular region. The rest are marked off with x


UI:

**Input:** 10 characters representing 10 irregular region members, abcdefghij

a b b c c c d d d i

a b b b c c d d d i

...... so on


**Output:**

#1: Your solution is correct

#2: Your solution is incorrect at [.]

#3: The grid does not meet puzzle requirements

#4: [Spit out a correct solution]


