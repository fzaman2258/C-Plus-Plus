#include <iostream>
using namespace std;

int main()
{
   int x,y,z;
   cin>>x>>y>>z;
if(x>y)
{
	if (y>z)
	{
		cout<<z<<endl;
	}

	else if (z>y)
	{
		cout<<y<<endl;
	}
	else
	{
		cout<<y<<endl;
	}
}

else if(x<y)
{

	if (x>z)
	{
		cout<<z<<endl;
	}

	else if (z>x)
	{
		cout<<x<<endl;
	}
	else
	{
		cout<<x<<endl;
	}
}

else if(x=y)
{
	if(x<z)
	{
		cout<<x<<endl;
	}
	else if(z<x)
	{
		cout<<z<<endl;
	}
	else
	{
		cout<<z<<endl;
	}
}




	return 0;
}