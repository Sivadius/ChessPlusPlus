#include <iostream>
#include <string>
#include "piece.h"
#include "bishop.h"
using namespace std;

Bishop::Bishop(bool theColour, int x, int y) : Piece(theColour, x, y) {
	if(colour == 1) {
		symbol = "♝";
	} else {
		symbol = "♗";
	}
	type = "Bishop";
}


bool Bishop::move(int newX, int newY) {
	//return false if moving to the same position
	if((newX==xPos) && (newY==yPos)) {
		cout << "Your Bishop is already there." << endl;
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
	int steps[4] = {min(xPos, yPos), min(xPos, 8-yPos)};
	int theX;
	int theY;
	for(int i=0 ; i<8 ; i++) {
		theX = xPos-steps[0]+i;
		theY = yPos-steps[0]+i;
		if((theX < 8) && (theY < 8) && (theX >= 0) && (theY >= 0)) {
			canGo[theX][theY] = 1;
		}
		theX = xPos-steps[1]-1+i;
		theY = yPos+steps[1]-1-i;
		if((theX < 8) && (theY < 8) && (theX >= 0) && (theY >= 0)) {
			canGo[theX][theY] = 1;
		}
	}

	// this->printMoveTable(canGo);

	//Checks for valid movement
	if(canGo[newX-1][newY-1] == 1) {
		return Piece::move(newX, newY);
	}
	cout << "Your Bishop cannot move there." << endl;
	return 0;
}

//Function to find the minimum of two values
int min(int first, int second) {
	if(first<second) {
		return first;
	}
	return second;
}