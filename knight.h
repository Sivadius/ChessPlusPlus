#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include <string>
#include "piece.h"

class Knight: public Piece { //Derived class for Knight
public:
	Knight(bool theColour, int x, int y);
	bool move(int newX, int newY); //Restricted movement
};

#endif //KNIGHT_H