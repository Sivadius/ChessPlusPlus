#include <iostream>
#include <string>
#include "piece.h"
#include "knight.h"
#include "castle.h"
#include "pawn.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <cstdlib>
using namespace std;

int main() {
	//Useful lists
	char letters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	char numbers[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	string whitePieces[6] = {"♟","♜","♞","♝","♛","♚"};
	string blackPieces[6] = {"♙","♖","♘","♗","♕","♔"};

	//Board Display
	//syntax is: board[8-y][x-1]
	string board[8][8] = {
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "}
	};

	//2D piece array containing all the pieces.
	//Empty spaces have default pieces in them.
	Piece *boardState[8][8];
	for(int i=0 ; i<8 ; i++) {
		for(int j=0 ; j<8 ; j++) {
			boardState[i][j] = new Piece(0,i+1,j+1);
		}
	}

	// Creation of all pieces
	Pawn *wp1, *wp2, *wp3, *wp4, *wp5, *wp6, *wp7, *wp8,
	*bp1, *bp2, *bp3, *bp4, *bp5, *bp6, *bp7, *bp8;
	Castle *wc1, *wc2, *bc1, *bc2;
	Knight *wn1, *wn2, *bn1, *bn2;
	Bishop *wb1, *wb2, *bb1, *bb2;
	Queen *wq, *bq;
	King *bk, *wk;

	wp1 = new Pawn(1,1,2);
	board[8-wp1->getY()][wp1->getX()-1] = wp1->getSymbol();
	boardState[8-wp1->getY()][wp1->getX()-1] = wp1;

	wp2 = new Pawn(1,2,2);
	board[8-wp2->getY()][wp2->getX()-1] = wp2->getSymbol();
	boardState[8-wp2->getY()][wp2->getX()-1] = wp2;

	wp3 = new Pawn(1,3,2);
	board[8-wp3->getY()][wp3->getX()-1] = wp3->getSymbol();
	boardState[8-wp3->getY()][wp3->getX()-1] = wp3;

	wp4 = new Pawn(1,4,2);
	board[8-wp4->getY()][wp4->getX()-1] = wp4->getSymbol();
	boardState[8-wp4->getY()][wp4->getX()-1] = wp4;

	wp5 = new Pawn(1,5,2);
	board[8-wp5->getY()][wp5->getX()-1] = wp5->getSymbol();
	boardState[8-wp5->getY()][wp5->getX()-1] = wp5;

	wp6 = new Pawn(1,6,2);
	board[8-wp6->getY()][wp6->getX()-1] = wp6->getSymbol();
	boardState[8-wp6->getY()][wp6->getX()-1] = wp6;

	wp7 = new Pawn(1,7,2);
	board[8-wp7->getY()][wp7->getX()-1] = wp7->getSymbol();
	boardState[8-wp7->getY()][wp7->getX()-1] = wp7;

	wp8 = new Pawn(1,8,2);
	board[8-wp8->getY()][wp8->getX()-1] = wp8->getSymbol();
	boardState[8-wp8->getY()][wp8->getX()-1] = wp8;

	bp1 = new Pawn(0,1,7);
	board[8-bp1->getY()][bp1->getX()-1] = bp1->getSymbol();
	boardState[8-bp1->getY()][bp1->getX()-1] = bp1;

	bp2 = new Pawn(0,2,7);
	board[8-bp2->getY()][bp2->getX()-1] = bp2->getSymbol();
	boardState[8-bp2->getY()][bp2->getX()-1] = bp2;

	bp3 = new Pawn(0,3,7);
	board[8-bp3->getY()][bp3->getX()-1] = bp3->getSymbol();
	boardState[8-bp3->getY()][bp3->getX()-1] = bp3;

	bp4 = new Pawn(0,4,7);
	board[8-bp4->getY()][bp4->getX()-1] = bp4->getSymbol();
	boardState[8-bp4->getY()][bp4->getX()-1] = bp4;

	bp5 = new Pawn(0,5,7);
	board[8-bp5->getY()][bp5->getX()-1] = bp5->getSymbol();
	boardState[8-bp5->getY()][bp5->getX()-1] = bp5;

	bp6 = new Pawn(0,6,7);
	board[8-bp6->getY()][bp6->getX()-1] = bp6->getSymbol();
	boardState[8-bp6->getY()][bp6->getX()-1] = bp6;

	bp7 = new Pawn(0,7,7);
	board[8-bp7->getY()][bp7->getX()-1] = bp7->getSymbol();
	boardState[8-bp7->getY()][bp7->getX()-1] = bp7;

	bp8 = new Pawn(0,8,7);
	board[8-bp8->getY()][bp8->getX()-1] = bp8->getSymbol();
	boardState[8-bp8->getY()][bp8->getX()-1] = bp8;

	wc1 = new Castle(1,1,1);
	board[8-wc1->getY()][wc1->getX()-1] = wc1->getSymbol();
	boardState[8-wc1->getY()][wc1->getX()-1] = wc1;

	wc2 = new Castle(1,8,1);
	board[8-wc2->getY()][wc2->getX()-1] = wc2->getSymbol();
	boardState[8-wc2->getY()][wc2->getX()-1] = wc2;

	bc1 = new Castle(0,1,8);
	board[8-bc1->getY()][bc1->getX()-1] = bc1->getSymbol();
	boardState[8-bc1->getY()][bc1->getX()-1] = bc1;

	bc2 = new Castle(0,8,8);
	board[8-bc2->getY()][bc2->getX()-1] = bc2->getSymbol();
	boardState[8-bc2->getY()][bc2->getX()-1] = bc2;

	wn1 = new Knight(1,2,1);
	board[8-wn1->getY()][wn1->getX()-1] = wn1->getSymbol();
	boardState[8-wn1->getY()][wn1->getX()-1] = wn1;

	wn2 = new Knight(1,7,1);
	board[8-wn2->getY()][wn2->getX()-1] = wn2->getSymbol();
	boardState[8-wn2->getY()][wn2->getX()-1] = wn2;

	bn1 = new Knight(0,2,8);
	board[8-bn1->getY()][bn1->getX()-1] = bn1->getSymbol();
	boardState[8-bn1->getY()][bn1->getX()-1] = bn1;

	bn2 = new Knight(0,7,8);
	board[8-bn2->getY()][bn2->getX()-1] = bn2->getSymbol();
	boardState[8-bn2->getY()][bn2->getX()-1] = bn2;

	wb1 = new Bishop(1,3,1);
	board[8-wb1->getY()][wb1->getX()-1] = wb1->getSymbol();
	boardState[8-wb1->getY()][wb1->getX()-1] = wb1;

	wb2 = new Bishop(1,6,1);
	board[8-wb2->getY()][wb2->getX()-1] = wb2->getSymbol();
	boardState[8-wb2->getY()][wb2->getX()-1] = wb2;

	bb1 = new Bishop(0,3,8);
	board[8-bb1->getY()][bb1->getX()-1] = bb1->getSymbol();
	boardState[8-bb1->getY()][bb1->getX()-1] = bb1;

	bb2 = new Bishop(0,6,8);
	board[8-bb2->getY()][bb2->getX()-1] = bb2->getSymbol();
	boardState[8-bb2->getY()][bb2->getX()-1] = bb2;

	wq = new Queen(1,4,1);
	board[8-wq->getY()][wq->getX()-1] = wq->getSymbol();
	boardState[8-wq->getY()][wq->getX()-1] = wq;

	bq = new Queen(0,4,8);
	board[8-bq->getY()][bq->getX()-1] = bq->getSymbol();
	boardState[8-bq->getY()][bq->getX()-1] = bq;

	wk = new King(1,5,1);
	board[8-wk->getY()][wk->getX()-1] = wk->getSymbol();
	boardState[8-wk->getY()][wk->getX()-1] = wk;

	bk = new King(0,5,8);
	board[8-bk->getY()][bk->getX()-1] = bk->getSymbol();
	boardState[8-bk->getY()][bk->getX()-1] = bk;



	bool turn = 1; //Is it the white players turn?
	int turnNum = 1; //Current turn number.
	while(true) {
		system("clear"); //Clears the display
		cout << "Turn " << turnNum << ": ";
		if(turn) {
			cout << "White\n" << endl;
		} else {
			cout << "Black\n" << endl;
		}
		//Displays the board
		for(int i=0 ; i<8 ; i++) {
			cout << 8-i << " ";
			for(int j=0 ; j<8 ; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << "  A B C D E F G H\n" << endl;

		string select; //First input for piece selection
		string select2; //Second input for location to move to
		cout << "Select a piece (A1 to H8)." << endl;
		int letterValue; //Integer value for x-coordinate for first input
		int numberValue; //Integer value for y-coordinate for first input
		int letterValue2; //Integer value for x-coordinate for second input
		int numberValue2; //Integer value for y-coordinate for second input
		bool validSelection = 0; //Is the current selection valid?

		//Selecting a valid piece
		while(true) {
			cin >> select;
			char letter = select[0];	//character coordinate
			char number = select[1];	//numerical coordinate
			
			//Converts string inputs to integers
			for(int l=0 ; l<8 ; l++) {
				if(letter == letters[l]) {
					letterValue = l+1;
				}
				if(number == numbers[l]) {
					numberValue = l+1;
				}
			}

			//Checks for appropriate input to break input loop-K
			if (numberValue>=1 && numberValue<=8){
				//Checks if correct colour piece has been selected
				for(int i=0 ; i<6 ; i++) {
					if(((turn == 1) && (board[8-numberValue][letterValue-1] == whitePieces[i]))
					|| ((turn == 0) && (board[8-numberValue][letterValue-1] == blackPieces[i]))) {
						validSelection = 1;
					}
				}
			}
			if(validSelection) {
				break;
			}
			cout << "Invalid piece, try again." << endl;
		}
		//Displays selected piece
		cout << "Selected = "
		<< board[8-numberValue][letterValue-1] << 
		"\nPick a location to move to." << endl;

		//Selecting a valid position to move to
		while(true) {
			cin >> select2;
			char letter2 = select2[0];
			char number2 = select2[1];
			//Converts string inputs to integers
			for(int l=0 ; l<8 ; l++) {
				if(letter2 == letters[l]) {
					letterValue2 = l+1;
				}
				if(number2 == numbers[l]) {
					numberValue2 = l+1;
				}
			}
			//Continues if the move is valid
			if(boardState[8-numberValue][letterValue-1]->move(letterValue2, numberValue2)) {
				break;
			} 
			//Special case for Pawns being able to take diagonally
			validSelection = 0;
			for(int i=0 ; i<6 ; i++) {
				if(((boardState[8-numberValue][letterValue-1]->getSymbol() == "♟")
					&& (boardState[8-numberValue2][letterValue2-1]->getSymbol() == blackPieces[i]))
					&& (((boardState[8-numberValue][letterValue-1]->getX() == boardState[8-numberValue2][letterValue2-1]->getX() + 1)
					|| (boardState[8-numberValue][letterValue-1]->getX() == boardState[8-numberValue2][letterValue2-1]->getX() - 1))
					&& (boardState[8-numberValue][letterValue-1]->getY() == boardState[8-numberValue2][letterValue2-1]->getY() - 1))
					|| ((boardState[8-numberValue][letterValue-1]->getSymbol() == "♙")
					&& (boardState[8-numberValue2][letterValue2-1]->getSymbol() == whitePieces[i]))
					&& (((boardState[8-numberValue][letterValue-1]->getX() == boardState[8-numberValue2][letterValue2-1]->getX() + 1)
					|| (boardState[8-numberValue][letterValue-1]->getX() == boardState[8-numberValue2][letterValue2-1]->getX() - 1))
					&& (boardState[8-numberValue][letterValue-1]->getY() == boardState[8-numberValue2][letterValue2-1]->getY() + 1))) {
					Piece *polyPiece = boardState[8-numberValue][letterValue-1];
					polyPiece->Piece::move(letterValue2, numberValue2);
					validSelection = 1;
				}
			}
			if(validSelection) {
				break;
			}
		}
		//Necessary updates to the board
		board[8-numberValue][letterValue-1] = " ";
		board[8-numberValue2][letterValue2-1] = boardState[8-numberValue][letterValue-1]->getSymbol();
		boardState[8-numberValue2][letterValue2-1] = boardState[8-numberValue][letterValue-1];
		boardState[8-numberValue][letterValue-1] = new Piece(boardState[8-numberValue][letterValue-1]->getColour(), letterValue, numberValue);

		turn = !turn; //Toggles the turn
		if(turn) {turnNum++;} // Increments turn number
	}
}

