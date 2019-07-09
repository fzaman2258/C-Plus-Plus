#ifndef __ZAMAN__FARHAN__HW1_H__
#define __ZAMAN__FARHAN__HW1_H__

#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>

using namespace std;

class Point
{
	private:
		double x;
		double y;
		double z;
	public:
		Point();
		Point(double inX, double inY, double inZ=0);
		Point(const Point& input2);
		void setX(double inX);
		void setY(double inY);
		void setZ(double inZ);
		void setXY(double inX, double inY);
		void setXYZ(double inX, double inY, double inZ);
		double getX() const;
		double getY() const;
		double getZ() const;
		void print();
		double distance();
		double distance(Point pt2);
		bool line(Point pt2);
		Point cross(Point pt2);
		Point operator + (Point pt2);
		Point operator - (Point pt2);
		friend istream& operator >> (istream& input, Point& pt);
		friend ostream& operator << (ostream& output, const Point& pt);
};

	bool plane(Point Ar[], Point pt);
	bool square(Point Ar[], int size);
	Point centroid(Point Ar[], int size);







#endif