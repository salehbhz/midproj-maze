#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>     
#include <time.h> 
#include"room.h"
class Room;
class Maze
{
    public:

        Maze(int size);
        ~Maze();

        int getAdjacentRoom(int roomNumber, int size);
        int mazeRow(int roomNumber, int size);
        int mazeColumn(int roomNumber, int size);
        void openDoors(Room *room1, Room *room2, int size);
        bool checkComplete(Room **maze, int size);
        void updatePaths(Room **maze, int size, int oldPath, int newPath);
        void generatorMaze();

    private:
        int size;
        Room** maze;

};

#endif