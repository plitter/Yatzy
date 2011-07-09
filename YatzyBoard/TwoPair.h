#ifndef TWOPAIR_H
#define TWOPAIR_H

#include <vector>

#include "PointClass.h"

using namespace std;

// Calculates points for two pairs. Same as house.
class TwoPair : public PointClass {
	public:
		void getValue(vector<int>);
};

#endif
