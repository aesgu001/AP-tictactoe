# AP-tictactoe
A standard Tic-Tac-Toe program developed using C++. Players *X* and *O* take turns marking the 3 x 3 board, and whoever first makes a row, column, or diagonal match wins
the game. To place a mark, simply enter a number on the terminal to specify which free space on the board to use.
## Game Modes
This program features two modes: **Player vs. AI** or **Player vs. Player**.
| Player vs. AI   | Player vs. Player |
| --- | --- |
| ![](https://github.com/aesgu001/AP-tictactoe/blob/main/Player%20vs%20AI.gif) | ![](https://github.com/aesgu001/AP-tictactoe/blob/main/Player%20vs%20Player.gif) |

**Player vs. Player** is a straightforward game of wits between two human players.
### Unbeatable AI
**Player vs. AI** sets users against an AI that makes decisions for the non-controlled player. The AI applies the [minimax algorithm](https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/?ref=lbp)
to optimize each move, becoming an unbeatable opponent. However, the algorithm requires evaluating all possible states of the game board, meaning it has to check
**all 549945 of them** just to determine its first move! One possible solution to address this issue is by implementing the [alpha-beta pruning algorithm](https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-4-alpha-beta-pruning/).
| Without Alpha-Beta Pruning | With Alpha-Beta Pruning |
| --- | --- |
| ![](https://github.com/aesgu001/AP-tictactoe/blob/main/Minimax.gif) | ![](https://github.com/aesgu001/AP-tictactoe/blob/main/Alpha-Beta%20Pruning.gif) |

As shown above, the alpha-beta pruning algorithm significantly reduced the number of searches for its first move roughly **by 90%!**
## Build
**Note**: The GNU C++ compiler package must be installed in order to generate the application.

Building and running this program takes 5 easy steps using the Linux terminal:
```
git clone https://github.com/aesgu001/AP-tictactoe.git
cd AP-tictactoe
git checkout v1-00
make
./AP-tictactoe
```
