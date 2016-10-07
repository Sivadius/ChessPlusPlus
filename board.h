#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include "piece.h"

//class type for board object
class Board{
protected:
	// char letters[8];
	// char letters2[8];
	// char numbers[8];
	// std::string whitePieces[6];
	// std::string blackPieces[6];

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
	void changeTurn();
	bool spaceCheck(char letter, char number);
	bool movePiece(char letter, char number, char letter2, char number2);
	~Board();

};

#endif //BOARD_H