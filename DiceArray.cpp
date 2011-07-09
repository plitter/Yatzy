#include <iostream>

#include "DiceArray.h"

using namespace std;

// It's not possible to call a constructor in a constructor.
// DiceArray::DiceArray() {
//	DiceArray(6, 6);
//}

// Constructor.
DiceArray::DiceArray(int numberOfDice, int sides) {

	// Sets standard values for status and values
	for(int i = 0; i<numberOfDice; i++) {
		status.push_back(false);
		values.push_back(0);
	}

	// Sets number of sides on dice
	dice.setSides(sides);	

	// Tells the class the number of dice we have
	this->numberOfDice= numberOfDice;
}

// Get new values for the values you dont want to keep.
void DiceArray::throwDice() {

	// Goes through the vector
	for(unsigned int j = 0; j < status.size(); j++) {

		// If the the status for the vector is false
		// then we throw the dice
		if ( status[j] == false ) {
			values[j] = dice.getValue();
		}
	}
}

// Returns the vector values
vector<int> DiceArray::getValues() { return values; }

// This function we made in case we would have to make it a game, on second
// thought it might be better to just make a function that prints it out.
vector<bool> DiceArray::getStatus() { return status;}

// The next 2 functions we made in case we would have to make a game of it.
void DiceArray::keep(int index) { status[index] = true; }

void DiceArray::dismiss(int index) { status[index] = false; }

// This one we made like this cause it would be silly to make for individual
// cases like keepTwo, keepThree and so on. Returns the index so it knows 
// where to continue searching for a value.
int DiceArray::keepOneNumber(int number, int index) {
	for (int i = index; i< values.size(); i++) {
		if (values[i] == number) {
			keep(i);
			return ++i;
		}
	}
}

// Keeps all the occurences of a number. Made for the keep FirstSix.
void DiceArray::keepNumber(int number) {
	for (unsigned int i = 0; i < values.size(); i++) {
		if (values[i] == number) {
			this->keep(i); 
		}
	}
}

// Opposite of the above except it is not in use.
void DiceArray::dismissNumber(int number) {
	for (unsigned int i = 0; i < values.size(); i++) {
		if (values[i] == number) { this->dismiss(i); }
	}
}

// Sets every status to false so all dices will be judged the same.
void DiceArray::reset() {
	for (unsigned int i = 0; i < values.size(); i++) {
		dismiss(i);
	}
}

// Nice way of checking that a function does what we want it to do.
void DiceArray::printState() {
	for (unsigned int i = 0; i < values.size(); i++) {
		cout << values[i] << ":"<< status[i] << " "; 
//		cout << values[i] << " ";
	}
	cout << endl;
}
