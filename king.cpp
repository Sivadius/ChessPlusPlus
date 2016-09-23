#include <iostream>
#include <string>
#include "piece.h"
#include "king.h"
using namespace std;

King::King(bool theColour, int x, int y) : Piece(theColour, x, y) {
	if(colour == 1) {
		symbol = "♚";
	} else {
		symbol = "♔";
	}
	type = "King";
}


bool King::move(int newX, int newY) {
	//return false if moving to the same position
	if((newX==xPos) && (newY==yPos)) {
		cout << "Your King is already there." << endl;
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

	//Sets available positions to 1
	for(int i=-1 ; i<2 ; i++) {
		for(int j=-1 ; j<2 ; j++) {
			if((xPos-1+i < 8) && 
			(xPos-1+i >= 0) &&
			(yPos-1+j < 8) &&
			(yPos-1+j >= 0)) {
				canGo[xPos-1+i][yPos-1+j] = 1;
			}
		}
	}
	
	// this->printMoveTable(canGo);

	//Checks for valid movement
	if(canGo[newX-1][newY-1] == 1) {
		return Piece::move(newX, newY);
	}
	cout << "Your King cannot move there." << endl;
	return 0;
}