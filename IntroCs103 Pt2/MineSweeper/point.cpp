#ifndef __POINT_CPP__
#define __POINT_CPP__
#include "point.h"


Point::Point()
{
	x='A';
	y='A';
}

Point::Point(char x1, char y1)
{
	x=x1;
	y=y1;
}
Point::~Point()
{

}
void Point::SetX(char x1)
{
	x=x1;
}
void Point::SetY(char y1)
{
	y=y1;
}
char Point::GetX()
{
	return x;
}
char Point::GetY()
{
	return y;
}

istream& operator >> (istream& input, Point& pt4)			// overload the operator
{
	input>>pt4.x>>pt4.y;
	return input;
}
ostream& operator << (ostream& output,const Point& pt4)
{;
	output<<"("<<pt4.x<<", "<<pt4.y<<")"<<endl;
	return output;
}

bool Point::operator ==(Point pt2)
{
	if(x==pt2.GetX() && y==pt2.GetY())
		return true;
	else 
		return false;
}

		
#endif
