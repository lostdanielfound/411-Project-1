#include "A.i_helper_functions.h"



int evaluate(Board board)
{

}

/**
 * @brief minimax function that is to return the optimal
 * value the A.i can obtain when minimizing the gains of 
 * the game. 
 * 
 * @param depth The total and current depth of the decision tree 
 * @param index 
 * @param ismin If True we are minimizing the game otherwise we are maximizing. 
 * @param board The current game board
 * @return int 
 */
int minimax(int depth, int index, bool ismin, Board board)
{
    /* Look at the current state of the board 
    and evaluate it by giving it a score. */
    int score = evaluate(board); 
    if (score != 0) { return score; }

    /* If the board is filled then we can't assign 
    a score and thus ends in a draw */
    if (board.filled()) { return 0; }
    
    if (ismin)
    {
        /* Traverse through all the positions  */
    }
    
}

int optimalMove(Board board)
{
    
}