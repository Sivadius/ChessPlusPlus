#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>

class Piece { //The base class for all pieces to inherit from
public:
	Piece(bool theColour); //Piece constructor
	bool colour; //Binary value for colour
	void printColour(); //Displays colour
	~Piece(); //Piece destuctor
};

#endif //PIECE_H