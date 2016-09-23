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
	std::string type; //The type of piece
public:
	Piece(bool theColour, int x, int y); //Piece constructor
	bool getColour(); //Displays colour
	virtual bool move(int newX, int newY); //Unrestricted movement
	int getX(); //Return xPos
	int getY(); //Return yPos
	std::string getSymbol(); //Return icon on board
	void printMoveTable(bool table[8][8]); //Prints valid moves
	~Piece(); //Piece destuctor
};

#endif //PIECE_H