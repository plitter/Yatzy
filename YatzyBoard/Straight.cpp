#include <algorithm>
#include <iostream>
#include "Straight.h"

using namespace std;

// Constructors
Straight::Straight() {}

Straight::Straight(int start, int stop) {
	this->start = start;
	this->stop = stop;
}

// Calculate points
void Straight::getValue(vector<int> values) {
	int value = 0;
	int numberOfHits = 0;
	int numberRequired = stop - start + 1;

	// Checks to see if we meet all the values we need.
	for (int i = start; i <= stop; i++) {
		value+=i;

		// If there is more than one hit on we add one to number of hits
		if ((int) count(values.begin(), values.end(), i) > 0) {
			numberOfHits++;
		}
	}

	// If we have required number of hits then we get value 
	if (numberOfHits >= numberRequired) { 
		this->setPoints(value); 
	}

	// Else we have 0 points
	else { this->setPoints(0); }
}

void Straight::setRange(int start, int stop) {
	this->start = start;
	this->stop = stop;
}
