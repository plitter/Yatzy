#include <iostream> 

#include "YatzyBoard.h"

using namespace std;

// Constructor from what I remember of yatzy.
YatzyBoard::YatzyBoard() {
	Bonus = 0;

	// Make a vector for the first six values of yatzy
	firstsix.resize(6);

	// Initialize the standard values
	for (unsigned int i = 0; i < firstsix.size(); i++) { 
		firstsix[i].setNumber(i+1); 
	}

	// Make a vector for the alike values of yatzy
	alike.resize(3);

	// Initialize the standard values
	for (unsigned int i = 0; i < alike.size(); i++) {
		alike[i].setNumberAlike(i+2);
	}

	// Make a vector for the straight values of yatzy
	straight.resize(3);

	// Initialize the standard values
	straight[0].setRange(1,5);
	straight[1].setRange(2,6);
	straight[2].setRange(1,6);
	}

// Checks if you get the bonus.
void YatzyBoard::bonusCheck() {
	int valueRequired = 0;

	// Finds the value required to get bonus
	for (unsigned int i = 1; i <= firstsix.size(); i++) {
		valueRequired += i*3;
	}
	int value = FirstSix::sumPoints;

	// If the sumPoints are bigger than valuerequired you get the bonus of 50
	if (value >= valueRequired) { 
		Bonus = 50; 
		PointClass::global_points += 50;
	}
}

// Not used, figured that just asking for the global_points directly is just
// as easy.
int YatzyBoard::finalPoints() { return PointClass::global_points; }

// Resets the board.
void YatzyBoard::reset() {
	for (unsigned int i = 0; i < firstsix.size(); i++){ firstsix[i].reset();}
	for (unsigned int i = 0; i < alike.size(); i++) { alike[i].reset();}
	for (unsigned int i = 0; i < straight.size(); i++) { straight[i].reset(); }
	twopair.reset();
	house.reset();
	chance.reset();
	yatzy.reset();
	Bonus = 0;
	PointClass::global_points=0;
	FirstSix::sumPoints = 0;
} 
