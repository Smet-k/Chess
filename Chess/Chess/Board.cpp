#include "Board.h"
Board::Board()
{
    /*List<Figure*> input;
    for (int y = 0;y < 8;y++)
    {
        for (int x = 0;x < 8;x++)
        {
            Point currentCoords = { x,y };
            Empty empty = { currentCoords };
            //input.add(&empty);
        }
        //allFigures.add(input);
    }*/
}


bool Board::searchForFigure(Point coords)
{
    if (allFigures[coords.y][coords.x].Symbol == ' ') { return false; }
    return true;
}


char Board::getSymbol(int rowIndex,int columnIndex)
{
    for(int i = 0;i < rowIndex;i++)
    {
        allFigures.first = allFigures.first->next;
    }
    return allFigures[0][0].Symbol;
}

void Board::InitBoard()
{

    for (int y = 0;y < 8;y++)
    {
        List<Figure> input;
        for (int x = 0;x < 8; x++)
        {
            
            //if (y == 1 || y == 6)
            if (y == 1 || y == 6)
            {
                Pawn pawn = { { x,y } };
                input.add(pawn);
            }
            else if (y == 0 && x == 0 || y == 0 && x == 7 || y == 7 && x == 0 || y == 7 && x == 7)
            {
                Rook rook = { { x,y } };
                input.add(rook);
            }
            else if (y == 0 && x == 1 || y == 0 && x == 6 || y == 7 && x == 1 || y == 7 && x == 6)
            {
                Knight knight = { { x,y } };
                input.add(knight);
            }
            else if (y == 0 && x == 1 || y == 0 && x == 6 || y == 7 && x == 1 || y == 7 && x == 6)
            {
                Knight knight = { { x,y } };
                input.add(knight);
            }
            else if (y == 0 && x == 2 || y == 0 && x == 5 || y == 7 && x == 2 || y == 7 && x == 5)
            {
                Bishop bishop = { { x,y } };
                input.add(bishop);
            }
            else if (y == 0 && x == 3 || y == 7 && x == 3)
            {
                King king = { { x,y } };
                input.add(king);
            }
            else if (y == 0 && x == 4 || y == 7 && x == 4)
            {
                Queen queen = { { x,y } };
                input.add(queen);
            }
            else
            {
                Empty empty = { { x,y } };
                input.add(empty);
            }
        }
        allFigures.add(input);
    }

    //              allFigures[y][x];
}

void Board::RefreshBoard() 
{
    system("CLS");

	for (int l = 0; l < 8; l++)
	{
		std::cout << "------";
	}
    std::cout << "\n|     ";
    for (int m = 0; m < 8; m++)
    {
        std::cout << letters[m] << "    ";
    }
    std::cout << " |\n";
	for (int y = 0; y < 8; y++)
	{
		int spaces = 2;
		int dots = 2;
		for (int n = 0; n < CellSize; n++) {
			if (n == 0 || n == 3) { spaces = 2; dots = 2; }
			else { spaces = 1; dots = 4; }
			std::cout << "|";
			if (n == 1) { std::cout << " " << 8 - y << " "; }
			else { std::cout << "   "; }
			for (int x = 0; x < 8; x++)
			{
                if (searchForFigure({ x,y }) == false)
                {
                    if ((x + y) % 2 == 0)
                    {
                        for (int i = 0;i < CellSize;i++)
                        {
                            std::cout << WhiteCellSymbol; // біле
                        }
                    }
                    else
                    {
                        for (int i = 0;i < CellSize;i++)
                        {
                            std::cout << BlackCellSymbol; // чорне
                        }
                    }
                }
                else
                {
                    if ((x + y) % 2 == 0)
                    {
                        for (int i = 0;i < CellSize;i++)
                        {
                            if(i == CellSize / 2 && n == CellSize / 2)
                            {
                                std::cout << allFigures[y][x].Symbol;
                            }
                            else
                            {
                                std::cout << WhiteCellSymbol; // біле
                            }   
                        }
                    }
                    else
                    {
                        for (int i = 0;i < CellSize;i++)
                        {
                            if (i == CellSize / 2 && n == CellSize / 2)
                            {
                                std::cout << allFigures[y][x].Symbol;
                            }
                            else
                            {
                                std::cout << BlackCellSymbol; // чорне
                            }
                        }
                    }
                }
			}
			if (n == 1) { std::cout << " " << 8 - y << " "; }
			else { std::cout << "   "; }
			std::cout << "|";
			std::cout << "\n";
		}

	}
    std::cout << "|     ";
    for (int m = 0; m < 8; m++)
    {
        std::cout  << letters[m] << "    ";
    }
    std::cout << " |\n";
	for (int l = 0; l < 8; l++)
	{
		std::cout << "------";
	}
	std::cout << "\n";

}

void Board::Step(Player player) {}

void Board::doStep(Point coords) // newCoords are temporaly
{
    Figure figureToStep = allFigures[coords.y][coords.x];

    switch (figureToStep.Symbol)
    {
        case 'P':((Pawn*)&figureToStep)->Step(&allFigures, coords); break;
        case 'E':((King*)&figureToStep)->Step(&allFigures, coords); break;
        case 'K':((Knight*)&figureToStep)->Step(&allFigures, coords); break;
        case 'B':((Bishop*)&figureToStep)->Step(&allFigures, coords); break;
        case 'R':((Rook*)&figureToStep)->Step(&allFigures, coords); break;
        case 'Q':((Queen*)&figureToStep)->Step(&allFigures, coords); break;
    }

    /*
    if(figureToStep.Symbol == 'P'){ ((Pawn*)&figureToStep)->Step(&allFigures, coords); }
    else if(figureToStep.Symbol == 'E') { ((King*)&figureToStep)->Step(&allFigures, coords); }
    else if(figureToStep.Symbol == 'K') { ((Knight*)&figureToStep)->Step(&allFigures, coords); }
    else if(figureToStep.Symbol == 'B') { ((Bishop*)&figureToStep)->Step(&allFigures, coords); }
    else if(figureToStep.Symbol == 'R') { ((Rook*)&figureToStep)->Step(&allFigures, coords); }
    else if(figureToStep.Symbol == 'Q') { ((Queen*)&figureToStep)->Step(&allFigures, coords); }
    */

    /*
    List<List<Figure>> inputList;
    List<List<Figure>> output = allFigures;
    Figure figure = allFigures[coords.y][coords.x];
    for (int y = 0;y < allFigures.length();y++)
    {
        List<Figure> input;
        for (int x = 0;x < allFigures[y].length();x++)
        {
            if (y == coords.y && x == coords.x)
            {
                Empty empty = { {x,y} };
                input.add(empty);
                figure.Coords = figure.Step();
            }
            if (y == figure.Coords.y && x == figure.Coords.x) {

                input.add(figure);
            }
            else
            {
                input.add(allFigures[y][x]);
            }
        }
        inputList.add(input);
    }
    allFigures.first = inputList.first;
    */
}

bool Board::IsCheck()
{
    return false;
}

bool Board::IsMate()
{
    return false;
}

