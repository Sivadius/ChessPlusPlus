#ifndef QUEEN_H
#define QUEEN_H
#include <iostream>
#include <string>
#include "piece.h"

class Queen: public Piece { //Derived class for Queen
public:
	Queen(bool theColour, int x, int y);
	bool move(int newX, int newY); //Restricted movement
};

#endif //QUEEN_H