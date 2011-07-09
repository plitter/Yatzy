#ifndef POINTCLASS_H
#define POINTCLASS_H

/* MotherClass of the different points you can get. All the functions here 
 * are inherited in all of the different classes in this folder. 
 * I also made it possible to pluss to objects of this class to get the 
 * sum of points between the two. The rest is basic functions.
 */
class PointClass {
	protected:
		bool status; 
		int points;
	public:
		PointClass();
		void taken();
		void reset();
		bool getStatus();
		int operator+ (PointClass);
		void setPoints(int);
		int getPoints();
		static int global_points;
};

#endif
