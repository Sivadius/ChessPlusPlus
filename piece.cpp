#include <iostream>
#include <string>
#include "piece.h"
using namespace std;

//Initial constructor
Piece::Piece(bool theColour) {
	colour = theColour;
}

//Displays colour
void Piece::printColour() {
	cout << colour << endl;
}

//Deconstructor
Piece::~Piece() {}