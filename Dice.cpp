#include <ctime>
#include <cstdlib>

#include "Dice.h"

/* To get a random value in c++ we have a function that is called rand,
 * for rand to not give the same value every time we run it we must 
 * make it calculate the time from 1970 in seconds, and use this as a way
 * to get a random input for the random function. This is implemented with
 * the srand(time(0)). */


// Constructor that initialize the dice with a seed.
Dice::Dice() { 
	srand(time(0));
	sides = 6; 
}

// Constructor that initialize the dice with a seed
Dice::Dice(int a) { 
	srand(time(0));
	sides = a; 
}

// Returning a random value.
int Dice::getValue() { 

	// Uses the rand() function to get a random number.
	int value = rand() % sides + 1;
	return value;
}

// Returning the number of sides of the dice.
int Dice::getSides() { return sides; }

// Set number of sides on dice.
void Dice::setSides(int sides) { this->sides = sides; }
