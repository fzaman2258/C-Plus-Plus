#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>

using namespace std;

class Point
{
	private:

		char x;
		char y;
	public:
		
		Point();
		Point(char x1, char y1);
		~Point();
		void SetX(char x1);
		void SetY(char y1);
		char GetX();
		char GetY();
		bool operator == (Point pt2);
		friend istream& operator >> (istream& input, Point& pt4);
		friend ostream& operator << (ostream& output, const Point& pt4);
		
};
	

#endif
