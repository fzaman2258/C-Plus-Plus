#ifndef __MINES_CPP__
#define __MINES_CPP__
#include "mines.h"


Mines::Mines()
{
	Point p('A','A');
	bool status=false;
	double strength=0;
}
Mines::Mines(Point p1, double s)
{
	p=p1;
	status=false;
	strength=s;
}
Mines::~Mines()
{

}
void Mines::setPoint(Point p2)
{
	p=p2;
}
void Mines::setStatus(bool status1)
{
	status=status1;
}
void Mines::setStrength(double intensity)
{
	strength=intensity;
}
Point Mines::getPoint()
{
	return p;
}
bool Mines::getStatus()
{
	return status;
}

double Mines::getStrength()
{
	return strength;
}
void Mines::print()
{
	cout<<"("<<p.GetX()<<" , "<<p.GetY()<<")"<<endl;	
}


#endif
