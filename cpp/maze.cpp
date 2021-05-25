#include"maze.h"
//-----------------------------constructor-----------------------
Maze::Maze(int _size):size{_size}
{
 
    maze = new Room*[size];
	for(int i{0}; i < size; i++)
	{
		maze[i] = new Room[size];
	}

    for(int i = 0; i < size; i++)                           	//creat a matrix with size , from 0 until (size^2)-1 
	{
		for(int j = 0; j < size; j++)
		{
			maze[i][j].setRoomNumber((i * size) + j);
			maze[i][j].setPathNumber((i * size) + j);
           
		}
	}

}

//---------------------------destructor---------------------------

Maze::~Maze()
{
   
    for(int i = 0; i < size; i++)
	{
		delete[] maze[i];
	}
	delete[] maze;
	
}

//--------------------------generatorMaze------------------------

void Maze::generatorMaze()
{
   
	while(checkComplete(maze, size))
	{	
		int roomCount = size * size;
		int room = rand() % roomCount;							//room : from 1 - (size^2)-1
		int adjacentRoom = getAdjacentRoom(room, size);			//create neighbers of each room
		
		int row1 = mazeRow(room, size);							//row1 : random from 1 - (size -1)
		int col1 = mazeColumn(room, size);						//col1 : random from 1 - (size -1)
		int row2 = mazeRow(adjacentRoom, size);					
		int col2 = mazeColumn(adjacentRoom, size);

		if(maze[row1][col1].getPathNumber()!= maze[row2][col2].getPathNumber())
		{
			openDoors(&maze[row1][col1], &maze[row2][col2], size);
			if(maze[row1][col1].getPathNumber()> maze[row2][col2].getPathNumber())
			{
				updatePaths(maze, size, maze[row1][col1].getPathNumber(),maze[row2][col2].getPathNumber());
			}
			 else 
			{
				updatePaths(maze, size, maze[row2][col2].getPathNumber(),maze[row1][col1].getPathNumber());
			}
		}

	}
    
    maze[0][0].setNorth(1);
	maze[size - 1][size - 1].setSouth(1);
	
	std::cout << "\nCurrent Maze:\n";

	for(int i = 0; i < size; i++)
	{
		if(maze[0][i].getNorth() == 0)
		{
			std::cout << "+---";
		} 
		else 
		{
			std::cout << "+   ";
		}
	}
	std::cout << "+\n";
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(maze[i][j].getWest() == 0)
			{
				std::cout << "|   ";	
			} 
			else 
			{
				std::cout << "    ";
			}
		}
		std::cout << "|\n";
		for(int j = 0; j < size; j++)
		{
			if(maze[i][j].getSouth() == 0)
			{
				std::cout << "+---";
			} else {
				std::cout << "+   ";
			}
		}
		std::cout << "+\n";
	}
    
}


//--------------------------getAdjacentRoom-------------------------

int Maze::getAdjacentRoom(int roomNumber, int size)
{
    
    int adj, maxNumber, delta, addSub;
	bool valid = 0;
	maxNumber = (size * size) - 1;

	while(valid == 0)
	{
		valid = 1;
		delta = rand() % 2;
		addSub = rand() % 2;
		if (delta == 0)
		{
			delta = size;
		}
		if(addSub == 1)
		{
			adj = roomNumber + delta;
		} 
		else 
		{
			adj = roomNumber - delta;
		}
		// 4 special cases where it would not be adjacent
		if((adj - roomNumber == 1) && (adj % size == 0))
		{
			valid = 0;
		}
		if((roomNumber - adj == 1) && (roomNumber % size == 0))
		{
			valid = 0;
		}
		if((adj < 0) || (adj > maxNumber))
		{
			valid = 0;
		}
	}
	return adj;
}

//---------------------------mazeRow-------------------------------

int Maze::mazeRow(int roomNumber,int size)
{
   
    return roomNumber / size;
}

//-------------------------mazeColumn------------------------------

int Maze::mazeColumn(int roomNumber,int size)
{
   
    return roomNumber % size;
}

//-----------------------------openDoors---------------------------

void Maze::openDoors(Room* room1,Room* room2,int size)
{
  
    if(room1->getRoomNumber() - room2->getRoomNumber() == 1)
	{
		room1->setWest(1);
		room2->setEast(1);
	}
	if(room2->getRoomNumber() - room1->getRoomNumber() == 1)
	{
		room2->setWest(1);
		room1->setEast(1);
	}
	if(room1->getRoomNumber() - room2->getRoomNumber() == size)
	{
		room1->setNorth(1);
		room2->setSouth(1);
	}
	if(room2->getRoomNumber() - room1->getRoomNumber() == size)
	{
		room2->setNorth(1);
		room1->setSouth(1);
	}
}

//-------------------------checkComplete--------------------------

bool Maze::checkComplete(Room ** maze , int size)
{
  
    for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(maze[i][j].getPathNumber() != 0)
			{
				return true;
			}
		}
	}
	return false;
}

//--------------------------updatepaths-------------------------------

void Maze::updatePaths(Room **maze, int size, int oldPath, int newPath)
{
   
    for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(maze[i][j].getPathNumber() == oldPath)
			{
				maze[i][j].setPathNumber(newPath);
			}
		}
	}
}