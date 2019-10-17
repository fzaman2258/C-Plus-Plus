#ifndef __MINES_H__
#define __MINES_H__
#include "point.h"


class Mines
{

	private:
	Point p;
	bool status;
	double strength;

	public:
	Mines();
	Mines(Point p1, double s);
	~Mines();
	void setPoint(Point p2);
	Point getPoint();
	void setStatus(bool status1);
	bool getStatus();
	void setStrength(double intensity);
	double getStrength();
	void print();

};


#endif
