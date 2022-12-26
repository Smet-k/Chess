#include "Figure.h"

Figure::Figure(char symbol, Point coords, char color)
{
	Coords = coords;
	Symbol = symbol;
	Color = color;
}

Figure::Figure() {}
