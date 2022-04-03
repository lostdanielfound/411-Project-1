/**
 * @file A.i_helper_functions.h
 * @author Daniel Guzman (danielsonguzman2000@gmail.com)
 * @brief Function to aid in implimenting the Minimax algorithm
 * in which it will be designed to minimize the gains of the game state. 
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef A_I_FUNC_H
#define A_I_FUNC_H
#include "Board.h"

int evaluate(Board board, char symbol); 
int minimax(bool ismin, Board board, char symbol);
int optimalMove(Board board, char symbol); 

#endif // A_I_FUNC_H