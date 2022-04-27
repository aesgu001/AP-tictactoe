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

/*
*	Chooses the best possible position, after evaluating the
*	current board.
*
*	@param	gameBoard   the current game board.
*	@param  currPlayer  the player with the turn.
*	@param  boardSize   the game board's size.
*
*	@return A valid, optimal board position.
*/
int findOptimalPosition(char gameBoard[], char currPlayer, int boardSize)
{
    int position = 0;

    // TODO: evaluate position
    for (int i = 0; i < boardSize; ++i)
    {
        if (gameBoard[i] == static_cast<char>(i + 1 + 48))
        {
            position = i;
            break;
        }
    }

    return position + 1;
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

/*
*	Checks if the current player has made a column match.
*
*   @param  gameBoard   the current game board.
*	@param  currPlayer  the player with the turn.
*	@param  boardSize   the game board's size.
*
*	@return  True if three consistent marks are found.
*/
bool columnMatch(char gameBoard[], char currPlayer, int boardSize)
{
    int count = 0;
    int i = 0;
    int j = 0;

    while (j < boardSize / 3)
    {
        if (gameBoard[i + j] == currPlayer)
        {
            if (++count >= 3)
            {
                return true;
            }

            i += 3;
        }
        else
        {
            count = 0;
            i = 0;
            j++;
        }
    }

    return false;
}

/*
*	Checks if the current player has made a diagonal match.
*
*   @param  gameBoard   the current game board.
*	@param  currPlayer  the player with the turn.
*	@param  boardSize   the game board's size.
*
*	@return  True if three consistent marks are found.
*/
bool diagonalMatch(char gameBoard[], char currPlayer, int boardSize)
{
	int count = 0;
	int i = 0;
	int j = 0;

	// Move 1 space down, 1 space right
	while (i < boardSize)
	{
		if (gameBoard[i + j] == currPlayer)
		{
			if (++count >= 3)
			{
				return true;
			}

			i += 3;
			j++;
		}

		// Setup iterators for the upward match check
		else
		{
			count = 0;
			i = boardSize - 3;
			j = 0;

			break;
		}
	}

	// Move 1 space up, 1 space right
	while (i >= 0)
	{
		if (gameBoard[i + j] == currPlayer)
		{
			if (++count >= 3)
			{
				return true;
			}

			i -= 3;
			j++;
		}
		else
		{
			break;
		}
	}

	return false;
}

/*
*	Checks if there are no more moves available.
*
*   @param  gameBoard   the current game board.
*	@param  boardSize   the game board's size.
*
*	@return  True if there are no numbered positions.
*/
bool noMoreMoves(char gameBoard[], int boardSize)
{
    for (int i = 0; i < boardSize; i++)
	{
		if (gameBoard[i] == static_cast<char>(i + 1 + 48))
		{
			return false;
		}
	}

	return true;
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

    bool isPCOne = true;
    bool isPCTwo = false;

    bool repeatGame = true;
    while (repeatGame)
    {
        for (int i = 0; i < 9; ++i)
        {
            gameBoard[i] = i + 1 + 48;
        }
        char currPlayer = playerTwo;
        bool currIsPC = isPCTwo;

        bool matchFound = false;

        while (true)
        {
            displayGameBoard(gameBoard, 9);

            matchFound = rowMatch(gameBoard, currPlayer, 9) || columnMatch(gameBoard, currPlayer, 9) ||
                diagonalMatch(gameBoard, currPlayer, 9);
            if (matchFound || noMoreMoves(gameBoard, 9))
            {
                break;
            }

            if (currPlayer == playerOne)
            {
                currPlayer = playerTwo;
                currIsPC = isPCTwo;
            }
            else
            {
                currPlayer = playerOne;
                currIsPC = isPCOne;
            }

            int boardPos = 0;
            if (currIsPC)
            {
                boardPos = enterBoardPosition(gameBoard, currPlayer, 9);
            }
            else
            {
                boardPos = findOptimalPosition(gameBoard, currPlayer, 9);
                std::cout << "Player " << currPlayer << "'s Turn: " << boardPos << "\n\n";
            }
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

        int choice = 0;
        std::cout << "Game Over (1: Restart, 2: Quit): ";
        std::cin >> choice;
        if (choice == 1)
        {
            repeatGame = true;
        }
        else
        {
            repeatGame = false;
        }
        std::cout << "\n";
        
    }

    return 0;
}