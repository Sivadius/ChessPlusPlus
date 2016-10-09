#include <iostream>
#include <string>
#include "piece.h"
#include "pawn.h"
using namespace std;

Pawn::Pawn(bool theColour, int x, int y) : Piece(theColour, x, y) {
	if(colour == 1) {
		symbol = "♟";
	} else {
		symbol = "♙";
	}
	type = "Pawn";
	first = 1;
}

//details valid moves for piece
bool Pawn::move(int newX, int newY) {
	//return false if moving to the same position
	if((newX==xPos) && (newY==yPos)) {
		cout << "Your Pawn is already there." << endl;
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
	for(int i=0 ; i<8 ; i++) {
		if((colour == 1) && (yPos < 8)) {
			canGo[xPos-1][yPos] = 1;
			if(first) { 
				canGo[xPos-1][yPos+1] = 1; 
			}
		}
		else if((colour == 0) && (yPos-2 >= 0)) {
			canGo[xPos-1][yPos-2] = 1;
			if(first) {
				canGo[xPos-1][yPos-3] = 1;
			}
		}
	}

	// this->printMoveTable(canGo);

	//Checks for valid movement
	if(canGo[newX-1][newY-1] == 1) {
		first = 0;
		return Piece::move(newX, newY);
	}
	cout << "Your Pawn cannot move there." << endl;
	return 0;
}