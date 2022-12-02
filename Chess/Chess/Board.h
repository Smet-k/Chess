#ifndef Board_h
#define Board_h
#include "Figure.h"
#include "Player.h"
#include "List.h"
#include "Point.h"

//figures
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Empty.h"


class Board
{
    bool searchForFigure(Point coords);

    char letters[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z' };

    const int CellSize = 5;
    
    const char BlackCellSymbol = ' ';
    const char WhiteCellSymbol = '-';
public:

    void doStep(Point coords);

    List<List<Figure>> allFigures;

    Player* player1;

    Player* player2;
    
    Board();
    void InitBoard();

    void RefreshBoard();

    void Step(Player player);


    char getSymbol(int rowIndex, int columnIndex);

    bool IsCheck();

    bool IsMate();
};

#endif