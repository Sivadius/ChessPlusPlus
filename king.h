#ifndef KING_H
#define KING_H
#include <iostream>
#include <string>
#include "piece.h"

class King: public Piece { //Derived class for Queen
public:
	King(bool theColour, int x, int y);
	bool move(int newX, int newY); //Restricted movement
};

#endif //KING_H