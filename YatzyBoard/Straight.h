#ifndef STRAIGHT_H
#define STRAIGHT_H

#include <vector>

#include "PointClass.h"

using namespace std;

// Calculates points and knows where the straight starts and stops.
// Inherits all functions from PointClass.
class Straight : public PointClass {
	private:
		int start, stop;
	public:
		Straight();
		Straight(int, int);
		void getValue(vector<int>);
		void setRange(int, int);
};

#endif
