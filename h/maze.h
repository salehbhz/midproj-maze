#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include <vector>
#include <string>

class Maze {
private:
	// number of cells described with width and height
	int height;
	int width;

	// 2d maze vector
	std::vector<std::vector<Cell>> maze;

	// create vector of strings to store directions of solution
	std::vector<std::string> solution;

public:
	// constructor and methods
	Maze(const int inputHeight = 10, const int inputWidth = 10);
	void displayMaze() const;
	void generateMaze();
	void solveBfs();
	

};

#endif