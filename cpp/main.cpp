#include "maze.h"

int main() 
{	
	int height ,width,startRow,startCol,endRow,endCol;
	char ch,Ran;
	
	std::cout<<std::endl;
	std::cout<<"---------------------------------------------------------------------------------------------------------"<<std::endl;
	
	std::cout<<"\nif you want generate random maze with random startnode and endnode press ---> R , Manual press ---> M : ";
	std::cin>>Ran;
	std::cout<<std::endl;

	while(Ran != 'R' && Ran != 'M')
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "no generate whith your want pleas use this (R ---> random ; M ---> Manual) : ";
		std::cin >> Ran;
	
	}

	switch(Ran)
	{

		case 'M':
		{

			std::cout<<std::endl;
			std::cout<<"Input the desired side height for the maze : ";
			std::cin>>height;
			
			std::cout<<"Input the desired side width for the maze : ";
			std::cin>>width;
			std::cout<<std::endl;

			std::cout<<"Input the desired startRow for the maze : ";
			std::cin>>startRow;
			while(startRow < 1 || startRow > height)
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid startRow. startRow must be (1 < startRow < height) : ";
				std::cin >> startRow;
			}

			std::cout<<"Input the desired startCol for the maze : ";
			std::cin>>startCol;
			while(startCol < 1 || startCol> width)
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid startCol. startCol must be (1 < startCol < width) : ";
				std::cin >> startCol;
			}
			std::cout<<std::endl;

			std::cout<<"Input the desired endRow for the maze : ";
			std::cin>>endRow;
			while(endRow < 1 || endRow > height)
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid endRow. endRow must be (1 < endRow < width) : ";
				std::cin >> endRow;
			}
			
			std::cout<<"Input the desired endCol for the maze : ";
			std::cin>>endCol;
			while(endCol < 1 || endCol > width)
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid endCol. endCol must be (1 < endCol < width) : ";
				std::cin >> endCol;
			}
			std::cout<<std::endl;
		};break;
		case 'R':
		{
			srand(time(0));
			height = rand() % 20+10 ;
			width = rand() % 20+10;
			startRow = (rand() % (height-1))+1 ;
			startCol = (rand() % (width-1))+1 ;
			endRow = (rand() % (height-1))+1 ;
			endCol = (rand() % (width-1))+1;
			while(startRow==endRow && startCol==endCol)
			{
			startRow = (rand() % (height-1))+1 ;
			startCol = (rand() % (width-1))+1 ;
			endRow = (rand() % (height-1))+1 ;
			endCol = (rand() % (width-1))+1;
			}
	
		
		}
	}

	std::cout<<"How do you want to solve maze? (D--->Dfs ; B--->Bfs): ";
	std::cin>>ch;
	
	while(ch!='B' && ch!='D')
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "no solve whith your want pleas use this solve (D--->Dfs ; B--->Bfs) : ";
		std::cin >> ch;
	}
	std::cout<<std::endl;
	std::cout<<"---------------------------------------------------------------------------------------------------------\n\n\n\n";
	Maze maze(height, width,startRow,startCol,endRow,endCol,ch);
	

	return 0;

}