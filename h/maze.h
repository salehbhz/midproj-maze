#ifndef MAZE_H
#define MAZE_H


#include <iostream>

class Maze
{
    public:
        Maze(int,int,int);
        Maze();

        
        void FillRoom();
        int XYToIndex( int x, int y );
        int IsInBounds( int x, int y );
      

        int get_room_width();
        int get_room_height();
        int get_path();

        char* room;


    private:
        int room_width;
        int room_height;
        int path;

};