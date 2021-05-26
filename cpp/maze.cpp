#include"maze.h"
//-----------------------------constructor------------------------
Maze::Maze(int _room_width,int _room_height,int _path):room_width{_room_width},room_height{_room_height},path{_path}
{
	room = new char[room_width*_room_height];
	int x{0},y{0};

	FillRoom();

	if(room_height%2==0)
	{
		room_height++;
	}
	if(room_width%2==0)
	{
		room_width++;
	}

	x=room_width-2;
	y=room_heigh-2;
	Visit(x,y);
	
}

//-----------------------------fillroom---------------------------
void Maze::fillroom()
{
    for (int i=0; i<room_width*room_height; ++i)   	// Fills the grid with walls ('+' characters).
    {
        room[i] = '+';
    }
}

//-----------------------------XYtoindex----------------------------

int Maze::XYToIndex( int x, int y )
{
	return x * room_height + y;
}

//-------------------------------isinbounds----------------------------
int Maze::IsInBounds( int x, int y )
{
    if (x < 0 || x >= room_width) 
	{
		return false;
	}
    if (y < 0 || y >= room_height)
	{
		return false;
	}
    return true;
}


