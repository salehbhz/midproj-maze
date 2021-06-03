#ifndef CELL_H
#define CELL_H

class Cell 
{
	public:
		
		int row = 0;
		int col = 0;

		Cell* child=nullptr;
		Cell* parent=nullptr;
		
		bool northWall = true;
		bool eastWall = true;

		bool visited = false;
		bool open = false;
		bool closed = false;

		bool path = false;
		bool search = false;
		bool start =false;
		bool end = false;
		
};

#endif
