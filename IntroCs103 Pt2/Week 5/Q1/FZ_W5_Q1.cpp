#ifndef __POINT_CPP__
#define __POINT_CPP__

#include "FZ_W5_Q1.h"



Point::Point()
{
	x=0;
	y=0;
}

Point::Point(double x1, double y1)
{
	x=x1;
	y=y1;
}
Point::~Point()
{

}
void Point::SetX(double x1)
{
	x=x1;
}
void Point::SetY(double y1)
{
	y=y1;
}
double Point::GetX()
{
	return x;
}
double Point::GetY()
{
	return y;
}
void Point::Print()
{


cout<<"("<<x<<", "<<y<<")"<<endl;

}
string Point::Quadrant()
{

	if(x==0 && y==0)
	{
		return "origin";
	}
	if (y==0)
	{
		return "y-axis";
	}

	if (x==0)
	{
		return "x-axis";
	}
	if(x>0 && y>0)
	{
		return "Quadrant 1";
	}
	if(x<0 && y>0)
	{
		return"Quadrant 2";
	}
	if(x<0 && y<0)
	{	
		return "Quadrant 3";
	}
	if(x>0 && y<0)
	{
		return "Quadrant 4";
	}
}
	Point Point::operator + (Point pt2)
	{
		Point temp;
		temp.SetX(x+pt2.GetX());
		temp.SetY(y+pt2.GetY());
		return temp;
	}
	Point Point::operator - (Point pt2)
	{
		Point temp;
		temp.SetX(x-pt2.GetX());
		temp.SetY(y-pt2.GetY());
		return temp;
	}
	istream& operator >> (istream& input, Point& pt4)
	{
		
		input>>pt4.x>>pt4.y;
		return input;
	}
	ostream& operator << (ostream& output, Point& pt4)
	{;
		output<<"("<<pt4.x<<", "<<pt4.y<<")"<<endl;
		return output;
	}



		

#endif
