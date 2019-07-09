#ifndef __ZAMAN__FARHAN__HW1_CPP__
#define __ZAMAN__FARHAN__HW1_CPP__
#include "Zaman_Farhan_HW1.h"

Point::Point()
{
	x=0;
	y=0;
	z=0;
}

Point::Point(double inX, double inY, double inZ)
{
	x=inX;
	y=inY;
	z=inZ;
}

Point::Point(const Point& input2)
{
	x=input2.getX();
	y=input2.getY();
	z=input2.getZ();
}

void Point::setX(double inX)
{
	x=inX;
}

void Point::setY(double inY)
{
	y=inY;
}

void Point::setZ(double inZ)
{
	z=inZ;
}

void Point::setXY(double inX, double inY)
{
	x=inX;
	y=inY;
}

void Point::setXYZ(double inX, double inY, double inZ)
{
	x=inX;
	y=inY;
	z=inZ;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getZ() const
{
	return z;
}

void Point::print()
{
	cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
}

double Point::distance()
{
	double answer;
	answer=sqrt(x*x+y*y+z*z);
	return answer;
}

double Point::distance(Point pt2)
{
	double newx=(x-pt2.getX())*(x-pt2.getX());
	double newy=(y-pt2.getY())*(y-pt2.getY());
	double newz=(z-pt2.getZ())*(z-pt2.getZ());
	return sqrt(newx+newy+newz);
}

bool Point::line(Point pt2)
{
	double scalar;
	if(x!=0 && pt2.x!=0)
	{
		scalar = pt2.x/x;
		return y*scalar == pt2.y && z*scalar==pt2.z;
	}
	else if(y!=0 && pt2.y!=0)
	{
		scalar = pt2.y/y;
		return x*scalar == pt2.x && z*scalar==pt2.z;
	}
	else if(z!=0 && pt2.z!=0)
	{
		scalar = pt2.z/z;
		return y*scalar == pt2.y && x*scalar==pt2.x;
	}

	return false;

}

Point Point::cross(Point pt2)
{
	Point pt3;
	double inX, inY,inZ;
	inX=(y*pt2.getZ())-(z*pt2.getY());
	inY=-1*((x*pt2.getZ())-( z*pt2.getX()));
	inZ=(x*pt2.getY())-(y*pt2.getX());
	pt3.setXYZ(inX,inY,inZ);
	return pt3;
}

Point Point::operator +(Point pt2)
{
	Point pt3;
	double inX, inY,inZ;
	inX=x+pt2.getX();
	inY=y+pt2.getY();
	inZ=z+pt2.getZ();
	pt3.setXYZ(inX,inY,inZ);
	return pt3;
}

Point Point::operator -(Point pt2)
{
	Point pt3;
	double inX, inY,inZ;
	inX=x-pt2.getX();
	inY=y-pt2.getY();
	inZ=z-pt2.getZ();
	pt3.setXYZ(inX,inY,inZ);
	return pt3;
}

istream& operator >> (istream& input, Point& pt)
{
	input>>pt.x>>pt.y>>pt.z;
	return input;
}

ostream& operator << (ostream& output,const Point& pt)
{
	output<<"("<<pt.x<<","<<pt.y<<","<<pt.z<<")"<<endl;
	return output;
}

bool plane(Point Ar[], Point pt)
{
	Point u,v;
	u=Ar[1]-Ar[0];
	v=Ar[2]-Ar[0];
	Point crossproduct;
	crossproduct=u.cross(v);
	if(crossproduct.getX()*(pt.getX()-Ar[0].getX())+crossproduct.getY()*(pt.getY()-Ar[0].getY())+crossproduct.getZ()*(pt.getZ()-Ar[0].getZ())==0)
	{
		return true;
	}
	return false;
}

bool square(Point Ar[], int size)
{
	for(int i=0; i<size; i++)
	{
		Point pt1=Ar[i];
		for(int j=i+1; j<size; j++)
		{
			Point pt2=Ar[j];
			for(int k=j+1; k<size; k++)
			{
				Point pt3=Ar[k];
				for(int l=k+1; l<size; l++)
				{
					Point pt4=Ar[l];

					double AB,AC,AD,BC,BD,CD;
					AB=pt1.distance(pt2);
					AC=pt1.distance(pt3);
					AD=pt1.distance(pt4);
					BC=pt2.distance(pt3);
					BD=pt2.distance(pt4);
					CD=pt3.distance(pt4);

					

					if(AB==AC && BD==CD && AB==BD && (sqrt(2)*AB)==AD && (sqrt(2)*AB)==BC)
					{
						return true;
					}
					if(AB==AD && BC==CD && AB==CD && (sqrt(2)*AB)==AC && (sqrt(2)*AB)==BD)
					{
						return true;
					}
					if(AC==AD && BC==BD && AC==BC && (sqrt(2)*AC)==AB && (sqrt(2)*AC)==CD)
					{
						return true;
					}

				}
			}
		}
	}
	return false;
}
	
Point centroid(Point Ar[], int size)
{
	Point centroid;
	double subx=0,suby=0,subz=0;
	for(int i=0; i<size; i++)
	{
		subx+=Ar[i].getX();
	}
	for(int i=0; i<size; i++)
	{
		suby+=Ar[i].getY();
	}
	for(int i=0; i<size; i++)
	{
		subz+=Ar[i].getZ();
	}
	centroid.setXYZ(subx/size,suby/size,subz/size);
	return centroid;
}




#endif