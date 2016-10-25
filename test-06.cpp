#include <iostream>
#include <string>
#include "piece.h"
#include "knight.h"
#include "castle.h"
#include "pawn.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "board.h"
#include <cstdlib>
using namespace std;

int main() {
	//creates new board
	Board *board;
	board= new Board();

	Piece *fieldPointer;

	board->testGame_1(1);
	board->printBoard();

	string select;
	bool turn=board->getTurn();
	int turnNum=board->getTurnNum();
	char letter;
	char number;
	char letter2;
	char number2;
	bool restart;
	while(true){
		system("clear");
		restart = 0;

		fieldPointer = board->getPiece(4,7);
		board->printBoard();

		cout<< fieldPointer->getSymbol() <<endl;
		//Piece Selection
		while(true){
			cin >> select;
			letter = select[0];	//character coordinate
			number = select[1];	//numerical coordinate
			if(board->spaceCheck(letter, number)){break;}
			cout<<"Invalid Selection"<<endl;
		}
		
		//Movement Selection
		while(true) {
			cout << "Pick a place to go!" << endl;
			cin >> select;
			letter2 = select[0];
			number2 = select[1];
			if((letter2 == 'r') || (letter2 == 'R')) {
				restart = 1;
				break;
			}
			if(board->movePiece(letter, number, letter2, number2)){break;}
			cout << "Invalid Selection" << endl;
		}
		if(restart) {continue;}
		bool endThis;
		//board->changeTurn();
	}
	delete board;
}