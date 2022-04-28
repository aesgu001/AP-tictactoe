/*
*	Checks if the current player has made a row match on the game board.
*
*   @param  gameBoard   the current game board.
*	@param  currPlayer  the player with the turn.
*	@param  boardSize   the game board's size.
*
*	@return  True if three consistent marks are found.
*/
bool rowMatch(char gameBoard[], char currPlayer, int boardSize);

/*
*	Checks if the current player has made a column match on the game board.
*
*   @param  gameBoard   the current game board.
*	@param  currPlayer  the player with the turn.
*	@param  boardSize   the game board's size.
*
*	@return  True if three consistent marks are found.
*/
bool columnMatch(char gameBoard[], char currPlayer, int boardSize);

/*
*	Checks if the current player has made a diagonal match on the game board.
*
*   @param  gameBoard   the current game board.
*	@param  currPlayer  the player with the turn.
*	@param  boardSize   the game board's size.
*
*	@return  True if three consistent marks are found.
*/
bool diagonalMatch(char gameBoard[], char currPlayer, int boardSize);

/*
*	Checks if there are no more moves available on the game board.
*
*   @param  gameBoard   the current game board.
*	@param  boardSize   the game board's size.
*
*	@return  True if there are no numbered positions on the game board.
*/
bool noMoreMoves(char gameBoard[], int boardSize);