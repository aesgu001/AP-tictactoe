#include <iostream>

/*
*  Reads user option from standard input.
*
*  @param   numOptions   the number of possible options.
*
*  @return  A valid option.
*/
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

/*
*	Iterates through all possible states on the current game board until the end state is reached.
*   Then backtracks, returning the best (or worst) possible score.
*
*	@param	gameBoard   the current gameboard.
*	@param	boardSize   the game board's size.
*	@param	depth       the current search depth.
*	@param	player      the maximizer.
*	@param	opponent    the minimizer.
*   @param  isMax       determines the next player.
*   @param  alpha       value to compare for pruning.
*   @param  beta        value to compare for pruning.
*
*	@return The highest score (as maximizer) or lowest score (as minimizer).
*/
int evaluatePosition(char gameBoard[], int boardSize, int depth, char player, char opponent, bool isMax,
    int alpha, int beta)
{
    if (rowMatch(gameBoard, player, boardSize) || columnMatch(gameBoard, player, boardSize) ||
        diagonalMatch(gameBoard, player, boardSize))
    {
        return boardSize - depth;
    }
    else if (rowMatch(gameBoard, opponent, boardSize) || columnMatch(gameBoard, opponent, boardSize) ||
        diagonalMatch(gameBoard, opponent, boardSize))
    {
        return depth - boardSize;
    }
    else if (noMoreMoves(gameBoard, boardSize))
    {
        return 0;
    }

    if (isMax)
    {
        int maxScore = INT32_MIN;
        for (int i = 0; i < boardSize; ++i)
        {
            if (gameBoard[i] == static_cast<char>(i + 1 + 48))
            {
                gameBoard[i] = player;
                int score = evaluatePosition(gameBoard, boardSize, depth + 1, player, opponent, false,
                    alpha, beta);
                gameBoard[i] = static_cast<char>(i + 1 + 48);

                maxScore = std::max(score, maxScore);
                alpha = std::max(maxScore, alpha);
                if (beta <= alpha)
                {
                    break;
                }
            }
        }

        return maxScore;
    }
    else
    {
        int minScore = INT32_MAX;
        for (int i = 0; i < boardSize; ++i)
        {
            if (gameBoard[i] == static_cast<char>(i + 1 + 48))
            {
                gameBoard[i] = opponent;
                int score = evaluatePosition(gameBoard, boardSize, depth + 1, player, opponent, true,
                    alpha, beta);
                gameBoard[i] = static_cast<char>(i + 1 + 48);

                minScore = std::min(score, minScore);
                beta = std::min(minScore, beta);
                if (beta <= alpha)
                {
                    break;
                }
            }
        }

        return minScore;
    }
}

/*
*	Chooses the best possible position, after evaluating the current board.
*
*	@param	gameBoard       the current game board.
*	@param  currPlayer      the player with the turn.
*   @param  currOpponent    the opposing player.
*	@param  boardSize       the game board's size.
*
*	@return A valid, optimal board position.
*/
int findOptimalPosition(char gameBoard[], char currPlayer, char currOpponent, int boardSize)
{
    int position = 0;
    int maxScore = INT32_MIN;

    for (int i = 0; i < boardSize; ++i)
    {
        if (gameBoard[i] == static_cast<char>(i + 1 + 48))
        {
            gameBoard[i] = currPlayer;
            int score = evaluatePosition(gameBoard, boardSize, 0, currPlayer, currOpponent, false,
                INT32_MIN, INT32_MAX);
            gameBoard[i] = static_cast<char>(i + 1 + 48);

            if (score > maxScore)
            {
                maxScore = score;
                position = i;
            }
        }
    }

    return position + 1;
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

            matchFound = rowMatch(gameBoard, currPlayer, 9) || columnMatch(gameBoard, currPlayer, 9) ||
                diagonalMatch(gameBoard, currPlayer, 9);
            if (matchFound || noMoreMoves(gameBoard, 9))
            {
                break;
            }

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
        }
        
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