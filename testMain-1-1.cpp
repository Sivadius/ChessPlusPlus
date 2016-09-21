#include <iostream>
#include <string>
#include "piece.h"
#include <cstdlib>
using namespace std;

int main() {
	Piece *p1;
	p1 = new Piece(0);
	p1->printColour();
	cout << "8 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖" << endl;
	cout << "7 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙" << endl;
	cout << "6\n5\n4\n3" << endl;
	// cout << "6 ■ □ ■ □ ■ □ ■ □" << endl;
	// cout << "5 □ ■ □ ■ □ ■ □ ■" << endl;
	// cout << "4 ■ □ ■ □ ■ □ ■ □" << endl;
	// cout << "3 □ ■ □ ■ □ ■ □ ■" << endl;
	// cout << "6 □ □ □ □ □ □ □ □" << endl;
	// cout << "5 □ □ □ □ □ □ □ □" << endl;
	// cout << "4 □ □ □ □ □ □ □ □" << endl;
	// cout << "3 □ □ □ □ □ □ □ □" << endl;
	cout <<	"2 ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟" << endl;
	cout << "1 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜" << endl;
	cout << "  A B C D E F G H" << endl;
	while(true) {
		system("clear");
		cout << "8 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖" << endl;
		cout << "7 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙" << endl;
		cout << "6\n5\n4\n3" << endl;
		cout <<	"2 ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟" << endl;
		cout << "1 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜" << endl;
		cout << "  A B C D E F G H" << endl;
		string var;
		cin >> var;
		cout << var << endl;
	}
	delete p1;
}

