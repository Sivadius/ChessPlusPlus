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
	//Useful lists
	char letters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	char letters2[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	char numbers[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	string whitePieces[6] = {"♟","♜","♞","♝","♛","♚"};
	string blackPieces[6] = {"♙","♖","♘","♗","♕","♔"};

	//creates new board
	Board *board;
	board= new Board();

	board->newGame();
	board->printBoard();

	string select;
	bool turn=board->getTurn();
	int turnNum=board->getTurnNum();
	while(true){
		
		turn=!turn;
		if(turn){turnNum++;}

		system("clear");

		board->printBoard();


		while(true){
			cin >> select;
			char letter = select[0];	//character coordinate
			char number = select[1];	//numerical coordinate

			if(board->spaceCheck(letter, number)){break;}

			cout<<"invalid selection"<<endl;
		}
	}


}