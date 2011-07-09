#include "PointClass.h"

// Initializing global_points.
int PointClass::global_points=0;

// Initialize the standard values for PointClass
PointClass::PointClass() {
	status = false;
	points = 0;
}

void PointClass::taken() { status = true; }

bool PointClass::getStatus() { return status; }

void PointClass::setPoints(int points) { 
	this->points = points;
	global_points +=points;
	this->taken();
}

int PointClass::getPoints() { return points; }

// Makes it possible to pluss two objects that has inherited from PointClass
// and it returns the sum of points of the two objects.
int PointClass::operator+ (PointClass data) {
	int temp = this->points + data.getPoints();
	return temp;
}

// Resets the values of PointClass.
void PointClass::reset() {
	status = false;
	points = 0;
}
