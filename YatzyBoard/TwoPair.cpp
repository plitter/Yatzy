#include <algorithm>

#include "TwoPair.h"

// Calculates points
void TwoPair::getValue(vector<int> values) {
	int value1 = 0;
	int value2 = 0;
	int i = 6;

	// Finds two alike and stores the value of dice that has 2 alike
	int numberAlike = 2;
	for(i; i > 0; i--) {
		if ((int) count(values.begin(), values.end(), i) == numberAlike) {
			value1 = i*numberAlike;
			break;
		}
	}

	// When we broke out of the loop we stop at the value that had 2 alike, 
	// but since that is already taken we reduce i with one.
	
	i--;

	// Finds the next 2 alike.
	for(i; i > 0; i--) {
		if ((int) count(values.begin(), values.end(), i) == numberAlike) {
			value2 = i*numberAlike;
			break;
		}
	}

	// Sets value if we have 2 pairs else sets 0 points
	if (value2 != 0) { this->setPoints(value1 + value2); }
	else { this->setPoints(0);}
}
