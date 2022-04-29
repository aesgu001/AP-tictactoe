#pragma once

#include "ttt-ai.h"
#include "ttt-rules.h"

#include <iostream> // std::cin/cout

/*
*  Reads user option from standard input.
*
*  @param   numOptions   the number of possible options.
*
*  @return  A valid option.
*/
int enterOption(int);

/*
*   Selects the game mode and players to control from user input.
*
*   @param  playerOne   the player X.
*   @param  playerTwo   the player O.
*   @param  isPCOne     is player X user controlled?
*   @param  isPCTwo     is player O user controlled?
*
*   @return  None.
*/
void selectModeAndPlayer(char, char, bool &, bool &);

/*
*  Writes the current game board to standard output.
*
*  @param   gameBoard   the game board to display.
*  @param   boardSize   the game board's size.
*
*  @return  None.
*/
void displayGameBoard(char[], int);

/*
*   Specifies a board position and marks it. If the player is AI controlled, finds the best possible
*   position after evaluating the current board.
*
*   @param  gameBoard       the current game board.
*   @param  currPlayer      the player with the turn.
*   @param  currOpponent    the opposing player.
*   @param  currIsPC        is current player user controlled? 
*   @param  boardSize       the game board's size.
*
*   @return  None.
*/
void markGameBoard(char[], char, char, bool, int);

/*
*   Displays the final state of the game board. Also announces the winner or that the game ended 
*   in a tie.
*
*   @param  gameBoard   the game board.
*   @param  currPlayer  the potential winner.
*   @param  matchFound  is there a winning match?
*   @param  boardSize   the game board's size.
*
*   @return None.
*/
void declareGameResult(char[], char, bool, int);

/*
*   Restarts the game with another round.
*
*   @return True if user enters 1 when prompted.
*/
bool restartGame();