#ifndef Knight_h
#define Knight_h
#include "Empty.h"
#include "Figure.h"

class Knight : public Figure
{
public:
	Knight(Point coords) : Figure('K', coords) {}

	void Step(List<List<Figure>>* allFigure, Point newCoords) ;
};

#endif // !1
