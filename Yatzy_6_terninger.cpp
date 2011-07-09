#include <iostream>
#include <algorithm>
#include <fstream>
#include "DiceArray.h"
#include "YatzyBoard.h"

using namespace std;

// Gets the correct values for the first six values
void FirstXs(int number, DiceArray dices, int pos, YatzyBoard * board) {
	
	// Throws dice and keeps the number that we want
	// This loop throw dice 3 times
	for (int i = 1; i <= 3; i++ ) {
		dices.throwDice();
		dices.keepNumber(number);
	}

	// Puts the number value we get on the board.
	// The -> notation is used for the pointer to point at a function in 
	// its class.
	board->firstsix[pos].getValue(dices.getValues());

//	cout << board->firstsix[pos].getPoints() << " : " << PointClass::global_points << endl;
}	

// Returns the highest number with the one closest to number alike
int findHighestNumberValue(int numberAlike, vector<int> notValues, DiceArray * dices, int betterThan) {
	vector<int> tmp = dices->getValues();

	// Checks first for the number alike we need and then one less each time
	// it doesn't find the number we need
	for (int i = numberAlike; i>0; i--) {

		// Checks 6 first and then one less each time, until zero or the 
		// limit, betterThan is reached.
		for (int j = 6; j>0 && j>betterThan; j--) {
			if (count(tmp.begin(), tmp.end(), j) >= i) {

				// If value in notValues, then start next iteration of loop
				// so we won't get the same value again.
				if (binary_search (notValues.begin(), notValues.end(),j)) {
					continue;
				}

				// Reset index
				int index = 0;

				// Keep i values of j
				for (int k = i; k > 0; k--) {
					index = dices->keepOneNumber(j,index);
				}

				// Return j so that we know where to continue in the vector.
				return j;
			}
		}
	}
}

// Gets the correct value of the number of alike
void findAlike(int throws, int numberAlike, int betterThan, DiceArray dices, YatzyBoard * board) {
	DiceArray *pointerDices = &dices;

	// This loop throw dice "throws" number of times
	for (int l = 0; l < throws; l++) {

		// Resets and throwes dice
		vector<int> notValues;
		dices.throwDice();
		dices.reset();

		// Saves the number that is closest to number alike.
		notValues.push_back(findHighestNumberValue(numberAlike, notValues, pointerDices, betterThan));
	}

	// Write value to board.
	board->alike[numberAlike-2].getValue(dices.getValues());
//	cout << board->alike[numberAlike-2].getPoints() << " : " << PointClass::global_points << endl;
}


// Gets the correct value of 2 pairs
void findTwoPair (int throws, int betterThan, DiceArray dices, YatzyBoard * board) {
    
	// Shows how many alike we need.
	int numberAlike1 = 2, numberAlike2 = 2;
    DiceArray * pointerDices = &dices;

	// This loop throw dice "throws" number of times
    for (int l = 0; l < throws; l++) {

		// Resets and throw dice 
        vector<int> notValues;
        dices.throwDice();
        dices.reset();

		// Saves the number that is the closest to number alike
        notValues.push_back(findHighestNumberValue(numberAlike1, notValues,pointerDices, betterThan));

		// Saves the number that is the closest to number alike
        notValues.push_back(findHighestNumberValue(numberAlike2, notValues,pointerDices, betterThan));
    }

	// Writes values to board.
    board->twopair.getValue(dices.getValues());
//    cout << board->twopair.getPoints() << " : " << PointClass::global_points <<  endl;
}


// Gets the correct value of house
void findHouse (int throws, int betterThan, DiceArray dices, YatzyBoard * board) {

	// Shows how many alike we need
    int numberAlike1 = 3, numberAlike2 = 2;
    vector<int> tmp;
	DiceArray * pointerDices = &dices;

	// This loop throw dice "throws" number of times
    for (int l = 0; l < throws; l++) {

		// Throw dice and reset values that we need
		vector<int> notValues;
		dices.throwDice();
		dices.reset();

		// Saves the highest number that is the closest to number alike
		notValues.push_back(findHighestNumberValue(numberAlike1, notValues,pointerDices, betterThan));

		// Saves the highest number that is the closest to number alike
		notValues.push_back(findHighestNumberValue(numberAlike2, notValues,pointerDices, betterThan));
    }

	// Write value to board
    board->house.getValue(dices.getValues());
//    cout << board->house.getPoints() << " : " << PointClass::global_points <<  endl;
}


// Gets the correct value of straight
void findStraight(int throws, DiceArray dices, YatzyBoard * board, int start,int stopp, int whichStraight) {
	
	// This loop throw dice "throws" number of times
	for (int i = 0; i< throws;i++) {

		// Throw dice and reset value
		dices.throwDice();
		dices.reset();

		// Saves the values needed for straight
		for (int j = start; j <= stopp; j++) {
			dices.keepOneNumber(j, 0);
		}
	}

	// Write value to board.
	board->straight[whichStraight].getValue(dices.getValues());
//	cout << board->straight[whichStraight].getPoints() << " : " << PointClass::global_points << endl;
}


// Get a good value for chance
void findChance(DiceArray dices, YatzyBoard * board, int throws, int betterThan) {

	// This loop throw dice "throws" number of times
	for (int i = 0; i < throws; i++) {
		dices.throwDice();

		// This loop keeps the numbers that is higher than betterThan.
		for (int i = 6; i > betterThan; i--) {
			dices.keepNumber(i);
		}
	}

	// Write value to board.
	board->chance.getValue(dices.getValues());
//	cout << board->chance.getPoints() << " : "<< PointClass::global_points << endl;
	
}


// Get yatzy
void findYatzy(int throws, YatzyBoard * board, DiceArray dices) {
    DiceArray *pointerDices = &dices;

	// This loop throw dice "throws" number of times
    for (int l = 0; l < throws; l++) {

		// Throw dice and reset values
        vector<int> notValues;
        dices.throwDice();
        dices.reset();

		// Find highest alike ... Doesn't have to be highest but it 
		// prioritize the most alike before highest
        notValues.push_back(findHighestNumberValue(6, notValues, pointerDices, 0));
    }

	// Write value to board.
    board->yatzy.getValue(dices.getValues());
//    cout << board->yatzy.getPoints() << " : " << PointClass::global_points << endl;
}

// Here it is all put together
int main() {

	// Make output filestream object
	ofstream verdier;

	// Open a file
	verdier.open("YatzyVerdier.txt");

	// Specify number of dice and sides
	int numberOfDice = 6;
	int numberOfSides = 6;

	// Make yatzyboard and a pointer to it.
	YatzyBoard board;
	YatzyBoard * pointerBoard = &board;

	// Make a dicearray and pointer to it.
	DiceArray dices(numberOfDice, numberOfSides);
	DiceArray * pointerDices = &dices;

	// Go through game i number of times.
	for(int i = 0; i<1000000; i++) {

		// Get the values of first six values and write them to the board.
		for (int i = 0; i < numberOfDice; i++) {
			FirstXs(i+1, dices, i, pointerBoard);
		}

		// checks if we get a bonus
		board.bonusCheck();

		// Find alike
		for (int i = 2; i<=4; i++) {
			findAlike(3, i, 0, dices, pointerBoard);
		}

		// Find everything else
		findHouse(3,0,dices, pointerBoard);
		findTwoPair(3,0,dices, pointerBoard);
		findStraight(3,dices, pointerBoard, 1,5,0);
		findStraight(3, dices, pointerBoard, 2,6,1);
		findStraight(3, dices, pointerBoard, 1,6,2);
		findChance(dices, pointerBoard, 3, 3);	
		findYatzy(3, pointerBoard, dices);

		// Writing all the values to file.
		verdier <<
			board.firstsix[0].getPoints() << " " <<
			board.firstsix[1].getPoints() << " " <<
			board.firstsix[2].getPoints() << " " <<
			board.firstsix[3].getPoints() << " " <<
			board.firstsix[4].getPoints() << " " <<
			board.firstsix[5].getPoints() << " " <<
			FirstSix::sumPoints << " " <<
			board.Bonus << " " <<
			board.alike[0].getPoints() << " " <<
			board.alike[1].getPoints() << " " <<
			board.alike[2].getPoints() << " " <<
			board.twopair.getPoints() << " " <<
			board.house.getPoints() << " " <<
			board.straight[0].getPoints() << " " <<
			board.straight[1].getPoints() << " " <<
			board.straight[2].getPoints() << " " <<
			board.yatzy.getPoints() << " " <<
			PointClass::global_points << endl;

		// Reset board
		board.reset();
	}

	// Close output filestream
	verdier.close();
}
