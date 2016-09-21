#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>

class Piece { //The base class for all pieces to inherit from
protected:
	std::string symbol; //Character on the board
	int xPos; //Position on the x-axis
	int yPos; //Position on the y-axis
	bool colour; //Binary value for colour
public:
	Piece();
	Piece(bool theColour, int x, int y); //Piece constructor
	void printColour(); //Displays colour
	virtual bool move(int newX, int newY); //Unrestricted movement
	int getX(); //Return xPos
	int getY(); //Return yPos
	std::string getSymbol();
	~Piece(); //Piece destuctor
};

#endif //PIECE_H