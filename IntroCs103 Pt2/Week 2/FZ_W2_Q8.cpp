#include <iostream>
using namespace std;

string quadrant(int x, int y)
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

int main()
{

int x,y;
cout<<"Enter x and y coordinates: \n";
cin>>x>>y;
string answer=quadrant(x,y);
cout<<answer<<endl;


	return 0;
}