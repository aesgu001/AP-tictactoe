#include "ttt-main.h"

int enterOption(int numOptions)
{
    int option = 0;

    std::cout << "Enter option: ";
    while (true)
    {
        std::cin >> option;
        if (option <= 0 || option > numOptions)
        {
            std::cout << "ERROR! Please enter a valid option: ";
        }
        else
        {
            break;
        }
    }   
    std::cout << "\n";

    return option;
}

void displayGameBoard(char gameBoard[], int boardSize)
{
    for (int i = 0; i < boardSize; ++i)
    {
        std::cout << " " << gameBoard[i] << " |";      
        if ((i + 1) % 3 == 0)
        {
            std::cout << "\n------------\n";
        }
    }
    std::cout << "\n";
}

int enterBoardPosition(char gameBoard[], char currPlayer, int boardSize)
{
    int position = 0;
    bool badInput = true;

    std::cout << "Player " << currPlayer << ", enter a position (1 - " << boardSize << "): ";  
    while (badInput)
    {
        badInput = false;
        std::cin >> position;

        if (position <= 0 || position > boardSize ||
            gameBoard[position - 1] != static_cast<char>(position + 48))
        {
            badInput = true;
            std::cout << "ERROR! Please enter a valid position: ";
        }
    }
    std::cout << "\n";

    return position;
}

int main()
{
    while (true)
    {
        int modeOption = 0;
        int playerOption = 0;
        int gameOverOption = 0;

        char gameBoard[9]
        {
            '1', '2', '3',
            '4', '5', '6',
            '7', '8', '9'
        };

        char playerOne = 'X';
        char playerTwo = 'O';
        char currPlayer = playerTwo;
        char currOpponent = playerOne;

        bool isPCOne = false;
        bool isPCTwo = false;
        bool currIsPC = isPCTwo;
        bool matchFound = false;
        
        std::cout << "SELECT MODE\n"
            << "(1) Player vs AI\n"
            << "(2) Player vs. Player\n\n";
        modeOption = enterOption(2);
        if (modeOption == 1)
        {
            std::cout << "SELECT PLAYER\n"
                << "(1) Player " << playerOne << "\n"
                << "(2) Player " << playerTwo << "\n\n";
            playerOption = enterOption(2);
            if (playerOption == 1)
            {
                isPCOne = true;
            }
            else
            {
                isPCTwo = true;
            }
        }
        else
        {
            isPCOne = true;
            isPCTwo = true;
        }

        while (true)
        {
            int boardPos = 0;

            displayGameBoard(gameBoard, 9);

            if (currPlayer == playerOne)
            {
                currPlayer = playerTwo;
                currOpponent = playerOne;
                currIsPC = isPCTwo;
            }
            else
            {
                currPlayer = playerOne;
                currOpponent = playerTwo;
                currIsPC = isPCOne;
            }

            if (currIsPC)
            {
                boardPos = enterBoardPosition(gameBoard, currPlayer, 9);
            }
            else
            {
                boardPos = findOptimalPosition(gameBoard, currPlayer, currOpponent, 9);
                std::cout << "Player " << currPlayer << "'s Turn: " << boardPos << "\n\n";
            }
            gameBoard[boardPos - 1] = currPlayer;

            matchFound = rowMatch(gameBoard, currPlayer, 9) || columnMatch(gameBoard, currPlayer, 9) ||
                diagonalMatch(gameBoard, currPlayer, 9);
            if (matchFound || noMoreMoves(gameBoard, 9))
            {
                break;
            }
        }

        displayGameBoard(gameBoard, 9);

        if (matchFound)
        {
            std::cout << "Player " << currPlayer << " WINS!\n\n";
        }
        else
        {
            std::cout << "It's a DRAW!\n\n";
        }

        std::cout << "GAME OVER\n"
            << "(1) Restart\n"
            << "(2) Quit\n\n";
        gameOverOption = enterOption(2);
        if (gameOverOption == 2)
        {
            break;
        }      
    }

    return 0;
}