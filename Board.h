/**
 * @file Board.h
 * @author Daniel Guzman (danielsonguzman2000@gmail.com)
 * @brief Object design of a TicTacToe Board
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board
{
public:
    /* attributes of the board
    will be stored here. */
    std::vector<std::vector<char>> board; 
    int dimension;
    int turnCount = 0; 

    Board(int dimension);

    void Draw(); 
    int Insert(int position, char symbol);
    void reset(); 
    bool CheckState(); 
    bool filled(); 
};

#endif