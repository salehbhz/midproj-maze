
#include <iostream>

void FillRoom();

int main()
{
    // Starting point and top-level control.
    srand( time(0) ); // seed random number generator.
    FillRoom();
    
    return 0;
}

void FillRoom()
{
    // Fills the grid with walls ('#' characters).
    for (int i=0; i<GRID_WIDTH*GRID_HEIGHT; ++i)
    {
        grid[i] = '+';
    }
}
