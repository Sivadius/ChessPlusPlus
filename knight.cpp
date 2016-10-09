#include <iostream>
#include <string>
#include "piece.h"
#include "knight.h"
using namespace std;

Knight::Knight(bool theColour, int x, int y) : Piece(theColour, x, y) {
	if(colour ==1) {
		symbol = "♞";
	} else {
		symbol = "♘";
	}
	type = "Knight";
}

bool Knight::move(int newX, int newY) {
	//return false if moving to the same position
	if((newX==xPos) && (newY==yPos)) {
		cout << "Your Knight is already there." << endl;
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
	for(int r=-2 ; r<3 ; r++) {
		for(int c=-2 ; c<3 ; c++) {
			if((r==0) || (c==0) || (r/c==1) || (r/c==-1)) {
				continue;
			} else if((xPos-1+r >= 0) && (xPos-1+r <= 7)
			&& (yPos-1+c >= 0) && (yPos-1+c <= 7)) {
				canGo[xPos-1+r][yPos-1+c] = 1;
			}
		}
	}

	// this->printMoveTable(canGo);

	//Checks for valid movement
	if(canGo[newX-1][newY-1] == 1) {
		return Piece::move(newX, newY);
	}
	cout << "Your Knight cannot move there." << endl;
	return 0;
}