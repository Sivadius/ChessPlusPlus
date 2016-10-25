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

	char validLetters[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	char validNumbers[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	for (int i =0; i<16; i++){
		for (int j=0; j<8; j++){
			cout << "Input: " << validLetters[i] << validNumbers[j];
			if (board->spaceCheck(validLetters[i], validNumbers[j]) == 0){
				cout<< " -Valid" <<endl;
			}		
		}
	}

	//cout << board->spaceCheck('A', 3) << endl;
}