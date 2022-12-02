#ifndef King_h
#define King_h
#include "Figure.h"

class King : public Figure
{
public:
	King(Point coords) : Figure('E', coords) {}

	void Step(List<List<Figure>>* allFigure, Point newCoords) ;
};

#endif // !1
