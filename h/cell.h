#ifndef CELL_H
#define CELL_H
// description of how the maze will be displayed
class Cell {
	public:
		bool visited = false;
		int row = 0;
		int col = 0;

		
		bool northWall = true;
		bool eastWall = true;

		
		bool open = false;
		bool closed = false;

		
		Cell* child=nullptr;
		Cell* parent=nullptr;

		bool path = false;
		bool search = false;

};

#ifndef MAZE_H
#define MAZE_H
