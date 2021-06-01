#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include <vector>
#include <string>

class Maze {
	public:
		// constructor and methods
		
		Maze(const int inputHeight = 10, const int inputWidth = 10);
		void displayMaze() const;
		void generateMaze();
		void solveBfs();
		// bool solveDfs(Cell*);
		// void solveDfs();
	private:
		Cell* targetNode;
		Cell* startNode;
	    Cell* currentNode;
		

		Cell* NeighbourNode=nullptr; 			// initialise neighbouring cell pointers to nullptr
		int height;
		int width;

		std::vector<std::vector<Cell>> maze;   	// 2d maze vector

		std::vector<Cell*>openlist;
		std::vector<Cell*>closedlist;

};

#endif