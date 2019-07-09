#ifndef __LINE__CPP_
#define __LINE__CPP_


#include "FZ_W5_Q2.h"
#include <cmath>


Line::Line()
{
	slope=0;
	length=0;
}
Line::Line(Point p, Point p3)
{
	p1=p;
	p2=p3;
	slope=(p1.GetY()-p2.GetY())/(p1.GetX()-p2.GetX());
	length= sqrt(
			( p1.GetY()-p2.GetY() ) *( p1.GetY()-p2.GetY()   ) +  ( p1.GetX()-p2.GetX() ) *( p1.GetX()-p2.GetX() )  
			);

} 
void Line::print()
{
	slope=(p1.GetY()-p2.GetY())/(p1.GetX()-p2.GetX());
	length= sqrt(
			( p1.GetY()-p2.GetY() ) *( p1.GetY()-p2.GetY()   ) +  ( p1.GetX()-p2.GetX() ) *( p1.GetX()-p2.GetX() )  
			);
	cout<<p1;
	cout<<p2;
	cout<<"Slope = "<<slope<<endl<<"Length = "<<length<<endl;

}

void Line::Setp1(Point p)
{
	p1=p;
}
void Line::Setp2(Point p)
{
	p2=p;
}
void Line::Setslope(double x)
{
	slope=x;
}
void Line::Setlength(double x)
{
	length=x;
}
Point Line::Getp1()
{
	return p1;
}
Point Line::Getp2()
{
	return p2;
}
double Line::Getslope()
{
	return slope;
}
double Line::Getlength()
{
	return length;
}

bool Line::parallel(Line l2)
{
	if(slope==l2.slope)
	{
		return true;
	}
	else
		return false;
}
bool Line::operator <(Line l2)
{
	if(length<l2.length)
	{
		return true;
	}
	return false;
}
bool Line::operator >(Line l2) 
{
	if(length>l2.length)
	{
		return true;
	}
	return false;
}








#endif 