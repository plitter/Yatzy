#ifndef FIRSTSIX_H
#define FIRSTSIX_H

#include <vector>
#include "PointClass.h"
using namespace std;

// Knows what number you get points for, calculates them and has a static 
// points value that makes it easier to check if you get bonus.
// Inherits all functions from PointClass
class FirstSix : public PointClass {
	private: 
		int number;
	public:
		FirstSix();
		FirstSix(int);
		void getValue(vector<int>);
		void setNumber(int);
		static int sumPoints;
};

#endif
