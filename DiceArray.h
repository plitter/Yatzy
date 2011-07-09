#ifndef DICEARRAY_H
#define DICEARRAY_H

#include <vector>

#include "Dice.h"

using namespace std;


/* DiceArray to make an "array" to keep track of values and which values
 * that you keep. Notice it only takes one dice, that is to keep it simple.
 * If you have a lot of different dice it would be better to create 
 * individual arrays or just dice and have different names */
class DiceArray {
	private:
		vector<bool> status;
		vector<int> values;
		Dice dice;
		int numberOfDice;

	public:
		DiceArray();
		DiceArray(int, int);
		void throwDice();
		void keep(int);
		int keepOneNumber(int,int);
		void keepNumber(int);
		void dismiss(int);
		void dismissNumber(int);
		vector<int> getValues();
		vector<bool> getStatus();
		void printState();
		void reset();
	
};
#endif
