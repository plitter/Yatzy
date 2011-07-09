#ifndef YATZYBOARD_H
#define YATZYBOARD_H

#include <vector>

#include "YatzyBoard/FirstSix.h"
#include "YatzyBoard/Alike.h"
#include "YatzyBoard/TwoPair.h"
#include "YatzyBoard/Yatzy.h"
#include "YatzyBoard/House.h"
#include "YatzyBoard/Straight.h"
#include "YatzyBoard/Chance.h"

using namespace std;

// Self explanatory, just a way to keep track of the different values.
// It also provides a way to check for the bonus and reset the values.
class YatzyBoard {
	public:
		vector<FirstSix> firstsix;
		int Bonus;
		vector<Alike> alike;
		TwoPair twopair;
		House house;
		vector<Straight> straight;
		Chance chance;
		Yatzy yatzy;
		YatzyBoard();
		void bonusCheck();
		int finalPoints();
		void reset();
	};

#endif
