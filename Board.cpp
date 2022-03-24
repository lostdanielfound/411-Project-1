#include <iostream>
#include <iomanip> 
#include "Board.h"

Board::Board(int dimension)
{
    board = new char *[dimension];

    /* Making the two dimension array */
    for (int i = 0; i < dimension; i++) { board[i] = new char[dimension]; }

    for (int i = 0; i < dimension; i++)
    {
        /* Filling the 2d array with '-' */
        for (int j = 0; j < dimension; j++) { board[i][j] = '-'; }
    }

    this->dimension = dimension; 
}

Board::~Board()
{
    for (int i = 0; i < dimension; i++) { delete [] board[i]; } 
    delete [] board; 
}



/**
 * @brief Simply draws out the current state of the 
 * tic-tac-toe board by references the players moves 
 * through the board[][] matrix.
 * 
 * Example: 
 * ----Turn  2----
 * | X | O | X |
 * | X | X | O |
 * | O | X | X | 
 * ---------------
 */
void Board::Draw()
{
    //std::cout << "----Turn  " << turnCount << "----\n";
    std::cout << "Turn " << turnCount << "\n";
    std::cout << std::setfill('-') << std::setw(dimension*5) << "-\n"; 
    for (int i = 0; i < dimension; i++)
    {
        std::cout << "|";
        for (int j = 0; j < dimension; j++)
        {
            if (board[i][j] == '-')
            {
                std::cout << " " << " " << " " << "|";
            }
            else
            {
                std::cout << " " << board[i][j] << " " << "|";
            }
        }
        std::cout << "\n";
    }
    std::cout << std::setfill('-') << std::setw(dimension*5) << "-\n"; 
}

/**
 * @brief Inserts the players symbol X or O 
 * into the 3x3 board at position from 1-9
 * | 1 | 2 | 3 |
 * | 4 | 5 | 6 |
 * | 7 | 8 | 9 | 
 * 
 * Or, given a nxn board, the position marks will 
 * follow the this pattern
 * 
 * | 1 | 2 | 3 | 4 | 5 | ... | n | 
 * |n-i| (i being the last index value above current index)
 * |n-(n-i)| 
 * |...| 
 * |...| 
 * |...| 
 * |n*n - n|                 | n*n | 
 * 
 * sadly for the worst case runtime is O(n^2) but can DEFINITLY BE IMPROVED!
 * 
 * @param position The placement of the symbol within the board
 * @param symbol The symbol of the player
 * @return int status of attempted Insert
 */
int Board::Insert(int position, char symbol)
{
    if (position > (dimension * dimension) || position < 1)
    {
        /* Out of bounds checking */
        std::cout << "\nIllegal move, please try a different spot...\n";
        return -1; 
    }

    for (int i = 0; i < dimension; i++)
    {
        /* Traveling through each row in order to find the position */
        for (int j = 0; j < dimension; j++)
        {
            /* Traveling through each cell within a row 
            in order to find the position */

            /* If we are not at the position yet
            then keep going until we are */

            if (--position == 0)
            {
                //We have arrived at the position
                if (board[i][j] != '-')
                {
                    /* Check to see if the position is already taken */
                    std::cout << "\nIllegal move, please try a different spot...\n";
                    return -1; 
                }
                else
                {
                    /* We found an empty spot! */
                    board[i][j] = symbol;
                    turnCount++;

                    return 0;
                }
            }   
        }
    }
    
    return -1; /* This should never execute... Reason could be out of bounds */
}

void Board::reset()
{
    turnCount = 0; 
}

/**
 * @brief After every turn, state of the board should be checked
 * to see IF a player has won. 
 * 
 * First, rows are checked by scanning each row cell with the first cell 
 * within the row. 
 * 
 * Second, columns are checked by the same method as rows. 
 * 
 * third, left diagonals are checked
 * 
 * last, right diagonals are checked
 * 
 * Best runtime case is O(n) :)
 * Average runtime case is O(n^2) :(
 * (This can be much better)
 * 
 * @return true, if player of last turn has a winning state 
 * @return false, if player of last turn doesn't have a winning state
 */
bool Board::CheckState()
{
    int count = 0; 

    //Checking rows
    for (int i = 0; i < dimension; i++)
    {
        /* increment count if we found a match */
        for (int j = 1; j < dimension; j++) 
        { 
            if (board[i][0] == board[i][j] && (board[i][0] != '-')) { count++; } 
        }
        if (count == dimension-1) { return true; } //We have a winner!
        count = 0;
    }

    //Checking Columns
    for (int i = 0; i < dimension; i++)
    {
        /* increment count if we found a match */
        for (int j = 1; j < dimension; j++) 
        { 
            if (board[0][i] == board[i][j] && (board[0][i] != '-')) { count++; } 
        }
        if (count == dimension-1) { return true; } //We have a winner!
        count = 0;
    }

    //Checking left diagonals 
    for (int i = 1; i < dimension; i++)
    {
        /* increment count if we found a match */
        if (board[0][0] == board[i][i] && (board[0][0] != '-')) { count++; }
    }
    if (count == dimension-1) { return true; }
    count = 0;

    //Checking right diagonals 
    for (int i = 1; i < dimension; i++)
    {
        /* increment count if we found a match */
        if (board[0][dimension-1] == board[i][dimension-i-1] && (board[0][dimension-1] != '-')) { count++; }
    }
    if (count == dimension-1) { return true; }
    count = 0;
    
    return false; //No winner yet   
}