#include "A.i_helper_functions.h"
#include <algorithm>
#include <limits.h>


/**
 * @brief A function to evaluate and score a current 
 * state of the board. The score of game state is calculated 
 * by counting the most amount of pieces lined up either within 
 * a row, column, or diagonal. 
 * 
 * @param board 
 * @return The min or max score of the board given the symbol of the player
 */
int evaluate(Board board, char symbol)
{
    int score;
    int tempscore = 0; 
    if (symbol == 'O') { score = INT_MAX; }
    else if (symbol == 'X') { score = INT_MIN; }

    //Checking rows
    for (int i = 0; i < board.dimension; i++)
    {
        /* increment count if we found a match */
        for (int j = 1; j < board.dimension; j++) 
        { 
            if (board.board[i][0] == board.board[i][j] && (board.board[i][0] != '-') && (symbol == 'O') && (board.board[i][0] == 'O')) { tempscore--; }
            else if (board.board[i][0] == board.board[i][j] && (board.board[i][0] != '-') && (symbol == 'X') && (board.board[i][0] == 'X')) { tempscore++; }
        }
        if (symbol == 'O') { score = std::min(score, tempscore); }
        else if (symbol == 'X') { score = std::max(score, tempscore); }

        tempscore = 0; 
    }

    //Checking Columns
    for (int i = 0; i < board.dimension; i++)
    {
        /* increment count if we found a match */
        for (int j = 1; j < board.dimension; j++) 
        { 
            if (board.board[0][i] == board.board[j][i] && (board.board[0][i] != '-') && (symbol == 'O') && (board.board[0][i] == 'O')) { tempscore--; } 
            else if (board.board[0][i] == board.board[j][i] && (board.board[0][i] != '-') && (symbol == 'X') && (board.board[0][i] == 'X')) { tempscore++; } 
        }
        if (symbol == 'O') { score = std::min(score, tempscore); }
        else if (symbol == 'X') { score = std::max(score, tempscore); }

        tempscore = 0; 
    }

    //Checking left diagonals 
    for (int i = 1; i < board.dimension; i++)
    {
        /* increment count if we found a match */
        if (board.board[0][0] == board.board[i][i] && (board.board[0][0] != '-') && (symbol == 'O') && (board.board[0][0] == 'O')) { tempscore--; }
        else if (board.board[0][0] == board.board[i][i] && (board.board[0][0] != '-') && (symbol == 'X') && (board.board[0][0] == 'X')) { tempscore++; }
    }
    if (symbol == 'O') { score = std::min(score, tempscore); }
    else if (symbol == 'X') { score = std::max(score, tempscore); }

    tempscore = 0; 

    //Checking right diagonals 
    for (int i = 1; i < board.dimension; i++)
    {
        /* increment count if we found a match */
        if (board.board[0][board.dimension-1] == board.board[i][board.dimension-i-1] && (board.board[0][board.dimension-1] != '-') && (symbol == 'O') && (board.board[0][board.dimension-1] == 'O')) { tempscore--; }
        else if (board.board[0][board.dimension-1] == board.board[i][board.dimension-i-1] && (board.board[0][board.dimension-1] != '-') && (symbol == 'X') && (board.board[0][board.dimension-1] == 'X')) { tempscore++; }
    }
    if (symbol == 'O') { score = std::min(score, tempscore); }
    else if (symbol == 'X') { score = std::max(score, tempscore); }
    
    return score;
    
}

/**
 * @brief minimax function that is to return the optimal
 * value the A.i can obtain when minimizing the gains of 
 * the game. 
 * 
 * @param ismin If True we are minimizing the game otherwise we are maximizing. 
 * @param board The current game board
 * @return the score of the node states 
 */
int minimax(bool ismin, Board board, char symbol)
{
    /* Look at the current state of the board 
    and evaluate it by giving it a score. */
    int score = evaluate(board, symbol); 
    if (score == (board.dimension-1) || score == -(board.dimension-1)) { return score; }

    /* If the board is filled then we can't assign 
    a score and thus ends in a draw */
    if (board.filled()) { return 0; }
    
    if (ismin)
    {
        /* Traverse through all the positions
        to find the best position to place. */
        int bestScore = INT_MAX;
        for (int i = 0; i < board.dimension; i++)
        {
            for (int j = 0; j < board.dimension; j++)
            {
                if (board.board[i][j] == '-')
                {
                    /* placed a psuedo piece on the board */
                    board.board[i][j] = symbol;

                    score = minimax(false, board, 'X');
                    bestScore = std::min(bestScore, score);

                    /* Remove the psuedo piece */
                    board.board[i][j] = '-'; 
                }
            }
        }
        return bestScore;
    }

    int bestScore = INT_MIN;
    for (int i = 0; i < board.dimension; i++)
    {
        for (int j = 0; j < board.dimension; j++)
        {
            if (board.board[i][j] == '-')
            {
                /* placed a psuedo piece on the board */
                board.board[i][j] = symbol; 

                score = minimax(true, board, 'O');
                bestScore = std::max(bestScore, score); 

                /* Remove the psuedo piece */
                board.board[i][j] = '-';
            }
        }
    }
    
    return bestScore;
}

int optimalMove(Board board, char symbol)
{
    int position = 1; //current position on the board
    int bestMove = 1; //optimal position on the board
    
    int score; 
    int bestScore;
    if (symbol == 'O') { bestScore = INT_MAX; } //Setting current bestScore if A.i is '0'
    else if (symbol == 'X') { bestScore = INT_MIN; } //Setting current bestScore if A.i is 'X'

    for (int i = 0; i < board.dimension; i++)
    {
        for (int j = 0; j < board.dimension; j++)
        {
            if (board.board[i][j] == '-')
            {
                /* Placing the inital (root) psuedo piece */
                board.board[i][j] = symbol; 

                score = minimax((symbol == 'O' ? false : true), board, (symbol == 'O' ? 'X' : 'O'));

                if (symbol == 'O')
                {
                    if (score < bestScore) { bestMove = position; }
                }
                else if (symbol == 'X')
                {
                    if (score > bestScore) { bestMove = position; }
                }
                
                /* Removing the root psuedo piece */
                board.board[i][j] = '-';
            }
            
            position++; 
        }
    }

    return bestMove; 
}