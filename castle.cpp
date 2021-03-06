#include <iostream>
#include <string>
#include "piece.h"
#include "castle.h"
using namespace std;

Castle::Castle(bool theColour, int x, int y) : Piece(theColour, x, y) {
	if(colour ==1) {
		symbol = "♜";
	} else {
		symbol = "♖";
	}
	type = "Castle";
}


bool Castle::move(int newX, int newY) {
	//return false if moving to the same position
	if((newX==xPos) && (newY==yPos)) {
		cout << "Your Castle is already there." << endl;
		return 0;
	}

	//Boolean table showing available move spaces
	bool canGo[8][8] = {
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
	};
	canGo[xPos-1][yPos-1] = 1;

	//Sets available positions to 1
	for(int i=0 ; i<8 ; i++) {
		canGo[xPos-1][i] = 1;
		canGo[i][yPos-1] = 1;
	}

	// this->printMoveTable(canGo);

	//Checks for valid movement
	if(canGo[newX-1][newY-1] == 1) {
		return Piece::move(newX, newY);
	}
	cout << "Your Castle cannot move there." << endl;
	return 0;
}