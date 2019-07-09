
#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
//#include <string>
using namespace std;

class Point
{
	private:
		double x;
		double y;
	public:
		
		Point();
		Point(double x1, double y1);
		~Point();
		void SetX(double x1);
		void SetY(double y1);
		double GetX();
		double GetY();
		void Print();
		string Quadrant();
		Point operator + (Point pt2);
		Point operator - (Point pt2);
		friend istream& operator >> (istream& input, Point& pt4);
		friend ostream& operator << (ostream& output, Point& pt4);
		
};
	





#endif