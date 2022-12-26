#ifndef Figure_h
#define Figure_h
#include "Point.h"
#include "List.h"
class Figure
{
public:

	char Symbol;

	char Color;

	Point Coords;

	void Step(List<List<Figure>>* allFigure, Point newCoords) {}

	Figure(char symbol, Point coords, char color);

	Figure();
};


#endif