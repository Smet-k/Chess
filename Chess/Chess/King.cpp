#include "King.h"


void King::Step(List<List<Figure>>* allFigure, Point newCoords)
{

	//check if move allowed function;
	Empty empty = { newCoords };

	//finish it
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
		if(newY == outputCoords.y + 1 && newX == outputCoords.x || newY == outputCoords.y - 1 && newX == outputCoords.x || 
		   newY == outputCoords.y && newX == outputCoords.x + 1 || newY == outputCoords.y && newX == outputCoords.x - 1 || 
		   newY == outputCoords.y + 1 && newX == outputCoords.x + 1 || newY == outputCoords.y + 1 && newX == outputCoords.x - 1 || 
			newY == outputCoords.y - 1 && newX == outputCoords.x + 1|| newY == outputCoords.y - 1 && newX == outputCoords.x - 1)
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
}