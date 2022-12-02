#include "Pawn.h"



void Pawn::Step(List<List<Figure>>* allFigure, Point newCoords)
{
	// black step
	//check if move allowed function;
	Empty empty = { newCoords };
	
	// white move
	Point outputCoords = { Coords.x, Coords.y + 1 };

	List<List<Figure>> inputList;
	List<List<Figure>> output = allFigure[0];
	Figure figure = output[Coords.y][Coords.x];

	if(output[outputCoords.y][outputCoords.x].Symbol != ' ')
	{
		std::cout << "You can't move this chess figure to that position.";
		return;
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
}