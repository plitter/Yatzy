#ifndef YATZY_H
#define YATZY_H

#include <vector>

#include "PointClass.h"

using namespace std;

// Calculate points
// Inherits all functions from PointClass
class Yatzy : public PointClass {
	public:
		void getValue(vector<int>);
};

#endif
