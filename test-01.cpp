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
//creates new board and prints
int main() {
	
	Board *board;
	board = new Board();
	cout << "creating and printing test board..." << endl;
	board->printBoard();
	cout << "testing newGame..." << endl;
	board->newGame();

	board->printBoard();
}