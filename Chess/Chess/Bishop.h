#ifndef Bishop_h
#define Bishop_h
#include "Figure.h"
#include "Empty.h"
#include "Board.h"
class Bishop : public Figure
{
public:
	Bishop(Point coords, char color) : Figure('B', coords, color) {}

	bool Step(List<List<Figure>>* allFigure, Point newCoords);

	bool CalculateStep(Point target, List<List<Figure>>* allFigure);
};

#endif // !1
