#include "King.h"

bool King::CalculateStep(Point target, List<List<Figure>>* allFigure)
{
	Point outputCoords = { Coords.x, Coords.y };

	List<List<Figure>> output = allFigure[0];

	while (true)
	{
		if (target.y == outputCoords.y + 1 && target.x == outputCoords.x || target.y == outputCoords.y - 1 && target.x == outputCoords.x ||
			target.y == outputCoords.y && target.x == outputCoords.x + 1 || target.y == outputCoords.y && target.x == outputCoords.x - 1 ||
			target.y == outputCoords.y + 1 && target.x == outputCoords.x + 1 || target.y == outputCoords.y + 1 && target.x == outputCoords.x - 1 ||
			target.y == outputCoords.y - 1 && target.x == outputCoords.x + 1 || target.y == outputCoords.y - 1 && target.x == outputCoords.x - 1)
		{
			outputCoords = { target.x,target.y };
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


bool King::Step(List<List<Figure>>* allFigure, Point newCoords)
{
	Board func;
	//check if move allowed function;
	Empty empty = { newCoords };

	//finish it
	Point outputCoords = { Coords.x, Coords.y };

	List<List<Figure>> inputList;
	List<List<Figure>> output = allFigure[0];

	int newX, newY;
	char rawX;
	while (true)
	{
		std::cout << "\nEnter coordinates you want to move to(row): ";
		std::cin >> newY;
		newY = 8 - newY;
		std::cout << "Enter coordinates you want to move to(column): ";
		std::cin >> rawX;
		newX = func.convertLetter(rawX);
		if(newY == outputCoords.y + 1 && newX == outputCoords.x || newY == outputCoords.y - 1 && newX == outputCoords.x || 
		   newY == outputCoords.y && newX == outputCoords.x + 1 || newY == outputCoords.y && newX == outputCoords.x - 1 || 
		   newY == outputCoords.y + 1 && newX == outputCoords.x + 1 || newY == outputCoords.y + 1 && newX == outputCoords.x - 1 || 
			newY == outputCoords.y - 1 && newX == outputCoords.x + 1|| newY == outputCoords.y - 1 && newX == outputCoords.x - 1)
		{
			outputCoords = { newX,newY };
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

