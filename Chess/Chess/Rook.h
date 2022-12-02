#ifndef Rook_h
#define Rook_h
#include "Figure.h"
#include "Empty.h"
class Rook : public Figure
{
public:
	Rook(Point coords) : Figure('R', coords) {}

	void Step(List<List<Figure>>* allFigure, Point newCoords);
};

#endif // !1
