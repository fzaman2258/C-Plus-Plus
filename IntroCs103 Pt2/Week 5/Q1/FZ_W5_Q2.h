#ifndef __LINE__H_
#define __LINE__H_

#include "FZ_W5_Q1.h"

class Line
{
	private:
		Point p1;
		Point p2;
		double slope;
		double length;
	public:
		Line();
		Line(Point p, Point p3);
		void Setp1(Point p);
		void Setp2(Point p);
		void Setslope(double x);
		void Setlength(double x);
		Point Getp1();
		Point Getp2();
		double Getslope();
		double Getlength();
		bool parallel(Line l2);
		bool operator <(Line l2);
		bool operator >(Line l2);
		void print();





};





#endif