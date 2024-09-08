Checkers Game
This repository contains the source code for a simple implementation of the Checkers (Draughts) game in C. The game is played in the console, and it follows the standard rules of Checkers.

File Description
Checkers game.c: This is the main source file that contains all the code necessary to run the Checkers game. It includes functions for initializing the game, handling player moves, updating the board, and determining the winner.
How to Compile and Run
Compile the Code: To compile the Checkers game.c file, use a C compiler like gcc. Open your terminal or command prompt and run the following command:

bash
Copy code
gcc -o checkers Checkers\ game.c
This will create an executable file named checkers.

Run the Game: After compiling, you can run the game by executing the following command in your terminal:

bash
Copy code
./checkers
Game Rules
The game is played on an 8x8 board.
Two players take turns moving their pawns ('X' and 'O') on the board.
Pawns can move diagonally forward to an empty square.
If a pawn can jump over an opponent's pawn, it captures that pawn.
The game ends when one player captures all of the opponent's pawns or no legal moves are available.
Players can quit the game by entering 999 as input.

Gameplay Instructions
Each player is prompted to enter the location of their pawn and its desired destination.
The game checks the legality of the move.
If the move is legal, the pawn is moved. If the move results in a capture, the opponent's pawn is removed from the board.
The game continues until one player wins or a player decides to quit.

Input Format
Enter the row and column number for the pawn you want to move.
Enter the row and column number for the destination you want to move the pawn to.

Conclusion
This project is a simple demonstration of how to implement the classic Draughts game using C. It includes core game mechanics, input validation, and turn-based logic for two-player gameplay.

