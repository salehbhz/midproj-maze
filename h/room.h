#ifndef ROOM_H
#define ROOM_H

#include"maze.h"

class Room
{
	private:
	int roomNumber;
	int pathNumber;
	bool north;
	bool south;
	bool east;
	bool west;
	bool visited;

	public:
	Room();
	void setRoomNumber(int x);
	void setPathNumber(int x);
	void setNorth(bool x);
	void setSouth(bool x);  
	void setEast(bool x);
	void setWest(bool x);
	void setVisited(bool x);
	int getRoomNumber();
	int getPathNumber();
	bool getNorth();
	bool getSouth();  
	bool getEast();
	bool getWest();
	bool getVisited();
};
#endif