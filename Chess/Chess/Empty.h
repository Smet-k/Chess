#ifndef Empty_h
#define Empty_h

#include "Figure.h"

class Empty : public Figure
{
public:
	Empty(Point coords) : Figure(' ', coords, ' ') {}

	void Step(List<List<Figure>>* allFigure, Point newCoords) {}
};

#endif // !1