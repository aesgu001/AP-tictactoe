#pragma once

#include "ttt-ai.h"
#include "ttt-rules.h"

#include <iostream>

/*
*  Reads user option from standard input.
*
*  @param   numOptions   the number of possible options.
*
*  @return  A valid option.
*/
int enterOption(int numOptions);

/*
*  Writes the current game board to standard output.
*
*  @param   gameBoard   the game board to display.
*  @param   boardSize   the game board's size.
*
*  @return  None.
*/
void displayGameBoard(char gameBoard[], int boardSize);

/*
*  Reads a board position from standard input.
*
*  @param   gameBoard   the current game board.
*  @param   currPlayer  the player with the turn.
*  @param   boardSize   the game board's size.
*
*  @return  A valid board position.
*/
int enterBoardPosition(char gameBoard[], char currPlayer, int boardSize);