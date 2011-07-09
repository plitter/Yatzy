#ifndef HOUSE_H
#define HOUSE_H

#include <vector>

#include "PointClass.h"

using namespace std;

// Calculates the points for House
// Inherits all functions from PointClass
class House : public PointClass {
	public:
		void getValue(vector<int>);
};

#endif
