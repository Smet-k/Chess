#include "Queen.h"

bool Queen::CalculateStep(Point target, List<List<Figure>>* allFigure)
{
	int actionY = 0;
	int actionX = 0;
	Board func;

	Point outputCoords = { Coords.x, Coords.y };

	List<List<Figure>> inputList;
	List<List<Figure>> output = allFigure[0];

	while (true)
	{
		int action;
		if (target.x > Coords.x) { actionX = 1; }
		else if (target.x < Coords.x) { actionX = -1; }
		if (target.y > Coords.y) { actionY = 1; }
		else if (target.y < Coords.y) { actionY = -1; }
		if (target.y != Coords.y && target.x == Coords.x)
		{
			if (target.y < Coords.y) { action = -1; }
			else if (target.y > Coords.y) { action = 1; }
			for (int i = Coords.y; i != target.y;i += action)
			{
				if (output[outputCoords.y + action][outputCoords.x].Symbol != ' ' && target.y != outputCoords.y + action || output[target.y][target.x].Color == Color)
				{
					return false;
				}
				outputCoords.y += action;
			}
			break;
		}
		else if (target.x != Coords.x && target.y == Coords.y)
		{
			if (target.x < Coords.x) { action = -1; }
			else if (target.x > Coords.x) { action = 1; }
			for (int i = Coords.x; i != target.x;i += action)
			{
				if (output[outputCoords.y][outputCoords.x + action].Symbol != ' ' && target.x != outputCoords.x + action || output[target.y][target.x].Color == Color)
				{
					return false;
				}
				outputCoords.x += action;
			}
			break;
		}
		else if (actionX != 0 && actionY != 0) {
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
					}
					else { break; }

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
					else { break; }
				}
			}
		}

		if (target.x == outputCoords.x && target.y == outputCoords.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Queen::Step(List<List<Figure>>* allFigure, Point newCoords)
{
	int actionY = 0;
	int actionX = 0;
	Board func;
	Empty empty = { newCoords };

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
		int action;
		if (newX > Coords.x) { actionX = 1; }
		else if (newX < Coords.x) { actionX = -1; }
		if (newY > Coords.y) { actionY = 1; }
		else if (newY < Coords.y) { actionY = -1; }
		if (newY != Coords.y && newX == Coords.x)
		{
			if (newY < Coords.y) { action = -1; }
			else if (newY > Coords.y) { action = 1; }
			for (int i = Coords.y; i != newY;i += action)
			{
				if (output[outputCoords.y + action][outputCoords.x].Symbol != ' ' && newY != outputCoords.y + action || output[newY][newX].Color == Color)
				{
					std::cout << "This figure can't move that way.";
					return true;
				}
				outputCoords.y += action;
			}
			break;
		}
		else if (newX != Coords.x && newY == Coords.y)
		{
			if (newX < Coords.x) { action = -1; }
			else if (newX > Coords.x) { action = 1; }
			for (int i = Coords.x; i != newX;i += action)
			{
				if (output[outputCoords.y][outputCoords.x + action].Symbol != ' ' && newX != outputCoords.x + action || output[newY][newX].Color == Color)
				{
					std::cout << "This figure can't move that way.";
					return true;
				}
				outputCoords.x += action;
			}
			break;
		}
		else if (actionX != 0 && actionY != 0) {
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
			else if (actionY == -1)
			{
				for (int i = outputCoords.y;i > newY;i--)
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
		}

		if (newX == outputCoords.x && newY == outputCoords.y)
		{
			break;
		}
		else
		{
			std::cout << "This figure can't move that way.";
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