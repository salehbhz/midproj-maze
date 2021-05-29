#ifndef CELL_H
#define CELL_H
// description of how the maze will be displayed
class Cell {
	public:
		bool visited = false;
		int row = 0;
		int col = 0;

		// only need to manipulate 2 walls for each cell since cells share walls
		bool northWall = true;
		bool eastWall = true;

	
		bool open = false;
		bool closed = false;

		Cell* parent = nullptr;
		bool path = false;
		bool search = false;

};

#ifndef MAZE_H
#define MAZE_H