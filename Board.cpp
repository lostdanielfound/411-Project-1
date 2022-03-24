#include <iostream>
#include "Board.h"

Board::Board(int dimension)
{
    board = new char *[dimension];

    for (int i = 0; i < dimension; i++)
    {
        /* Making the two dimension array */
        board[i] = new char[dimension];
    }

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            /* Filling the 2d array with '-' */
            board[i][j] = '-';
        }
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
    std::cout << "----Turn  " << turnCount << "----\n";
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
    std::cout << "---------------\n\n";
}

/**
 * @brief Inserts the players symbol X or O 
 * into the board at position from 1-9
 * | 1 | 2 | 3 |
 * | 4 | 5 | 6 |
 * | 7 | 8 | 9 | 
 * @param position The placement of the symbol within the board
 * @param symbol The symbol of the player
 * @return int status of attempted Insert
 */
int Board::Insert(int position, char symbol)
{
    if (position > 9 || position < 1)
    {
        /* Out of bounds checking */
        std::cout << "\nIllegal move, please try a different spot...\n";
        return -1; 
    }

    if (position >= 1 && position <= 3)
    {
        /* Inserting in the first row */
        if (board[0][position - 1] != '-')
        {
            /* There is already something there, ILLEGAL MOVE */
            std::cout << "\nIllegal move, please try a different spot...\n";
            return -1;
        }
        
        board[0][position - 1] = symbol;
        turnCount++;
    } 
    else if (position >= 4 && position <= 6)
    {
        /* Inserting in the second row */
        if (board[1][(position % 4)] != '-')
        {
            /* There is already something there, ILLEGAL MOVE */
            std::cout << "\nIllegal move, please try a different spot...\n";
            return -1;
        }

        board[1][(position % 4)] = symbol; 
        turnCount++;
    }
    else if (position >= 7 && position <= 9)
    {
        /* Inserting in the thrid row */
        if (board[2][(position % 6) - 1] != '-')
        {
            /* There is already something there, ILLEGAL MOVE */
            std::cout << "\nIllegal move, please try a different spot...\n";
            return -1;
        }
        
        board[2][(position % 6) - 1] = symbol;
        turnCount++;
    }

    return 0;
}

void Board::reset()
{
    turnCount = 0; 
    //board = {"", "", "",
    //        "", "", "",
    //        "", "", ""};
}

bool Board::CheckState()
{
    for (int i = 0; i < dimension; i++)
    {
        if ((board[i][0] == board[i][1] && (board[i][0] != '-')) && board[i][0] == board[i][2])
        {
            /* Check the rows of the board to see if someone won */
            return true; 
        }
        else if ((board[0][i] == board[1][i] && (board[0][i] != '-')) && board[0][i] == board[2][i])
        {
            /* Check the columns of the board to see if someone won */
            return true; 
        }
    }


    if ((board[0][0] == board[1][1] && (board[0][0] != '-')) && board[0][0] == board[2][2])
    {
        /* Checking left diagonals now */
        return true;
    }
    else if ((board[0][2] == board[1][1] && (board[0][2] != '-')) && board[0][2] == board[2][0])
    {
        /* Checking right diagonals now */
        return true; 
    }
    
    return false; //No winner yet   
}