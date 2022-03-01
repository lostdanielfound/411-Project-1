#ifndef BOARD_H
#define BOARD_H
#define WIDTH 3
#define LENGTH 3
class Board
{
private:
    /* attributes of the board
    will be stored here. */
    char board[3][3] = { {'-', '-', '-'},
                         {'-', '-', '-'},
                         {'-', '-', '-'}};
    int turnCount = 0; 
public:
    Board();
    ~Board();
    void Draw(); 
    int Insert(int position, char symbol);
    void reset(); 

};

#endif