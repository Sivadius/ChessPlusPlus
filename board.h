#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include "piece.h"

//class type for board object
class Board{
protected:
	// char letters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	// char letters2[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	// char numbers[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	// std::string whitePieces[6] = {"♟","♜","♞","♝","♛","♚"};
	// std::string blackPieces[6] = {"♙","♖","♘","♗","♕","♔"};

public:

	Piece *field[8][8];
	bool turnWhite;
	int turnNum;

	Board();
	int pCipher(char input);	
	void printBoard();
	void newGame();
	bool getTurn();
	int getTurnNum();
	bool spaceCheck(char letter, char number);
	//~Board();

};

#endif //BOARD_H