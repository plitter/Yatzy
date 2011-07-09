#ifndef ALIKE_H
#define ALIKE_H

#include <vector>

#include "PointClass.h"
using namespace std;

// Knows how many alike you need to get points. Also calculates the points.
// Inherits all the functions from PointClass
class Alike : public PointClass {
	private:
		int numberAlike;
	public:
		Alike();
		Alike(int);
		void getValue(vector<int>);
		void setNumberAlike(int);
};

#endif
