#ifndef Queen_h
#define Queen_h
#include "Figure.h"
#include "Empty.h"
#include "Board.h"
class Queen : public Figure
{
public:
	Queen(Point coords, char color) : Figure('Q', coords, color) {}

	bool Step(List<List<Figure>>* allFigure, Point newCoords);

	bool CalculateStep(Point target, List<List<Figure>>* allFigure);
};

#endif // !1