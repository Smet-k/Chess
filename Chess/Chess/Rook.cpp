#include "Rook.h"

void Rook::Step(List<List<Figure>>* allFigure, Point newCoords)
{
	// black step
	//check if move allowed function;
	Empty empty = { newCoords };

	//finish it
	// white move
	Point outputCoords = { Coords.x, Coords.y};

	List<List<Figure>> inputList;
	List<List<Figure>> output = allFigure[0];
	
	int newX, newY;
	while(true)
	{
		std::cout << "\nEnter coordinates you want to move to: ";
		std::cout << "\n X: ";
		std::cin >> newX;
		// Add converter from letters to coordinate, using numbers for now
		std::cout << "\n Y: ";
		std::cin >> newY;
		if(newX != outputCoords.x && newY == outputCoords.y || newX == outputCoords.x && newY != outputCoords.y)
		{
			break;
		}
		else
		{
			std::cout << "This figure can't move that way.";
		}
	}

	Figure figure = output[Coords.y][Coords.x];

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
}