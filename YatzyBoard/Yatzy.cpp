#include <algorithm>

#include "Yatzy.h"

// Calculates points
void Yatzy::getValue(vector<int> values) {
	int numberAlike = 6;
	int value = 0;
	int i = 6;

	// Checks if we have 6 alike
	for(i; i > 0; i--) {
		if ((int) count(values.begin(), values.end(), i) == numberAlike) {
			value = 100;
			break;
		}
	}

	this->setPoints(value);
}
