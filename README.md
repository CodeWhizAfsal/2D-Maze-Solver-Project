# 2D-Maze-Solver-Project
# 2D Maze Solver

## Objective
Develop an algorithm to find a path in a 2D maze using graph representation and Breadth-First Search (BFS).

## Language
C

## Project Description

### Part A: Deque Implementation
- Implemented a deque using an array with a circular buffer for efficient space utilization.
- Operations:
  - `add_first(x)`: Adds an element `x` to the front of the deque.
  - `remove_first()`: Removes an element from the front of the deque.
  - `add_last(x)`: Adds an element `x` to the end of the deque.
  - `remove_last()`: Removes an element from the end of the deque.
- Achieved O(1) average runtime for adding and removing elements at both ends.

### Part B: 2D Maze Solver
- Input: Read maze description from a `.txt` file with the following symbols:
  - `#`: Wall/block
  - `S`: Start position
  - `E`: End position
- Represented the maze as a graph where each cell is a node and edges exist between adjacent walkable cells.
- Utilized the deque from Part A to perform a BFS to find the shortest path from the start position to the end position.

## File Structure
- `deque.h`: Header file for deque implementation.
- `deque.c`: Source file for deque implementation.
- `maze_solver.h`: Header file for maze solver.
- `maze_solver.c`: Source file for maze solver.
- `main.c`: Main program to execute the maze solver.
- `maze.txt`: Example input file for the maze description.
