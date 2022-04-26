#include <iostream>

/*
*  Writes the current game board to standard output.
*
*  @param   gameBoard the game board to display.
*  @param   boardSize the game board's size.
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

    displayGameBoard(gameBoard, 9);

    std::cout << "Player One: " << playerOne << ", Player Two: " << playerTwo << "\n";
    return 0;
}