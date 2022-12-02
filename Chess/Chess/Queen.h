#ifndef Queen_h
#define Queen_h
#include "Figure.h"
#include "Empty.h"
class Queen : public Figure
{
public:
	Queen(Point coords) : Figure('Q', coords) {}

	void Step(List<List<Figure>>* allFigure, Point newCoords);
};

#endif // !1