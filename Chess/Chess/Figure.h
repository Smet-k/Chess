#ifndef Figure_h
#define Figure_h
#include "Point.h"
#include "List.h"
#include "Empty.h"
class Figure
{
public:
	char Symbol;

	Point Coords;

	void Step(List<List<Figure>>* allFigure, Point newCoords) {}

	Figure(char symbol, Point coords);

	Figure();
};


#endif