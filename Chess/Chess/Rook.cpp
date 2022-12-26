#include "Rook.h"

bool Rook::CalculateStep(Point target, List<List<Figure>>* allFigure)
{
	List<List<Figure>>  output = allFigure[0];
	int action;
	Point outputCoords = { Coords.x, Coords.y };

	if (target.y != Coords.y && target.x == Coords.x)
	{
		if (target.y < Coords.y) { action = -1; }
		else if (target.y > Coords.y) { action = 1; }
		for (int i = Coords.y; i != target.y;i += action)
		{
			if (output[outputCoords.y + action][outputCoords.x].Symbol != ' ' && target.y != outputCoords.y + action || output[target.y][target.x].Color == Color)
			{
				std::cout << "This figure can't move that way.";
				return false;
			}
			outputCoords.y += action;
		}
		return true;
		//break;
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
		return true;
		//break;
		
	}
	else
	{
		return false;
	}
}

bool Rook::Step(List<List<Figure>>* allFigure, Point newCoords)
{
	Board func;
	Empty empty = { newCoords };

	Point outputCoords = { Coords.x, Coords.y};

	List<List<Figure>> inputList;
	List<List<Figure>> output = allFigure[0];
	
	int newX, newY;
	char rawX;
	while(true)
	{
		std::cout << "\nEnter coordinates you want to move to(row): ";
		std::cin >> newY;
		newY = 8 - newY;
		std::cout << "Enter coordinates you want to move to(column): ";
		std::cin >> rawX;
		newX = func.convertLetter(rawX);
		int action;

		if(newY != Coords.y && newX == Coords.x )
		{
			if (newY < Coords.y) { action = -1; }
			else if (newY > Coords.y) { action = 1; }
			for(int i = Coords.y; i != newY;i += action)
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
		else if(newX != Coords.x && newY == Coords.y)
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
		else
		{
			return true;
			std::cout << "\nThis figure can't move that way.\n";;
		}
	}
	Figure figure = output[Coords.y][Coords.x];
	figure.Coords = outputCoords;
/*
	if(newY != outputCoords.y)
	{
		for (int i = outputCoords.x + 1; i < newY;i++)
		{
			if (output[i][newX].Symbol != ' ')
			{
				std::cout << "You can't move this chess figure to that position.";
				return;
			}
		}
	}

	if (newX != outputCoords.x)
	{
		for (int i = 0; i < newX;i++)
		{
			if (output[newY][i].Symbol != ' ')
			{
				std::cout << "You can't move this chess figure to that position.";
				return;
			}
		}
	}
	*/
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
				input.add(output[y][x]);
			}
		}
		inputList.add(input);
	}
	allFigure->first = inputList.first;
	return false;
}

