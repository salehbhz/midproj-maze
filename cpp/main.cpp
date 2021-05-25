#include"maze.h"

int main()
{

	int siz;
	srand(time(NULL));
	
	std::cout << "Input the desired side length for the maze : ";
	std::cin >> siz;

	while(siz <= 3 && siz != 0)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Invalid size. Size must be a positive integer greater";
		std::cout << " than 3: ";
		std::cin >> siz;
	}
	
	Maze maze(siz);
	maze.generatorMaze();

	
	return 0;
}

