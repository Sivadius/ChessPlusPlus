#include <iostream>
#include <string>
#include "piece.h"
#include "knight.h"
using namespace std;

Knight::Knight(bool theColour, int x, int y) {
	colour = theColour;
	if(colour ==1) {
		symbol = "♞";
	} else {
		symbol = "♘";
	}
	xPos = x;
	yPos = y;
}


bool Knight::move(int newX, int newY) {
	//Numbers to letters conversion for x-axis
	char letters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

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
	canGo[xPos-1][yPos-1] = 1;

	//Sets available positions to 1
	for(int r=-2 ; r<3 ; r++) {
		for(int c=-2 ; c<3 ; c++) {
			if((r==0) || (c==0) || (r/c==1) || (r/c==-1)) {
				continue;
			} else if((xPos-1+r >= 0) && (xPos-1+r <= 7)
			&& (yPos-1+c >= 1) && (yPos-1+c <= 7)) {
				canGo[xPos-1+r][yPos-1+c] = 1;
			}
		}
	}

	// //Prints the movement table
	// for(int i=0 ; i<8 ; i++) {
	// 	cout << 8-i << " ";
	// 	for(int j=0 ; j<8 ; j++) {
	// 		cout << canGo[j][7-i] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "  A B C D E F G H\n" << endl;

	//Checks for valid movement
	if(canGo[newX-1][newY-1] == 1) {
		cout << "Knight " << letters[xPos-1] << 
		yPos << " to " << letters[newX-1] << 
		newY << "." << endl;
		yPos = newY;
		xPos = newX;
		return 1;
	}
	cout << "Your Knight cannot move there." << endl;
	return 0;
}