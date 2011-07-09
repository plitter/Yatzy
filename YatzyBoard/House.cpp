#include <algorithm>

#include "House.h"

// Calculate points
void House::getValue(vector<int> values) {
	int value1 = 0;
	int value2 = 0;
	int numberAlike = 3;
	int numberTaken;

	// Checks if there are 3 alike and saves value
	for(int i = values.size(); i > 0; i--) {
		if ((int) count(values.begin(), values.end(), i) >= numberAlike) {
			numberTaken = i;
			value1 = i*numberAlike;
			break;
		}
	}
	numberAlike = 2;

	// Checks if there are 2 alike and saves value
	for(int j = values.size(); j > 0; j--) {
		if ( numberTaken == j ) { continue; }
		if ((int) count(values.begin(), values.end(), j) >= numberAlike) {
			value2 = j*numberAlike;
			break;
		}
	}

	// Checks that there was 3 and 2 alike and if they are saves those 
	// else set points to 0.
	if (value2 != 0 && value1 != 0) { this->setPoints(value1 + value2); }
	else { this->setPoints(0);}
}
