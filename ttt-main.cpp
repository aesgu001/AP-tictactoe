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

void selectModeAndPlayer(char playerOne, char playerTwo, bool &isPCOne, bool &isPCTwo)
{
    std::cout << "SELECT MODE\n"
        << "(1) Player vs AI\n"
        << "(2) Player vs. Player\n\n";
    if (enterOption(2) == 1)
    {
        std::cout << "SELECT PLAYER\n"
            << "(1) Player " << playerOne << "\n"
            << "(2) Player " << playerTwo << "\n\n";
        if (enterOption(2) == 1)
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

void markGameBoard(char gameBoard[], char currPlayer, char currOpponent, bool currIsPC, int boardSize)
{
    int boardPos = 0;

    if (currIsPC)
    {
        std::cout << "Player " << currPlayer << ", enter a position (1 - " << boardSize << "): ";  
        while (true)
        {
            std::cin >> boardPos;
            if (boardPos <= 0 || boardPos > boardSize ||
                gameBoard[boardPos - 1] != static_cast<char>(boardPos + 48))
            {
                std::cout << "ERROR! Please enter a valid position: ";
            }
            else
            {
                break;
            }
        }
        std::cout << "\n";
    }
    else
    {
        boardPos = findOptimalPosition(gameBoard, currPlayer, currOpponent, boardSize);
        std::cout << "Player " << currPlayer << "'s turn: " << boardPos << "\n\n";
    }

    gameBoard[boardPos - 1] = currPlayer;
}

void declareGameResult(char gameBoard[], char currPlayer, bool matchFound, int boardSize)
{
    displayGameBoard(gameBoard, boardSize);

    if (matchFound)
    {
        std::cout << "Player " << currPlayer << " WINS!\n\n";
    }
    else
    {
        std::cout << "It's a DRAW!\n\n";
    }
}

bool restartGame()
{
    std::cout << "GAME OVER\n"
        << "(1) Restart\n"
        << "(2) Quit\n\n";
    
    return enterOption(2) == 1;
}

int main()
{
    while (true)
    {
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
        
        selectModeAndPlayer(playerOne, playerTwo, isPCOne, isPCTwo);

        while (true)
        {
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

            markGameBoard(gameBoard, currPlayer, currOpponent, currIsPC, 9);

            matchFound = findMatch(gameBoard, currPlayer, 9);
            if (matchFound || noMoreMoves(gameBoard, 9))
            {
                break;
            }
        }

        declareGameResult(gameBoard, currPlayer, matchFound, 9);

        if (!restartGame())
        {
            break;
        }
    }

    return 0;
}