#include <iostream>
#include <string>
#include "piece.h"
#include "knight.h"
#include "castle.h"
#include "pawn.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <cstdlib>
using namespace std;

int main() {
	//syntax = board[8-y][x-1]
	string board[8][8] = {
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "}
	};
	Knight *k1;
	Castle *c1;
	Pawn *p1;
	Bishop *b1;
	Queen *q1;
	King *i1;
	int xPos = 2;
	int yPos = 1;
	k1 = new Knight(1,xPos,yPos);
	c1 = new Castle(0,4,4);
	p1 = new Pawn(1,4,6);
	b1 = new Bishop(1,6,6);
	q1 = new Queen(0,4,3);
	i1 = new King(0,3,5);
	board[8-yPos][xPos-1] = k1->getSymbol();
	while(true) {
		system("clear");
		for(int i=0 ; i<8 ; i++) {
			cout << 8-i << " ";
			for(int j=0 ; j<8 ; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << "  A B C D E F G H\n" << endl;
		int xMove;
		int yMove;
		xPos = k1->getX();
		yPos = k1->getY();
		bool legit = 0;
		while(not legit) {
			cout << "x-coordinate (1-8)";
			cin >> xMove;
			cout << "y-coordinate (1-8)";
			cin >> yMove;
			legit = k1->move(xMove,yMove);
		}
		board[8-yPos][xPos-1] = " ";
		board[9-yMove-1][xMove-1] = k1->getSymbol();
	}
	delete p1;
}

