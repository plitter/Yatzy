#ifndef DICE_H
#define DICE_H

// This is the class for the Dice, pretty self explanatory.
class Dice {	
	private:
		int sides;
	public:
		Dice();
		Dice(int);
		int getValue();
		int getSides();
		void setSides(int);
};
#endif
