#ifndef Rook_h
#define Rook_h
#include "Figure.h"
#include "Empty.h"
#include "Board.h"
class Rook : public Figure
{
public:
	Rook(Point coords,char color) : Figure('R', coords, color) {}

	bool Step(List<List<Figure>>* allFigure, Point newCoords);

	bool CalculateStep(Point target, List<List<Figure>>* allFigure);

};

#endif // !1
