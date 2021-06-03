#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include <vector>
#include<iostream>
#include<list>
#include <cstdlib>
#include <ctime>

class Maze 
{
	public:
		// constructor and methods
		Maze(const int _height, const int _width,const int _startRow,const int _startCol,const int _endRow,const int _endCol,const char _solve);

		void displayMaze() const;
		void generateMaze();
		void solveBfs();
		bool solveDfs(Cell*);
		
	private:
		Cell* targetNode;
		Cell* startNode;
	    Cell* currentNode;
		Cell* NeighbourNode=nullptr; 		// initialise neighbouring cell pointers to nullptr

		int height;
		int width;
		int startRow ;
		int startCol ;
		int targetRow ;
		int targetCol ;

		std::vector<std::vector<Cell>> maze;   	// 2d maze vector
		std::vector<Cell*>cell_searching;
		std::vector<Cell*>cell_searched;
};

#endif