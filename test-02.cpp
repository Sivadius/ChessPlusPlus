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
//creates test board with single piece and compares positions
int main() {
	
	Board *board;
	board = new Board();
	board->testGame_1(1);
	board->printBoard();
	
	Piece *testPiece;

	testPiece = board->getPiece(0,0);

	cout << "piece position on board: A8" << endl;
	cout << "piece position in array: [0][0]" << endl;
	cout << endl;

	cout << "test piece symbol: " << testPiece->getSymbol() << endl;

	cout << "test piece X: " << testPiece->getX() << endl;
	cout << "test piece Y: " << testPiece->getY() << endl;

	cout << endl;
	cout << "Array conversion for A: " << board->pCipher('A') << endl;

}