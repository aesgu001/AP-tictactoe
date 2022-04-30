#include "ttt-ai.h"

// static int numEval;  // Tracks the number of state evaluations.

int evaluatePosition(char gameBoard[], int boardSize, int depth, char player, char opponent, bool isMax,
    int alpha, int beta)
{
    // ++numEval;

    // Maximizer win condition
    if (!isMax && findMatch(gameBoard, player, boardSize))
    {
        return boardSize - depth;
    }
    // Minimizer win condition
    else if (isMax && findMatch(gameBoard, opponent, boardSize))
    {
        return depth - boardSize;
    }
    else if (noMoreMoves(gameBoard, boardSize))
    {
        return 0;
    }

    if (isMax)
    {
        int maxScore = INT_MIN;

        for (int i = 0; i < boardSize; ++i)
        {
            int score = 0;

            if (gameBoard[i] == static_cast<char>(i + 1 + 48))
            {
                gameBoard[i] = player;
                score = evaluatePosition(gameBoard, boardSize, depth + 1, player, opponent, false,
                    alpha, beta);
                gameBoard[i] = static_cast<char>(i + 1 + 48);

                maxScore = std::max(score, maxScore);
                alpha = std::max(maxScore, alpha);
                if (beta <= alpha)
                {
                    // Skip remaining iterations; beta guaranteed for minimizer
                    break;
                }
            }
        }

        return maxScore;
    }
    else
    {
        int minScore = INT_MAX;

        for (int i = 0; i < boardSize; ++i)
        {
            int score = 0;

            if (gameBoard[i] == static_cast<char>(i + 1 + 48))
            {
                gameBoard[i] = opponent;
                score = evaluatePosition(gameBoard, boardSize, depth + 1, player, opponent, true,
                    alpha, beta);
                gameBoard[i] = static_cast<char>(i + 1 + 48);

                minScore = std::min(score, minScore);
                beta = std::min(minScore, beta);
                if (beta <= alpha)
                {
                    // Skip remaining iterations; alpha guaranteed for maximizer
                    break;
                }
            }
        }

        return minScore;
    }
}

int findOptimalPosition(char gameBoard[], char currPlayer, char currOpponent, int boardSize)
{
    int position = 0;
    int maxScore = INT_MIN;
    // numEval = 0;

    for (int i = 0; i < boardSize; ++i)
    {
        int score = 0;

        if (gameBoard[i] == static_cast<char>(i + 1 + 48))
        {
            gameBoard[i] = currPlayer;
            score = evaluatePosition(gameBoard, boardSize, 0, currPlayer, currOpponent, false,
                maxScore, INT_MAX);
            gameBoard[i] = static_cast<char>(i + 1 + 48);

            if (score > maxScore)
            {
                maxScore = score;
                position = i;
            }
        }
    }

    // std::cout << "Number of state evaluations: " << numEval << "\n";

    return position + 1;
}