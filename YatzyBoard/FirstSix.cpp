#include <algorithm>
#include <vector>

#include "FirstSix.h"

using namespace std;

FirstSix::FirstSix() {};

FirstSix::FirstSix(int number) {this->number = number;}

// Initializing the static value.
int FirstSix::sumPoints=0;

void FirstSix::setNumber(int number) { this->number = number; }

// Calculates the value.
void FirstSix::getValue(vector<int> values) { 
	int value = (int) count(values.begin(), values.end(), number);
	value *= number;
	this->setPoints(value);
	sumPoints += value;
}


