#include"maze.h"

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int main()
{
	int width{0},lenght{0},path{0};
	srand( time(0) ); //  random number generator.

	std::cout<<"enter width : ";
	std::cin>>width;
	std::cout<<std::endl;
	std::cout<<"enter lenght : ";
	std::cin>>lenght;
	std::cout<<std::endl;

	std::cout<<"if you want solve maze for dfs press 1 ";
	std::cin>>path;
	std::cout<<std::endl;
	
	Maze maze(width,lenght,path);
    

    return 0;
}

