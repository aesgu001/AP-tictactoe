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
    // char playerTwo = 'O';
    char currPlayer = playerOne;

    displayGameBoard(gameBoard, 9);

    int boardPos = 0;
    bool badInput = true;

    std::cout << "Player " << currPlayer << ", enter a board position <1 - 9>: ";
    while (badInput)
    {
        badInput = false;
        std::cin >> boardPos;

        if (boardPos <= 0 || boardPos > 9 ||
            gameBoard[boardPos - 1] != static_cast<char>(boardPos + 48))
        {
            badInput = true;
            std::cout << "ERROR! Please enter a valid position: ";
        }
    }  

    std::cout << "\n";
    return 0;
}