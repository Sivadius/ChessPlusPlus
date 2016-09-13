#include <iostream>
#include <string>
#include "piece.h"
using namespace std;

int main() {
	Piece *p1;
	p1 = new Piece(0);
	p1->printColour();
	delete p1;
}