#include "Bishop.h"

bool Bishop::CalculateStep(Point target, List<List<Figure>>* allFigure)
{
	Board func;

	//check if move allowed function;
	int actionY = 0;
	int actionX = 0;

	Point outputCoords = { Coords.x, Coords.y };

	List<List<Figure>> output = allFigure[0];
	while (true)
	{
		outputCoords = { Coords.x, Coords.y };
		if (target.x > Coords.x) { actionX = 1; }
		else if (target.x < Coords.x) { actionX = -1; }
		if (target.y > Coords.y) { actionY = 1; }
		else if (target.y < Coords.y) { actionY = -1; }
		if (actionX != 0 && actionY != 0) {
			Figure test = output[outputCoords.y + actionY][outputCoords.x + actionX];
			if (actionY == 1) {
				for (int i = outputCoords.y;i < target.y;i++)
				{
					if (outputCoords.y + actionY <= 7 && outputCoords.x + actionX <= 7 && outputCoords.y + actionY >= 0 && outputCoords.x + actionX >= 0) {
						if (output[outputCoords.y + actionY][outputCoords.x + actionX].Symbol != ' ' && target.x != outputCoords.x + actionX && target.y != outputCoords.y + actionY
							|| output[target.y][target.x].Color == Color)
						{
							return false;
						}
						outputCoords.y += actionY;
						outputCoords.x += actionX;
						if (outputCoords.x == 7) { return false; }
					}
					else { return false; }
				}
			}
			else if (actionY == -1)
			{
				for (int i = outputCoords.y;i > target.y;i--)
				{
					if (outputCoords.y + actionY <= 7 && outputCoords.x + actionX <= 7 && outputCoords.y + actionY >= 0 && outputCoords.x + actionX >= 0) {
						if (output[outputCoords.y + actionY][outputCoords.x + actionX].Symbol != ' ' && target.x != outputCoords.x + actionX && target.y != outputCoords.y + actionY
							|| output[target.y][target.x].Color == Color)
						{

							return false;
						}
						outputCoords.y += actionY;
						outputCoords.x += actionX;
					}
					else { return false; }
				}
			}
		}

		if (target.x == outputCoords.x && target.y == outputCoords.y)
		{
			return true;
		}
	}
}

bool Bishop::Step(List<List<Figure>>* allFigure, Point newCoords)
{
	Board func;

	//check if move allowed function;
	Empty empty = { newCoords };
	int actionY = 0;
	int actionX = 0;

	Point outputCoords = { Coords.x, Coords.y };

	List<List<Figure>> inputList;
	List<List<Figure>> output = allFigure[0];

	int newX, newY;
	char rawX;
	while (true)
	{
		outputCoords = { Coords.x, Coords.y };
		std::cout << "\nEnter coordinates you want to move to(row): ";
		std::cin >> newY;
		newY = 8 - newY;
		std::cout << "Enter coordinates you want to move to(column): ";
		std::cin >> rawX;
		newX = func.convertLetter(rawX);
		if (newX > Coords.x) { actionX = 1; }
		else if (newX < Coords.x) { actionX = -1; }
		if (newY > Coords.y) { actionY = 1; }
		else if (newY < Coords.y) { actionY = -1; }
		if (actionX != 0 && actionY != 0) {
			Figure test = output[outputCoords.y + actionY][outputCoords.x + actionX];
			if (actionY == 1) {
				for (int i = outputCoords.y;i < newY;i++)
				{
					if (outputCoords.y + actionY <= 7 && outputCoords.x + actionX <= 7 && outputCoords.y + actionY >= 0 && outputCoords.x + actionX >= 0) {
						if (output[outputCoords.y + actionY][outputCoords.x + actionX].Symbol != ' ' && newX != outputCoords.x + actionX && newY != outputCoords.y + actionY
							|| output[newY][newX].Color == Color)
						{
							std::cout << "This figure can't move that way.";
							return true;
						}
						outputCoords.y += actionY;
						outputCoords.x += actionX;
					}
					else { break; }

				}
			}
			else if(actionY == -1)
			{
				if (outputCoords.y + actionY <= 7 && outputCoords.x + actionX <= 7 && outputCoords.y + actionY >= 0 && outputCoords.x + actionX >= 0) {
					for (int i = outputCoords.y;i > newY;i--)
					{
						if (output[outputCoords.y + actionY][outputCoords.x + actionX].Symbol != ' ' && newX != outputCoords.x + actionX && newY != outputCoords.y + actionY
							|| output[newY][newX].Color == Color)
						{
							std::cout << "This figure can't move that way.";
							return true;
						}
						outputCoords.y += actionY;
						outputCoords.x += actionX;
					}	
				}
				else { break; }
			}
		}

		if (newX == outputCoords.x && newY == outputCoords.y)
		{
			break;
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