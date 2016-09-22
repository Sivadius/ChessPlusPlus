#include <iostream>
#include <string>
#include "piece.h"
using namespace std;

//Initial constructor
Piece::Piece(bool theColour, int x, int y) {
	symbol = "?";
	colour = theColour;
	xPos = x;
	yPos = y;
}

//Displays colour
void Piece::printColour() {
	cout << colour << endl;
}

//Moves the piece to another point on the board
bool Piece::move(int newX, int newY) {
	xPos = newX;
	yPos = newY;
	return 1;
}

int Piece::getX() {
	return xPos;
}

int Piece::getY() {
	return yPos;
}

string Piece::getSymbol() {
	return symbol;
}

//Deconstructor
Piece::~Piece() {}