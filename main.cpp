#include <iostream> 
#include "Board.h"

int main()
{
    Board playingBoard; 

    playingBoard.Draw(); 
    playingBoard.Insert(1, 'X');
    playingBoard.Insert(4, 'O');
    playingBoard.Draw();

    return 0; 
}