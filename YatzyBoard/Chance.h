#ifndef CHANCE_H
#define CHANCE_H

#include <vector>

#include "PointClass.h"
using namespace std;

// Calculates the points for chance. Inherits all functions from PointClass.
class Chance : public PointClass {
	public:
		void getValue(vector<int>);
};
#endif
