#include "Knight.h"

bool Knight::CalculateStep(Point target, List<List<Figure>>* allFigure)
{
	List<List<Figure>> output = allFigure[0];
	Point outputCoords = { Coords.x, Coords.y };
	while (true)
	{
		if (target.x == Coords.x - 2 && target.y == Coords.y + 1 || target.x == Coords.x - 2 && target.y == Coords.y - 1 ||
			target.x == Coords.x + 2 && target.y == Coords.y + 1 || target.x == Coords.x + 2 && target.y == Coords.y - 1 ||
			target.x == Coords.x - 1 && target.y == Coords.y + 2 || target.x == Coords.x + 1 && target.y == Coords.y + 2 ||
			target.x == Coords.x - 1 && target.y == Coords.y - 2 || target.x == Coords.x + 1 && target.y == Coords.y - 2)
		{
			if (output[target.y][target.x].Color != Color)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

}

bool Knight::Step(List<List<Figure>>* allFigure, Point newCoords)
{
	Board func;
	// black step
	//check if move allowed function;
	Empty empty = { newCoords };

	//finish it
	// white move
	

	List<List<Figure>> inputList;
	List<List<Figure>> output = allFigure[0];
	Point outputCoords = { Coords.x, Coords.y };
	int newX, newY; char rawX;
	while (true)
	{
		std::cout << "\nEnter coordinates you want to move to(row): ";
		std::cin >> newY;
		newY = 8 - newY;
		std::cout << "Enter coordinates you want to move to(column): ";
		std::cin >> rawX;
		newX = func.convertLetter(rawX);
		if (newX == Coords.x - 2 && newY == Coords.y + 1 || newX == Coords.x - 2 && newY == Coords.y - 1 ||
			newX == Coords.x + 2 && newY == Coords.y + 1 || newX == Coords.x + 2 && newY == Coords.y - 1 ||
			newX == Coords.x - 1 && newY == Coords.y + 2 || newX == Coords.x + 1 && newY == Coords.y + 2 ||
			newX == Coords.x - 1 && newY == Coords.y - 2 || newX == Coords.x + 1 && newY == Coords.y - 2)
		{
			if (output[newY][newX].Color != Color)
			{
				break;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	outputCoords = { newX, newY };
	Figure figure = output[Coords.y][Coords.x];
	figure.Coords = outputCoords;
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
			else if (y == newY && x == newX) {

				input.add(figure);
			}
			else
			{
				Figure test = (output[y][x]);
				input.add(output[y][x]);
			}
		}
		inputList.add(input);
	}
	allFigure->first = inputList.first;
	return false;
}