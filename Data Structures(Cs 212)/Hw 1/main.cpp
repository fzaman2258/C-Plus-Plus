#include "Zaman_Farhan_HW1.h"
using namespace std;
int main()
{
	Point p1;
	cout<<"this is default constructor= "; p1.print();
	Point p2(0,2);
	cout<<"this is we dont input z it is 0= ";	p2.print();
	Point p3(2,2,2);
	cout<<"this is when we input all 3= "; p3.print();
	p1.setX(1);
	p1.setY(1);
	p1.setZ(1);
	cout<<"this is set x, set y, set z functions= "; p1.print();
	p1.setXY(2,2);
	cout<<"this is setxy="; p1.print();
	p1.setXYZ(3,3,3);
	cout<<"this is setxyz="; p1.print();
	double dummyx=p1.getX();
	cout<<"this is get x function= "<<dummyx<<endl;
	double dummy2=p1.getY();
	cout<<"this is get y function= "<<dummy2<<endl;
	double dummy3=p1.getZ();
	cout<<"this is get z function= "<<dummy3<<endl;

	cout<<"this is distance from origin function= "<<p2.distance()<<endl;
	cout<<"this is overloaded distance= "<<p1.distance(p2)<<endl;
	cout<<"are these on a line? true=1 false=0 : "<<p1.line(p3)<<endl;
	cout<<"this is cross product = ";
	Point crossproduct=p1.cross(Point(1,2,3));
	crossproduct.print();
	
	cout<<"this is adding points ";
	(Point(2,2.2,2.0)+Point(1,1.3,1)).print();

	cout<<"this is subtracting ";
	(Point(2,2.2,2.0)-Point(1,1.1,1)).print();
	cout<<" please gimme a dummy \n";
	Point dummy;
	cin>>dummy;
	cout<<"this is overloaded operator = "<<dummy;

	Point Ar[]={Point(1,1,1),Point(0.5,1.5,1),Point(0.5,0.5,2)};
	cout<<"this is plane true=1 false=0 :"<<plane(Ar,Point(3,0,0))<<endl;

	cout<<"are any 4 combos of these square:";
	Point Square[]={Point(0,0,0),Point(1,0,0),Point(0,1,0),Point(1,1,0)};
	cout<<square(Square,4)<<"\n";

	Point Square1[]={Point(0,0,0),Point(4.1,8.4,9.7),Point(5,0,0),Point(1,2,3),Point(0,5,0),Point(6,6,6),Point(5,5,0)};
	cout<<square(Square1,7)<<"\n";

	Point Square2[]={Point(20,20,0),Point(10,20,0),Point(0,20,0),Point(10,20-sqrt(200),0)};
	cout<<square(Square2,4)<<"\n";

	Point Square3[]={Point(1,1,0),Point(3,5,0),Point(7,7,0),Point(5,3,0),Point(100,20,0)};
	cout<<square(Square3,5)<<"\n";

	cout<<"this is centroid="<<centroid(Square,4)<<endl;

	return 0;
}