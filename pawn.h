#ifndef PAWN_H
#define PAWN_H
#include <iostream>
#include <string>
#include "piece.h"

class Pawn: public Piece { //Derived class for Pawn
protected:
	bool first;
public:
	Pawn(bool theColour, int x, int y);
	bool move(int newX, int newY); //Restricted movement
};

#endif //PAWN_H