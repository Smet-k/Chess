#ifndef Pawn_h
#define Pawn_h
#include "Figure.h"
#include "Empty.h"

class Pawn : public Figure
{
public:
	Pawn(Point coords) : Figure('P', coords){}

	void Step(List<List<Figure>>* allFigure, Point newCoords);
};

#endif // !