#ifndef Bishop_h
#define Bishop_h
#include "Figure.h"

class Bishop : public Figure
{
public:
	Bishop(Point coords) : Figure('B', coords) {}

	void Step(List<List<Figure>>* allFigure, Point newCoords);
};

#endif // !1
