#include "Board.h"
#include <iostream>
//		system("CLS");

int main()
{
    // fix turn system - loop in figure function(pawn etc) not in main
    // change Step function from void to bool 
    // finish check - use check for mate
    int X = -1,Y; char rawX;
    Board board;
    while(!board.isMateBool)
    {
        board.skip = false;
        board.InitBoard();
        board.RefreshBoard();
        while (true)
        {
            //===

            std::cout << "\nEnter coordinate (row): ";
            std::cin >> Y;
            Y = 8 - Y;
            do {
                std::cout << "Enter coordinate (column): ";
                std::cin >> rawX;
                X = board.convertLetter(rawX);
            } while (X == -1);
            
            if (board.allFigures[Y][X].Symbol != 'E') {
                for (int y = 0;y < board.allFigures.length();y++)
                {
                    for (int x = 0;x < board.allFigures[y].length();x++)
                    {
                        if (board.allFigures[y][x].Symbol == 'E' && board.allFigures[y][x].Color == 'W' && board.activePlayer == true ||
                            board.allFigures[y][x].Symbol == 'E' && board.allFigures[y][x].Color == 'B' && board.activePlayer == false)
                        {
                            board.IsCheck({ x,y });
                            board.isMateBool = board.IsMate( {x,y} );
                            if (board.isMateBool) { break; }
                        }
                    }
                }
            }
            
            //===
            

            if (board.isCheckBool == false || board.allFigures[Y][X].Symbol == 'E') { break; }
            else { std::cout << "King is in danger!!!!"; }
        }

        board.doStep({ X, Y });
        board.RefreshBoard();

        if (board.isMateBool == true) { std::cout << "Checkmate"; }

        if (!board.skip) {
            if (board.activePlayer == true) { board.activePlayer = false; }
            else { board.activePlayer = true; }
        }
    }
}

