#include <iostream>
#include "maze.h"
#include "cell.h"
#include <ctime>
#include <fstream>

// initialising dimensions
Maze::Maze(const int inputHeight, const int inputWidth): height{ inputHeight }, width{ inputWidth } 
{
	for (int i = 0; i < height; i++) 
	{
		std::vector<Cell> mazeRow;
		for (int j = 0; j < width; j++) 
		{
			Cell cell;
			cell.row = i;
			cell.col = j;
			mazeRow.push_back(cell);
			
		}
		maze.push_back(mazeRow);
	}
	
	std::cout << "The width of the maze is " << width << std::endl;
	std::cout << "The height of the maze is " << height << std::endl;
	
	
	generateMaze();
	displayMaze();
}

void Maze::generateMaze() 
{
	// set random seed using time
	srand(time(0));

	// create a vector of pointers to Cells
	std::vector<Cell*> mazeStack;

	// create a vector of pointers to neighbours of cells
	std::vector<Cell*> neighbours;

	// choose the initial cell, mark it as visited and push it to stack
	int row = 0;
	int col = 0;
	Cell* currentCell = &maze[row][col];
	currentCell->visited = true;
	mazeStack.push_back(&maze[row][col]);

	// initialise neighbouring cell pointers to something
	Cell* northCell = &maze[row][col];
	Cell* eastCell = &maze[row][col];
	Cell* southCell = &maze[row][col];
	Cell* westCell = &maze[row][col];
	Cell* randomNeighbour = &maze[row][col];

	// while stack is not empty
	while (!mazeStack.empty()) 
	{

		// pop a cell from the stack and make it the current cell
		row = mazeStack.back()->row;
		col = mazeStack.back()->col;
		
		currentCell = &maze[row][col];
		mazeStack.pop_back();
		
		// define and check if any neighbours have not been visited
		// also check for out of bound indexes
		if (row > 0 && !maze[row - 1][col].visited) 
		{
			northCell = &maze[row - 1][col];
			neighbours.push_back(northCell);
		}
		if (col < width - 1 && !maze[row][col + 1].visited) 
		{
			eastCell = &maze[row][col + 1];
			neighbours.push_back(eastCell);
		}
		if (row < height - 1 && !maze[row + 1][col].visited) 
		{
			southCell = &maze[row + 1][col];
			neighbours.push_back(southCell);
		}
		if (col > 0 && !maze[row][col - 1].visited) 
		{
			westCell = &maze[row][col - 1];
			neighbours.push_back(westCell);
		}

		// check if any neighbours have not been visited
		if (!neighbours.empty())
		{
			// push the current cell to the stack
			mazeStack.push_back(currentCell);
			// choose random unvisited neighbour
			randomNeighbour = neighbours[rand() % neighbours.size()];
			// push chosen cell as visited and push to stack
			randomNeighbour->visited = true;
			mazeStack.push_back(randomNeighbour);
			// remove wall between current cell and chosen cell
			if (randomNeighbour == northCell) {
				currentCell->northWall = false;
			}
			else if (randomNeighbour == eastCell) {
				currentCell->eastWall = false;
			}
			else if (randomNeighbour == southCell) {
				southCell->northWall = false;
			}
			else {
				westCell->eastWall = false;
			}
			neighbours.clear();

		}
	}
	std::cout << "Maze has been generated!\n";
}