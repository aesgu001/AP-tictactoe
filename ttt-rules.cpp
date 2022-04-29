#include "ttt-rules.h"

bool rowMatch(char gameBoard[], char currPlayer, int boardSize)
{
    int count = 0; // Three instances make a winning match
    int i = 0;     // Board iterator by row
    int j = 0;     // Board iterator by column

    while (i < boardSize / 3)
    {
        if (gameBoard[(i * 3) + j] == currPlayer)
        {
            if (++count >= 3)
            {
                return true;
            }

            ++j;
        }
        else
        {
            count = 0;
            ++i;
            j = 0;
        }
    }

    return false;
}

bool columnMatch(char gameBoard[], char currPlayer, int boardSize)
{
    int count = 0;
    int i = 0;
    int j = 0;

    while (j < boardSize / 3)
    {
        if (gameBoard[(i * 3) + j] == currPlayer)
        {
            if (++count >= 3)
            {
                return true;
            }

            ++i;
        }
        else
        {
            count = 0;
            i = 0;
            ++j;
        }
    }

    return false;
}

bool diagonalMatch(char gameBoard[], char currPlayer, int boardSize)
{
	int count = 0;
	int i = 0;
	int j = 0;

	// Move 1 space down, 1 space right
	while (i < boardSize / 3)
	{
		if (gameBoard[(i * 3) + j] == currPlayer)
		{
			if (++count >= 3)
			{
				return true;
			}

			++i;
			++j;
		}

		// Setup iterators for the upward match check
		else
		{
			count = 0;
			i = (boardSize / 3) - 1;
			j = 0;

			break;
		}
	}

	// Move 1 space up, 1 space right
	while (i >= 0)
	{
		if (gameBoard[(i * 3) + j] == currPlayer)
		{
			if (++count >= 3)
			{
				return true;
			}

			--i;
			++j;
		}
		else
		{
			break;
		}
	}

	return false;
}

bool findMatch(char gameBoard[], char currPlayer, int boardSize)
{
	return rowMatch(gameBoard, currPlayer, boardSize) || columnMatch(gameBoard, currPlayer, boardSize) ||
		diagonalMatch(gameBoard, currPlayer, boardSize);
}

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