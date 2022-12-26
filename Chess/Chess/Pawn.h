#ifndef Pawn_h
#define Pawn_h
#include "Figure.h"
#include "Empty.h"
#include "Board.h"
class Pawn : public Figure
{
public:

	Pawn(Point coords, char color) : Figure('P', coords,color){}

	bool Step(List<List<Figure>>* allFigure, Point newCoords);

	bool CalculateStep(Point target, List<List<Figure>>* allFigure);
};


#endif // !