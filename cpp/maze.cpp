#include "maze.h"
#include "cell.h"

//------------------------------constructor----------------------------
Maze::Maze(const int _height, const int _width,const int _startRow,const int _startCol,const int _endRow,const int _endCol,const char _solve):
	height{ _height },
	width{ _width } ,
	startRow{_startRow},
	startCol{_startCol},
	targetRow{_endRow},
	targetCol{_endCol}
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

	// set target node

	targetNode = &maze[targetRow-1][targetCol-1];
	targetNode->end=true;

	// set start and current node

	startNode = &maze[startRow-1][startCol-1];
	cell_searching.push_back(startNode);
	startNode->open=true;
	startNode->start=true;


	std::cout << "The width of the maze is " << width << std::endl;
	std::cout << "The height of the maze is " << height << std::endl;
	
	switch(_solve)
	{
		case 'D':
		{
			generateMaze();
			displayMaze();
			std::cout << "\n\nMaze has been solved with DFS algorithm!\n";
			solveDfs(startNode);
			displayMaze();
			
		};break;
		case 'B':
		{
			generateMaze();
			displayMaze();
			std::cout << "\n\nMaze has been solved with BFS algorithm!\n";
			solveBfs();
			displayMaze();
		}
	}

}

//-----------------------------Generator-------------------------------

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

//--------------------------------BFS-----------------------------------

void Maze::solveBfs() 
{
	int depth=0;
	while(true)
	{	

		currentNode=cell_searching[depth];
			
		currentNode->open=false;
		
		
		//remove currentnode from cell_searching
		if(currentNode==targetNode){break;}
		
		
		//add current node to closelist
		cell_searched.push_back(currentNode);
		currentNode->closed=true;
		
		
		for(int j=-1 ; j<2 ; j++)
		{
			
			for(int i=-1;i<2;i++)
			{
				
				
				if (i == j || i == -j || (i == 0 && j == 0)) 
				{
					
					continue;
				}
				
				if (currentNode->row + i < 0 || currentNode->col + j < 0 || currentNode->row + i >= height || currentNode->col + j >= width) 
				{
					continue;
				}
				
				if (maze[currentNode->row + i][currentNode->col + j].closed) 
				{
					continue;
				}
				
				if (i == -1 && j == 0 && maze[currentNode->row][currentNode->col].northWall ) 
				{
					continue;
				}
				
				if (i == 0 && j == 1 && maze[currentNode->row][currentNode->col].eastWall) 
				{
					continue;
				}
				
				if (i == 1 && j == 0 && maze[currentNode->row + 1][currentNode->col].northWall)
				{
					continue;
				}
				
				if (i == 0 && j == -1 && maze[currentNode->row][currentNode->col - 1].eastWall) 
				{
					continue;
				}

				NeighbourNode = &maze[currentNode->row + i][currentNode->col + j];
				
				if ( !NeighbourNode->open) 
				{
				
					// set parent of neighbour to current
					NeighbourNode->parent = currentNode;
					NeighbourNode->search = true;
					NeighbourNode->open = true;
					cell_searching.push_back(NeighbourNode);
				}
			}

		}
		depth++;
	}


	currentNode = targetNode;
	while (currentNode != startNode) 
	{
		currentNode->path = true;
		currentNode = currentNode->parent;
	}
	startNode->path = true;
	
	fputs("\033[0;32m", stdout);
    fputs("X", stdout);
	fputs("\033[0m", stdout);
	std::cout <<" = path , ";   
				
	fputs("\033[0;91m", stdout);
    fputs(".", stdout);
	fputs("\033[0m", stdout);
	std::cout <<" = search area , ";

	fputs("\033[0;34m", stdout);
    fputs("S", stdout);
	fputs("\033[0m", stdout);
	std::cout <<" = startNode , ";

	fputs("\033[0;33m", stdout);
    fputs("E", stdout);
	fputs("\033[0m", stdout);
	std::cout<<" = EndNode\n";
	std::cout<<"startNode = ("<<startRow<<","<<startCol<<")\n";
	std::cout<<"endNode = ("<<targetRow<<","<<targetCol<<")\n";

}

//---------------------------------DFS----------------------------------
bool Maze::solveDfs(Cell* node) 
{
	std::list<Cell*>LIST;
	currentNode=node;
	
		//remove currentnode from cell_searching
		
		currentNode->open=false;
		
		//add current node to closelist
		cell_searched.push_back(currentNode);
		currentNode->closed=true;


		for(int j=-1 ; j<2 ; j++)
		{
			
			for(int i=-1;i<2;i++)
			{
				
				
				if (i == j || i == -j || (i == 0 && j == 0)) 
				{
					
					continue;
				}
				
				if (currentNode->row + i < 0 || currentNode->col + j < 0 || currentNode->row + i >= height || currentNode->col + j >= width) 
				{
					continue;
				}
				
				if (maze[currentNode->row + i][currentNode->col + j].closed) 
				{
					continue;
				}
				
				if (i == -1 && j == 0 && maze[currentNode->row][currentNode->col].northWall ) 
				{
					continue;
				}
				
				if (i == 0 && j == 1 && maze[currentNode->row][currentNode->col].eastWall) 
				{
					continue;
				}
				
				if (i == 1 && j == 0 && maze[currentNode->row + 1][currentNode->col].northWall)
				{
					continue;
				}
				
				if (i == 0 && j == -1 && maze[currentNode->row][currentNode->col - 1].eastWall) 
				{
					continue;
				}

				NeighbourNode = &maze[currentNode->row + i][currentNode->col + j];
				NeighbourNode->parent = currentNode;
				currentNode->child=NeighbourNode;
				NeighbourNode->search = true;

				if ( !NeighbourNode->open) 
				{
					LIST.push_back(NeighbourNode);
					// set parent of neighbour to current
					NeighbourNode->open = true;
					
				}
			}
		}
		for(auto child:LIST)
		{
			if(child==targetNode)
			{
				while (child != startNode) 
				{
					child->path = true;
					child = child->parent;
				}
				startNode->path = true;

				fputs("\033[0;32m", stdout);
        		fputs("X", stdout);
				fputs("\033[0m", stdout);
				std::cout <<" = path , ";   
				
				fputs("\033[0;91m", stdout);
        		fputs(".", stdout);
				fputs("\033[0m", stdout);
				std::cout <<" = search area , ";

				fputs("\033[0;34m", stdout);
        		fputs("S", stdout);
				fputs("\033[0m", stdout);
				std::cout <<" = startNode , ";

				fputs("\033[0;33m", stdout);
        		fputs("E", stdout);
				fputs("\033[0m", stdout);
				std::cout<<" = EndNode\n";

				std::cout<<"startNode = ("<<startRow<<","<<startCol<<")\n";
				std::cout<<"endNode = ("<<targetRow<<","<<targetCol<<")\n";
				return true;
			}
			else
			{
				solveDfs(child);
			}
		}

	return false;

}

//-------------------------------Display-------------------------------

void Maze::displayMaze() const 
{

	for (auto const& mazeRow : maze) {

		// print top/bottom walls
		for (auto const& cell : mazeRow) {
			std::cout << "+";
			// print if top wall is true
			if (cell.northWall) {
				std::cout << "---";
			}
			else {
				std::cout << "   ";
			}
		}
		std::cout << "+" << std::endl;


		// print left/right walls on next line
		std::cout << "|";
		for (auto const& cell : mazeRow) {
			// print if right wall if true ( x = path, o = searched node but not part of path)
			
			if (!cell.end&&!cell.start&&cell.eastWall && cell.path && !cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;32m", stdout);
        		fputs("X", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc('|', stdout);

			}
			else if (cell.start&&!cell.end&&cell.eastWall && cell.path && !cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;34m", stdout);
        		fputs("S", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc('|', stdout);

			}

			else if (cell.end&&!cell.start&&cell.eastWall && cell.path && !cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;33m", stdout);
        		fputs("E", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc('|', stdout);

			}

			//---------------------------------------------------

			else if (cell.eastWall && !cell.path && !cell.search) 
			{ 
				fputc(' ', stdout);
				fputc(' ', stdout);
				fputc(' ', stdout);
				fputc('|', stdout);
			}
			//-----------------------------------------------------
			else if (!cell.end&&!cell.start&&!cell.eastWall && cell.path && !cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;32m", stdout);
        		fputs("X", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc(' ', stdout);
				
			}
			else if (cell.start&&!cell.end&&!cell.eastWall && cell.path && !cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;34m", stdout);
        		fputs("S", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc(' ', stdout);
				
			}
			else if (cell.end&&!cell.start&&!cell.eastWall && cell.path && !cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;33m", stdout);
        		fputs("E", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc(' ', stdout);
				
			}
			//--------------------------------------------------------------
			else if (!cell.end&&!cell.start&&cell.eastWall && cell.path && cell.search) 
			{
				fputc(' ', stdout);
				fputs("\033[0;32m", stdout);
        		fputs("X", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc('|', stdout);
			}
			else if (cell.start&&!cell.end&&cell.eastWall && cell.path && cell.search) 
			{
				fputc(' ', stdout);
				fputs("\033[0;34m", stdout);
        		fputs("S", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc('|', stdout);
			}
			else if (cell.end&&!cell.start&&cell.eastWall && cell.path && cell.search) 
			{
				fputc(' ', stdout);
				fputs("\033[0;33m", stdout);
        		fputs("E", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc('|', stdout);
			}
			//---------------------------------------------------------------------
			else if (cell.eastWall && !cell.path && cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;91m", stdout);
        		fputs(".", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc('|', stdout);
			}
			else if (!cell.eastWall && !cell.path && cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;91m", stdout);
        		fputs(".", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc(' ', stdout);
				
				
			}
			//------------------------------------------------------------------------
			else if (!cell.end&&!cell.start&&!cell.eastWall && cell.path && cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;32m", stdout);
        		fputs("X", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc(' ', stdout);
				
			}
			else if (cell.start&&!cell.end&&!cell.eastWall && cell.path && cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;32m", stdout);
        		fputs("S", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc(' ', stdout);
				
			}
			else if (cell.end&&!cell.start&&!cell.eastWall && cell.path && cell.search) 
			{ 
				fputc(' ', stdout);
				fputs("\033[0;33m", stdout);
        		fputs("E", stdout);
				fputs("\033[0m", stdout);
				fputc(' ', stdout);
				fputc(' ', stdout);
				
			}
			else 
			{
				std::cout << "    "; 
			}
		}
		std::cout << std::endl;

	}

	// print final bottom walls
	for (int i = 0; i < width; i++) {
		std::cout << "+---";
	}
	std::cout << "+" << std::endl;

}