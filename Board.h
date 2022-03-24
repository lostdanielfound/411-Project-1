#ifndef BOARD_H
#define BOARD_H
class Board
{
private:
    /* attributes of the board
    will be stored here. */
    char** board; 
    int dimension;

    int turnCount = 0; 
public:
    Board(int dimension);
    ~Board(); 
    void Draw(); 
    int Insert(int position, char symbol);
    void reset(); 
    bool CheckState(); 
};

#endif