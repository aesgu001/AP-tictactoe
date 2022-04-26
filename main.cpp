#include <iostream>

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

    for (int i = 0; i < 9; ++i)
    {
        std::cout << " " << gameBoard[i] << " |";
        if ((i + 1) % 3 == 0)
        {
            std::cout << "\n------------\n";
        }
    }
    std::cout << "\n";

    std::cout << "Player One: " << playerOne << ", Player Two: " << playerTwo << "\n";
    return 0;
}