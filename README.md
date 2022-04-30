# AP-tictactoe
A standard Tic-Tac-Toe program developed using C++. Players 'X' and 'O' take turns marking the 3 X 3 board, and whoever first makes a row, column, or diagonal match wins
the game. To place a mark, simply enter a number on the terminal to specify which free space on the board to use.
## Game Modes
This program features two modes: **Player vs. AI** or **Player vs. Player**.
| Player vs. AI   | Player vs. Player |
| --- | --- |
| ![](https://github.com/aesgu001/AP-tictactoe/blob/main/Player%20vs%20AI.gif) | ![](https://github.com/aesgu001/AP-tictactoe/blob/main/Player%20vs%20Player.gif) |

The AI applies the minimax algorithm to optimize each move, becoming an unbeatable opponent.
With alpha-beta pruning, computing the first move is significantly reduced roughly by 90%!
| Without Alpha-Beta Pruning | With Alpha-Beta Pruning |
| --- | --- |
| ![](https://github.com/aesgu001/AP-tictactoe/blob/main/Minimax.gif) | ![](https://github.com/aesgu001/AP-tictactoe/blob/main/Alpha-Beta%20Pruning.gif) |
