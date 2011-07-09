#include "Chance.h"

// Adds all the values from dicearray together.
void Chance::getValue(vector<int> values) {
	int value = 0;
	for (unsigned int i = 0; i<values.size(); i++) {
		value += values[i];
	}
	this->setPoints(value);
}
