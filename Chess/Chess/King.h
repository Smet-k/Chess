#ifndef King_h
#define King_h
#include "Figure.h"
#include "Empty.h"
#include "Board.h"
class King : public Figure
{
public:
	King(Point coords, char color) : Figure('E', coords, color) {}

	bool Step(List<List<Figure>>* allFigure, Point newCoords) ;

	bool CalculateStep(Point target, List<List<Figure>>* allFigure);
};

#endif // !1
