#include "Bishop.h"

void Bishop::Step(List<List<Figure>>* allFigure, Point newCoords)
{
	//check if move allowed function;
	Empty empty = { newCoords };
	int actionY = 0;
	int actionX = 0;

	Point outputCoords = { Coords.x, Coords.y };

	List<List<Figure>> inputList;
	List<List<Figure>> output = allFigure[0];

	int newX, newY;
	while (true)
	{
		std::cout << "\nEnter coordinates you want to move to: ";
		std::cout << "\n X: ";
		std::cin >> newX;
		// Add converter from letters to coordinate, using numbers for now
		std::cout << "\n Y: ";
		std::cin >> newY;
		if (newX > Coords.x) { actionX = 1; }
		else if (newX < Coords.x) { actionX = -1; }
		if (newY > Coords.y) { actionY = 1; }
		else if (newY < Coords.y) { actionY = -1; }
		if (actionX != 0 && actionY != 0) {
			for (int i = Coords.y;i < newY;i++)
			{
				if (output[outputCoords.y + actionY][outputCoords.x + actionX].Symbol != ' ')
				{
					std::cout << "This figure can't move that way.";
					return;
				}
				outputCoords.y += actionY;
				outputCoords.x += actionX;

			}
		}
		if (newX == outputCoords.x && newY == outputCoords.y)
		{
			break;
		}
		else
		{
			std::cout << "This figure can't move that way.";
		}
	}

	Figure figure = output[Coords.y][Coords.x];


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
}