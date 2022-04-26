#include <iostream>

/*
*  Writes the current game board to standard output.
*
*  @param   gameBoard   the game board to display.
*  @param   boardSize   the game board's size.
*
*  @return  None.
*/
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

/*
*  Reads a board position from standard input.
*
*  @param   gameBoard   the current game board.
*  @param   currPlayer  the player with the turn.
*  @param   boardSize   the game board's size.
*
*  @return  A valid board position.
*/
int enterBoardPosition(char gameBoard[], char currPlayer, int boardSize)
{
    int position = 0;
    bool badInput = true;

    std::cout << "Player " << currPlayer << ", enter a position <1 - " << boardSize << ">: ";  
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

/*
*	Checks if the current player has made a row match.
*
*   @param  gameBoard   the current game board.
*	@param  currPlayer  the player with the turn.
*	@param  boardSize   the game board's size.
*
*	@return  True if three consistent marks are found.
*/
bool rowMatch(char gameBoard[], char currPlayer, int boardSize)
{
    int count = 0; // Three instances make a winning match
    int i = 0;     // Board iterator by row
    int j = 0;     // Board iterator by column

    while (i < boardSize)
    {
        if (gameBoard[i + j] == currPlayer)
        {
            if (++count >= 3)
            {
                return true;
            }

            j++;
        }
        else
        {
            count = 0;
            i += 3;
            j = 0;
        }
    }

    return false;
}

int main()
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
    bool matchFound = false;

    for (int i = 0; i < 9; ++i)
    {
        displayGameBoard(gameBoard, 9);

        matchFound = rowMatch(gameBoard, currPlayer, 9);
        if (matchFound)
        {
            break;
        }

        if (currPlayer == playerOne)
        {
            currPlayer = playerTwo;
        }
        else
        {
            currPlayer = playerOne;
        }

        int boardPos = enterBoardPosition(gameBoard, currPlayer, 9);
        gameBoard[boardPos - 1] = currPlayer;
    }
    
    if (matchFound)
    {
        std::cout << "Player " << currPlayer << " WINS!\n";
    }
    else
    {
        std::cout << "DRAW!\n";
    }

    return 0;
}