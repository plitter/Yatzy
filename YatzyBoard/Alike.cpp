#include <algorithm>

#include "Alike.h"

Alike::Alike() {}

Alike::Alike(int numberAlike) { this->numberAlike = numberAlike; }

// Calculates points.
void Alike::getValue(vector<int> values) {
	int value = 0;

	// It goes from 6 to 1 so that we won't have to check that the value we
	// get is the highest.
	for(int i = 6; i > 0; i--) {
		if ((int) count(values.begin(), values.end(), i) >= numberAlike) {
			value = i*numberAlike;
			break;
		}
	}
	this->setPoints(value);
}

// Sets how many numbers you need alike.
void Alike::setNumberAlike(int numberAlike) { this->numberAlike = numberAlike; }
