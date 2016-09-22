#include <iostream>
#include <string>
#include "piece.h"
#include "knight.h"
#include "castle.h"
#include <cstdlib>
using namespace std;

int main() {
	//syntax = board[9-y-1][x-1]
	string board[8][8] = {
		{"♖","♘","♗","♕","♔","♗","♘","♖"},
		{"♙","♙","♙","♙","♙","♙","♙","♙"},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{"♟","♟","♟","♟","♟","♟","♟","♟"},
		{"♜","♞","♝","♛","♚","♝","♞","♜"}
	};
	Piece *p1;
	Knight *k1;
	Castle *c1;
	p1 = new Piece(0, 0, 0);
	int xPos = 2;
	int yPos = 1;
	k1 = new Knight(1,xPos,yPos);
	c1 = new Castle(0,4,4);
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
			c1->move(3,4);
			cout << "x-coordinate (1-8)";
			cin >> xMove;
			cout << "y-coordinate (1-8)";
			cin >> yMove;
			legit = k1->move(xMove,yMove);
		}
		board[9-yPos-1][xPos-1] = " ";
		board[9-yMove-1][xMove-1] = k1->getSymbol();
	}
	delete p1;
}

