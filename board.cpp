#include "board.h"
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"
#include "castle.h"
#include "pawn.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Board::Board()	{
	field[8][8];
		
	for(int i=0 ; i<8 ; i++) {
		for(int j=0 ; j<8 ; j++) {
			field[i][j] = new Piece(0,i+1,j+1);
		}
	}

	turnWhite=0;
	turnNum=0;

	letters = new char[8];
	char tLetters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	
	letters2 = new char[8];
	char tLetters2[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	numbers = new char[8];
	int tNumbers[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};

	whitePieces = new string[6];
	string tWhitePieces[6] = {"♟","♜","♞","♝","♛","♚"};

	blackPieces = new string[6];
	string tBlackPieces[6] = {"♙","♖","♘","♗","♕","♔"};
	for(int i=0 ; i<8 ; i++) {
		*(letters+i) = tLetters[i];
		*(letters2+i) = tLetters2[i];
		*(numbers+i) = tNumbers[i];
		if(i<6) {
			*(whitePieces+i) = tWhitePieces[i];
			*(blackPieces+i) = tBlackPieces[i];
		}
	}

}

//sets up board for new game -K
void Board::newGame(){
	//clearing board with empty pieces
	for(int i=0 ; i<8 ; i++) {
		for(int j=0 ; j<8 ; j++) {
			field[i][j] = new Piece(0,i+1,j+1);
		}
	}

	//pawns placement
	for(int i=0;i<8;i++){
		field[1][i] = new Pawn(0,i+1,7);
		field[6][i] = new Pawn(1,i+1,2);
	}

	for(int i=0;i<2;i++) {
		field[0][i*7] = new Castle(0,1+i*7,8);	//castle placement
		field[7][i*7] = new Castle(1,1+i*7,1);

		field[0][1+i*5] = new Knight(0,2+i*5,8); //knight placement
		field[7][1+i*5] = new Knight(1,2+i*5,1);

		field[0][2+i*3] = new Bishop(0,3+i*3,8);	//bishop placement
		field[7][2+i*3] = new Bishop(1,3+i*3,1);

		field[i*7][4] = new Queen(i,5,8-i*7);	//queen placement
		field[i*7][3] = new King(i,4,8-i*7);	//king placement

	}
	turnWhite=1;
	turnNum=1;
}
//displays current board state in terminal-K
void Board::printBoard(){

	cout << "Turn " << turnNum << ": ";
	if(turnWhite) {
		cout << "White\n" << endl;
	} else {
		cout << "Black\n" << endl;
	}

	for(int i=0 ; i<8 ; i++) {
		cout << 8-i << " ";
			for(int j=0 ; j<8 ; j++) {
				cout << field[i][j]->getSymbol() << " ";
			}
		cout << endl;
	}
	cout << "  A B C D E F G H\n" << endl;
}


bool Board::getTurn(){
	return turnWhite;
}

int Board::getTurnNum(){
	return turnNum;
}

void Board::changeTurn() {
	turnWhite = !turnWhite;
	if(turnWhite) {turnNum++;}
}

//Converts a character to it's integer coordinate
int Board::pCipher(char input){
	int inputValue;

	for(int l=0 ; l<8 ; l++) {
		if((input == letters[l])
			|| (input == letters2[l])) {
				inputValue = l+1;
			}
		if(input == numbers[l]) {
			inputValue = l+1;
		}
	}
	return inputValue;
}
//function to check if space input is valid-K
bool Board::spaceCheck(char letter, char number){
	bool validSelection=0;

	int numberValue= this->pCipher(number);
	int letterValue= this->pCipher(letter);

	//Checks for appropriate input to break input loop-K
	if (numberValue>=1 && numberValue<=8){
		//Checks if correct colour piece has been selected-M
		for(int i=0 ; i<6 ; i++) {
			if(((turnWhite == 1) && (field[8-numberValue][letterValue-1]->getSymbol() == whitePieces[i]))
				|| ((turnWhite == 0) && (field[8-numberValue][letterValue-1]->getSymbol() == blackPieces[i]))) {
				validSelection = 1;
			}
		}
	}

	if(validSelection){
		//Displays selected piece
		cout << "Selected = "
		<< field[8-numberValue][letterValue-1]->getSymbol() << 
		"\nPick a location to move to.\nType 'r' to reselect another piece." << endl;
	}

	return validSelection;
}
//function to check if movement selection is valid-K
bool Board::movePiece(char letter, char number, char letter2, char number2) {
	int numberValue= this->pCipher(number);
	int letterValue= this->pCipher(letter);
	int numberValue2 = this->pCipher(number2);
	int letterValue2 = this->pCipher(letter2);

	//checks for destination piece being on same team-K
	bool pieceColour=field[8-numberValue][letterValue-1]->getColour();
	string destination=field[8-numberValue2][letterValue2-1]->getSymbol();

	if (pieceColour==1){
		for (int i=0;i<6;i++){
			if (whitePieces[i]==destination){
				cout<<"Friendly piece!"<<endl;
				return 0;
			}
		}
	}

	if (pieceColour==0){
		for (int i=0;i<6;i++){
			if (blackPieces[i]==destination){
				cout<<"Friendly piece!"<<endl;
				return 0;
			}
		}
	}
	
	//pawn diagonal take move variant-K
	for (int i=0;i<6;i++){
		//for black pawn
		if ((field[8-numberValue][letterValue-1]->getSymbol()=="♙") 
			&&(field[8-numberValue2][letterValue2-1]->getSymbol() == whitePieces[i])){

			if (((numberValue2==numberValue-1) &&(letterValue2==letterValue+1))
				||((numberValue2==numberValue-1) &&(letterValue2==letterValue-1))){
				
				field[8-numberValue2][letterValue2-1] = field[8-numberValue][letterValue-1];
				field[8-numberValue][letterValue-1] = new Piece(field[8-numberValue2][letterValue2-1]->getColour(), letterValue, numberValue);
				return 1;
			}

			//Stopping black pawns from taking forwards
			if ((numberValue2==numberValue-1) && (letterValue2==letterValue)) {
				return 0;
			}
		}
		
		//for white pawn
		if ((field[8-numberValue][letterValue-1]->getSymbol()=="♟") 
			&&(field[8-numberValue2][letterValue2-1]->getSymbol() == blackPieces[i])){

			if (((numberValue2==numberValue+1) && (letterValue2==letterValue+1))
				||((numberValue2==numberValue+1) && (letterValue2==letterValue-1))){
				
				field[8-numberValue2][letterValue2-1] = field[8-numberValue][letterValue-1];
				field[8-numberValue][letterValue-1] = new Piece(field[8-numberValue2][letterValue2-1]->getColour(), letterValue, numberValue);
				return 1;
			}

			//Stopping white pawns from taking forwards
			if ((numberValue2==numberValue+1) && (letterValue2==letterValue)) {
				return 0;
			}
		}
	}
	

	//calls piece move function to check valid move
	//if valid completes the move
	if(field[8-numberValue][letterValue-1]->move(letterValue2, numberValue2)) {
		field[8-numberValue2][letterValue2-1] = field[8-numberValue][letterValue-1];
		field[8-numberValue][letterValue-1] = new Piece(field[8-numberValue2][letterValue2-1]->getColour(), letterValue, numberValue);
		return 1;
	}
	
	return 0;
}

Board::~Board() {
	delete letters;
	delete letters2;
	delete numbers;
	delete whitePieces;
	delete blackPieces;
}