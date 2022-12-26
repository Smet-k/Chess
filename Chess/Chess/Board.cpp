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

int Board::convertLetter(char input)
{
    for (int i = 0;i < 26;i++) 
    {
        if(tolower(input) == letters[i])
        {
            return i;
        }
    }
    return -1;
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

            if (y == 2 || y == 3)
            {
                Rook pawn = { { x,y } , 'W' };
                input.add(pawn);
            }
            else if (y == 1 || y == 6)
            {
                if (y == 1)
                {   /*
                    Empty empty = { { x,y } };
                    input.add(empty);
                    */
                    Pawn pawn = { { x,y } , 'B' };
                    input.add(pawn);
                    
                }
                if (y == 6)
                {
                    
                    Pawn pawn = { { x,y } , 'W' };
                    input.add(pawn);
                }

            }
            else if (y == 0 && x == 0 || y == 0 && x == 7 || y == 7 && x == 0 || y == 7 && x == 7)
            {
                if (y == 0) 
                {
                    Rook rook = { { x,y } , 'B' };
                    input.add(rook);
                }
                if (y == 7)
                {
                    Rook rook = { { x,y }, 'W' };
                    input.add(rook);
                }
            }
            else if (y == 0 && x == 1 || y == 0 && x == 6 || y == 7 && x == 1 || y == 7 && x == 6)
            {
                if (y == 0) {
                    Knight knight = { { x,y } , 'B'};
                    input.add(knight);
                }
                if(y == 7){
                    Knight knight = { { x,y } , 'W' };
                    input.add(knight);
                }
            }
            else if (y == 0 && x == 2 || y == 0 && x == 5 || y == 7 && x == 2 || y == 7 && x == 5)
            {
                if (y == 0) {
                    Bishop bishop = { { x,y } ,'B' };
                    input.add(bishop);
                }
                if (y == 7) {
                    Bishop bishop = { { x,y } ,'W' };
                    input.add(bishop);
                }
            }
            else if (y == 0 && x == 3 || y == 7 && x == 3)
            {
                if (y == 0) {
                    King king = { { x,y } ,'B'};
                    input.add(king);
                }
                if (y == 7) {
                    King king = { { x,y } ,'W' };
                    input.add(king);
                }
                
            }
            else if (y == 0 && x == 4 || y == 7 && x == 4)
            {
                if (y == 0) {
                    Queen queen = { { x,y } ,'B'};
                    input.add(queen);
                }
                if (y == 7){
                    Queen queen = { { x,y } ,'W' };
                    input.add(queen);
                }
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

                    for (int i = 0;i < CellSize;i++)
                    {
                        if (i == CellSize / 2 && n == CellSize / 2)
                        {
                            if (allFigures[y][x].Color == 'B')
                            {
                            std::cout << allFigures[y][x].Symbol;
                            }
                            if (allFigures[y][x].Color == 'W')
                            {
                            std::cout << (char)tolower(allFigures[y][x].Symbol);
                            }
                        }
                        else
                        {
                            if ((x + y) % 2 == 0)
                            {
                                std::cout << WhiteCellSymbol; // біле
                            }
                            else { std::cout << BlackCellSymbol; }
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

void Board::doStep(Point coords)
{

    Figure figureToStep = allFigures[coords.y][coords.x];

    if (figureToStep.Color == 'W' && activePlayer == true || figureToStep.Color == 'B' && activePlayer == false)
    {
        switch (figureToStep.Symbol)
        {
        case 'P':skip = ((Pawn*)&figureToStep)->Step(&allFigures, coords); break;
        case 'E':skip = ((King*)&figureToStep)->Step(&allFigures, coords); break;
        case 'K':skip = ((Knight*)&figureToStep)->Step(&allFigures, coords); break;
        case 'B':skip = ((Bishop*)&figureToStep)->Step(&allFigures, coords); break;
        case 'R':skip = ((Rook*)&figureToStep)->Step(&allFigures, coords); break;
        case 'Q':skip = ((Queen*)&figureToStep)->Step(&allFigures, coords); break;
        }
    }
    else { std::cout << "This is opponent's figure";skip = true; }
}

void Board::IsCheck(Point Coords)
{

    Figure king;
    List<List<Figure>>  output = allFigures;

    //Figure figureToStep = allFigures[coords.y][coords.x];

    for (int y = 0;y < allFigures.length();y++)
    {
        for (int x = 0;x < allFigures[y].length();x++)
        {
            if (allFigures[y][x].Symbol == 'E' && allFigures[y][x].Color == 'W' && activePlayer == true ||
                allFigures[y][x].Symbol == 'E' && allFigures[y][x].Color == 'B' && activePlayer == false)
            {
                king = allFigures[y][x];
            }
        }
    }

    for (int y = 0;y < output.length();y++)
    {
        for (int x = 0;x < output[y].length();x++)
        {
            if (output[y][x].Symbol != ' ')
            {
                Figure figureToStep = output[y][x];
                if (figureToStep.Color == 'W' && activePlayer == false || figureToStep.Color == 'B' && activePlayer == true)
                {
                    switch (figureToStep.Symbol)
                    {
                    case 'P':isCheckBool = ((Pawn*)&figureToStep)->CalculateStep(king.Coords, &allFigures); if (isCheckBool) { return ; } break;
                    case 'E':isCheckBool = ((King*)&figureToStep)->CalculateStep(king.Coords,&allFigures); if (isCheckBool) { return ; } break;
                    case 'K':isCheckBool = ((Knight*)&figureToStep)->CalculateStep(king.Coords, &allFigures);if (isCheckBool) { return ; } break;
                    case 'B':isCheckBool = ((Bishop*)&figureToStep)->CalculateStep(king.Coords, &allFigures); if (isCheckBool) { return ; } break;
                    case 'R':isCheckBool = ((Rook*)&figureToStep)->CalculateStep(king.Coords, &allFigures);  if (isCheckBool) { return ; } break;
                    case 'Q':isCheckBool = ((Queen*)&figureToStep)->CalculateStep(king.Coords, &allFigures); if (isCheckBool) { return ; } break;
                    
                    }
                }
                else
                {
                    isCheckBool = false;
                }
            }
        }
    }

    return ;
}

bool Board::IsMate(Point Coords)
{
    List<Point> possibleTurns;
    Point outputCoords = { Coords.x, Coords.y };
    IsCheck(Coords);
    if (isCheckBool) {
        for (int y = 0;y < allFigures.length();y++)
        {
            for (int x = 0;x < allFigures[y].length();x++)
            {
                if (allFigures[y][x].Color != allFigures[outputCoords.y][outputCoords.x].Color) {
                    if (y == outputCoords.y + 1 && x == outputCoords.x || y == outputCoords.y - 1 && x == outputCoords.x ||
                        y == outputCoords.y && x == outputCoords.x + 1 || y == outputCoords.y && x == outputCoords.x - 1 ||
                        y == outputCoords.y + 1 && x == outputCoords.x + 1 || y == outputCoords.y + 1 && x == outputCoords.x - 1 ||
                        y == outputCoords.y - 1 && x == outputCoords.x + 1 || y == outputCoords.y - 1 && x == outputCoords.x - 1 )
                    {
                        possibleTurns.add({ x,y });
                    }
                }
            }
        }

        for (int i = 0;i < possibleTurns.length();i++)
        {
            IsCheck(possibleTurns[i]);
            if (!isCheckBool)
            {
                return false;
            }
        }
        return true;
    }
    else { return false; }
}

