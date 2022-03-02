#include <iostream> 
#include "Board.h"
#include "Player.h"

void Introduction(Player*, Player*);
int Turn(Player*, Player*);

int main()
{

    Board playingBoard;
    Player *player1 = new Player();
    Player *player2 = new Player();
    player2->priority = false; 

    Introduction(player1, player2);

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

    return 0; 
}

void Introduction(Player* p1, Player* p2) 
{
    int choice = -1; 
    std::cout << "-----Tic-Tac-Toe-----\n";
    std::cout << "Welcome to the Tic-Tac-Toe game,\nPlayer 1 please choose you symbol.\n";
    std::cout << "\t1 for X\t2 for O\n:";
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

    return;
}

int Turn(Player* p1, Player* p2)
{
    int pos = -1; 

    if (p1->priority)
    {
        /* If p1 goes first */
        std::cout << "Player 1, Please pick a spot between 1-9 on the board: ";
        std::cin >> pos; 
    }
    else
    {
        std::cout << "Player 2, Please pick a spot between 1-9 on the board: ";
        std::cin >> pos;
    }
    
    return pos; 
}