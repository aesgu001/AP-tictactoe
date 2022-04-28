#pragma once

#include "tictactoe-rules.h"

#include <algorithm>    // std::max, std::min
#include <climits>      // INT_MAX, INT_MIN

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
    int alpha, int beta);

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
int findOptimalPosition(char gameBoard[], char currPlayer, char currOpponent, int boardSize);