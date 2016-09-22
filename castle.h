#ifndef CASTLE_H
#define CASTLE_H
#include <iostream>
#include <string>
#include "piece.h"

class Castle: public Piece { //Derived class for Castle
public:
	Castle(bool theColour, int x, int y);
	bool move(int newX, int newY); //Restricted movement
};

#endif //CASTLE_H