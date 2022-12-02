#include "Board.h"
#include <iostream>
//		system("CLS");
int main()
{
    Board board;
    board.InitBoard();
    board.RefreshBoard();
    board.doStep({ 5,0 });
    board.RefreshBoard();

}

