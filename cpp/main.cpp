#include "maze.h"

int main() {

	// define dimensions
	int height = 30;
	int width = 30;

	// create maze object
	Maze maze(height, width);

	
	maze.solveBfs();
	maze.displayMaze(); 


	return 0;

}