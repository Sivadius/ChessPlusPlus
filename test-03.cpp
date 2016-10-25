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
//tests all valid inputs of pCipher function
int main() {
	
	Board *board;
	board = new Board();
	
	cout << endl;
	cout << "Input A: " << board->pCipher('A') << endl;
	cout << "Input B: " << board->pCipher('B') << endl;
	cout << "Input C: " << board->pCipher('C') << endl;
	cout << "Input D: " << board->pCipher('D') << endl;
	cout << "Input E: " << board->pCipher('E') << endl;
	cout << "Input F: " << board->pCipher('F') << endl;
	cout << "Input G: " << board->pCipher('G') << endl;
	cout << "Input H: " << board->pCipher('H') << endl;

	cout << endl;
	cout << "Input a: " << board->pCipher('a') << endl;
	cout << "Input b: " << board->pCipher('b') << endl;
	cout << "Input c: " << board->pCipher('c') << endl;
	cout << "Input d: " << board->pCipher('d') << endl;
	cout << "Input e: " << board->pCipher('e') << endl;
	cout << "Input f: " << board->pCipher('f') << endl;
	cout << "Input g: " << board->pCipher('g') << endl;
	cout << "Input h: " << board->pCipher('h') << endl;

	cout << endl;
	cout << "Testing invalid inputs" << endl;

	cout << "Input i: " << board->pCipher('i') << endl;
	cout << "Input I: " << board->pCipher('I') << endl;
	cout << "Input x: " << board->pCipher('x') << endl;
	cout << "Input X: " << board->pCipher('X') << endl;
	cout << "Input !: " << board->pCipher('!') << endl;
	cout << "Input @: " << board->pCipher('@') << endl;
}