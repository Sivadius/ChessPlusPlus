#ifndef BISHOP_H
#define BISHOP_H
#include <iostream>
#include <string>
#include "piece.h"

class Bishop: public Piece { //Derived class for Bishop
	public:
	Bishop(bool theColour, int x, int y);
	bool move(int newX, int newY); //Restricted movement
};

#endif //BISHOP_H