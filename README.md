Maze Solver Project Descriptions
1. Maze Solver Using Deque Data Structure
Project Overview:
This project implements a maze-solving algorithm using a deque (double-ended queue) data structure. The maze is represented as a 2D grid of characters where 'S' marks the start, 'E' marks the end, '#' represents walls, and spaces (' ') represent open paths. The goal is to find a path from the start to the end position.

Key Features:

Deque Operations: The implementation utilizes deque operations to explore paths in the maze. Nodes can be added to the front or back of the deque, facilitating both breadth-first and depth-first search strategies.
Distance Heuristic: A distance heuristic (Manhattan distance) is used to prioritize nodes closer to the end position.
Path Marking: The algorithm marks visited paths to prevent revisiting and to visualize the path found.
Technologies Used:

C programming language
Deque data structure for efficient path exploration
2. Maze Solver Using Adjacency List and Breadth-First Search (BFS)
Project Overview:
This project uses an adjacency list to represent the maze as a graph and applies the breadth-first search (BFS) algorithm to find the shortest path from the start to the end position. The maze is similarly represented as a 2D grid of characters.

Key Features:

Graph Representation: The maze is converted into a graph where each cell is a node, and edges represent possible movements between cells.
BFS Algorithm: BFS is employed to explore the shortest path in an unweighted grid, ensuring the shortest path is found.
Dynamic Path Finding: The algorithm dynamically explores the maze, marking the path and updating the maze representation.
Technologies Used:

C programming language
Graph representation using adjacency lists
Breadth-first search (BFS) algorithm for pathfinding
