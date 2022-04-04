/**
 * @file TicTacToe.cpp
 * @author Daniel Guzman (danielsonguzman2000@gmail.com)
 * @brief Main file for TicTacToe application
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * 
 * To run tests against this program please pick a test.in file from 
 * either the tests_ai or tests_noai folder. 
 * 
 * Picking a test.in file from the tests_ai folder will test 
 * the program with an A.i acting as the oppenent
 * 
 * Picking a test.in file from the tests_noai folder will test
 * the program allowing two players to play Tic Tac Toe with 
 * each other. 
 * 
 * To run the test you would need to "pipe" the input 
 * into the program. 
 * 
 * Linux example: 
 * ./TicTacToe < /tests_noai/test1.in  
 * ./TicTacToe < /tests_ai/test2.in 
 * 
 */

#include <iostream> 
#include "Board.h"
#include "Player.h"
#include "A.i_helper_functions.h"

int Introduction(Player*, Player*);
int Turn(Player*, Player*);

Player *player1 = new Player();
Player *player2 = new Player();

Board playingBoard(Introduction(player1, player2));

int main()
{

    while (1)
    {
        /* player1 should go first */
        playingBoard.Draw();
        if (playingBoard.Insert(Turn(player1, player2), (player1->priority == true ? player1->symbol : player2->symbol)) == 0)
        {
            if (playingBoard.CheckState())
            {
                /* The last player that inserted has just won the game! */
                playingBoard.Draw();
                std::cout << "Player " << (player1->priority == true ? "1" : "2") << " is the Winner!\n";
                break; 
            }
            else if (playingBoard.filled())
            {
                /* Playing board is all out of position 
                so thus it's a game over */
                playingBoard.Draw();
                std::cout << "Draw! Game Over\n";
                break; 
            }
            
            if (player1->priority == true)
            {
                /* switching turns */
                player1->priority = false; 
                player2->priority = true; 
            }
            else
            {
                player1->priority = true; 
                player2->priority = false; 
            }
            
        } 
    }

    delete player1; 
    delete player2; 

    return 0; 
}

int Introduction(Player* p1, Player* p2) 
{
    p2->priority = false; 

    int choice = -1; 
    char c; 
    std::cout << "\t-----Tic-Tac-Toe-----\n";
    std::cout << "\tWelcome to the Tic-Tac-Toe game,\n\tPlayer 1 please choose you symbol.\n";
    std::cout << "\t1 for X\t2 for O\n\t: ";
    std::cin >> choice;

    if (choice == 1)
    {
        /* Player 1 chooses X and player 2 gets O */
        p1->symbol = 'X';
        p2->symbol = 'O';
    }
    else 
    {
        p1->symbol = 'O';
        p2->symbol = 'X';
    }

    std::cout << "\n\tWould you like to have Player 2 as an A.I?\n\tY or N: ";
    std::cin >> c; 

    /* Yes to playing with an A.I :D */
    if (std::toupper(c) == 'Y') { p2->ai = true; }
    

    /* Getting the N dimension of the playboard */
    std::cout << "\n\tNow please enter the playboard's dimension\n\tyou would want to play in the game in.\n\t: ";
    std::cin >> choice; 
    std::cout << "\n";

    return choice;
}

int Turn(Player* p1, Player* p2)
{
    int pos = -1; 

    if (p1->priority)
    {
        /* If p1 goes first */
        std::cout << "Player 1, Please pick a spot between on the board: ";
        std::cin >> pos; 
    }
    else
    {
        /* Player 2 picks position here, this is the point of interaction 
        for the A.i. From here the A.I should be able to determine the best 
        move possible and select that to be the move. */
        std::cout << "Player 2, Please pick a spot between on the board: ";
        if (p2->ai)
        {
            /* A.i's turn to pick position */
            pos = optimalMove(playingBoard, p2->symbol);
        }
        else
        {
            std::cin >> pos;
        }
        
    }
    
    return pos; 
}