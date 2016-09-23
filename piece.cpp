#include <iostream>
#include <string>
#include "piece.h"
using namespace std;

//Initial constructor
Piece::Piece(bool theColour, int x, int y) {
	symbol = " ";
	colour = theColour;
	xPos = x;
	yPos = y;
	type = "Piece";
}

//Displays colour
bool Piece::getColour() {
	return colour;
}

//Moves the piece to another point on the board
bool Piece::move(int newX, int newY) {
	char letters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	cout << type << " " << letters[xPos-1] << 
	yPos << " to " << letters[newX-1] << 
	newY << "." << endl;
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

//Prints the movement table
void Piece::printMoveTable(bool table[8][8]) {
	for(int i=0 ; i<8 ; i++) {
		cout << 8-i << " ";
		for(int j=0 ; j<8 ; j++) {
			cout << table[j][7-i] << " ";
		}
		cout << endl;
	}
	cout << "  A B C D E F G H\n" << endl;
}

//Deconstructor
Piece::~Piece() {}