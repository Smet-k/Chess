#include "Pawn.h"


bool Pawn::CalculateStep(Point target, List<List<Figure>>* allFigure)
{
	List<List<Figure>>  output = allFigure[0];
		if (Color == 'W' && output[target.y][target.x].Color == 'B' && target.x == Coords.x + 1 && target.y == Coords.y - 1 ||
			Color == 'W' && output[target.y][target.x].Color == 'B' && target.x == Coords.x - 1 && target.y == Coords.y - 1 ||
			Color == 'B' && output[target.y][target.x].Color == 'W' && target.x == Coords.x + 1 && target.y == Coords.y + 1 ||
			Color == 'B' && output[target.y][target.x].Color == 'W' && target.x == Coords.x - 1 && target.y == Coords.y + 1)
		{
			return true;
		}
		else
		{
			return false;
		}
}

bool Pawn::Step(List<List<Figure>>* allFigure, Point newCoords)
{
	List<List<Figure>> output = allFigure[0];
	Board func;
	Empty empty = { newCoords };
	int newX, newY; char rawX;
	while (true)
	{
		std::cout << "\nEnter coordinates you want to move to(row): ";
		std::cin >> newY;
		newY = 8 - newY;
		std::cout << "Enter coordinates you want to move to(column): ";
		std::cin >> rawX;
		newX = func.convertLetter(rawX);
		if (Coords.y == 1 && Color == 'B' && newX == Coords.x && newY == Coords.y + 2 || newX == Coords.x && newY == Coords.y + 1 && Color == 'B' ||
			Coords.y == 6 && Color == 'W' && newX == Coords.x && newY == Coords.y - 2 || newX == Coords.x && newY == Coords.y - 1 && Color == 'W')

		{
			if (output[newY][newX].Symbol == ' ')
			{
				break;
			}
		}
		if (Color == 'W' && output[newY][newX].Color == 'B' && newX == Coords.x + 1 && newY == Coords.y - 1 ||
			Color == 'W' && output[newY][newX].Color == 'B' && newX == Coords.x - 1 && newY == Coords.y - 1 ||
			Color == 'B' && output[newY][newX].Color == 'W' && newX == Coords.x + 1 && newY == Coords.y + 1 ||
			Color == 'B' && output[newY][newX].Color == 'W' && newX == Coords.x - 1 && newY == Coords.y + 1)
		{
			break;
		}
		else 
		{
			std::cout << "\nYou can't move this chess figure to that position.";
			return true;
		}
	}


	Point outputCoords = { newX, newY };

	/*

	if (Color == 'B') {outputCoords = { Coords.x, Coords.y + 1 };}
	else {outputCoords = { Coords.x, Coords.y - 1 }; }
	*/
	List<List<Figure>> inputList;
	
	Figure figure = output[Coords.y][Coords.x];
	figure.Coords = outputCoords;

	
	if (output[outputCoords.y][outputCoords.x].Symbol != ' ' && output[outputCoords.y][outputCoords.x].Color != Color && newX != Coords.x && newY != Coords.y)
	{}
	else if(output[outputCoords.y][outputCoords.x].Symbol != ' ')
	{
		std::cout << "You can't move this chess figure to that position.";
		return true; 
	}
	
	for (int y = 0;y < output.length();y++)
	{
		List<Figure> input;
		for (int x = 0;x < output[y].length();x++)
		{
			if (y == Coords.y && x == Coords.x)
			{
				Empty empty = { {x,y} };
				input.add(empty);
			}
			else if (y == outputCoords.y && x == outputCoords.x) {

				input.add(figure);
			}
			else
			{
				input.add(output[y][x]);
			}
		}
		inputList.add(input);
	}
	allFigure->first = inputList.first;
	return false;
}