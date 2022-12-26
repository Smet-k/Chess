#ifndef Knight_h
#define Knight_h
#include "Empty.h"
#include "Figure.h"
#include "Board.h"

class Knight : public Figure
{
public:
	Knight(Point coords,char color) : Figure('K', coords, color) {}

	bool Step(List<List<Figure>>* allFigure, Point newCoords) ;

	bool CalculateStep(Point target, List<List<Figure>>* allFigure);
};

#endif // !1
