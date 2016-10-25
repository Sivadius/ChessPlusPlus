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
//creates test board with single piece and moves around all directions
int main() {
	
	char validLetters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	char validNumbers[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};

	Board *board;
	board = new Board();
	board->testGame_1(1);
	board->printBoard();

	char xPos, yPos, xNew, yNew;

	xPos = 'A';
	yPos = '8';
	yNew = '8';
	//looping three times
	for (int j =0; j<3; j++){
		//moving right
		for (int i = 1; i<8; i++){
			system("clear");
			xNew = validLetters[i];
			cout << xNew << endl;
		
			board->movePiece( xPos, yPos, xNew, yNew);
			board->printBoard();
			xPos = xNew;
			yPos = yNew;
		}
		//moving down
		for (int i = 7; i>-1; i--){
			system("clear");
			yNew = validNumbers[i];
			cout << xNew << endl;
			board->movePiece( xPos, yPos, xNew, yNew);
			board->printBoard();
			xPos = xNew;
			yPos = yNew;
		}
		//moving left
		for (int i = 7; i>-1; i--){
			system("clear");
			xNew = validLetters[i];
			cout << xNew << endl;
			board->movePiece( xPos, yPos, xNew, yNew);
			board->printBoard();
			xPos = xNew;
			yPos = yNew;
		}
		//moving up
		for (int i = 1; i<8; i++){
			system("clear");
			yNew = validNumbers[i];
			cout << xNew << endl;
			board->movePiece( xPos, yPos, xNew, yNew);
			board->printBoard();
			xPos = xNew;
			yPos = yNew;
		}
		//moving diagonal 
		for (int i = 1; i<8; i++){
			system("clear");
			xNew = validLetters[i];
			yNew = validNumbers[7-i];
			cout << xNew << endl;
			board->movePiece( xPos, yPos, xNew, yNew);
			board->printBoard();
			xPos = xNew;
			yPos = yNew;
		}
		
		for (int i = 1; i<8; i++){
			system("clear");
			xNew = validLetters[7-i];
			yNew = validNumbers[i];
			cout << xNew << endl;
			board->movePiece( xPos, yPos, xNew, yNew);
			board->printBoard();
			xPos = xNew;
			yPos = yNew;
		}
	}
	
}