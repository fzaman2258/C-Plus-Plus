#include <iostream>
using namespace std;

int main()
{

int x,y,z;
cin>>x>>y>>z;
if (x>y)
{
	if(y>z)
	cout<<y<<endl;

    else if(y<z)
    {
    	if (x<z)
    		cout<<x<<endl;
    	else if(x==z)
    		cout<<x<<endl;
    	else if(x>z)
    		cout<<z<<endl;
    }

    else if(y==z)
    {
    	cout<<y<<endl;
    }
}

if(x<y)
{
	if(x>z)
		cout<<x<<endl;

    else if(x<z)
    {
    	if (y<z)
    		cout<<y<<endl;
    	else if(y==z)
    		cout<<y<<endl;
    	else if(y>z)
    		cout<<z<<endl;
    }

    else if(x==z)
    {
    	cout<<x<<endl;
    }
}

if(x==y)
	cout<<y<<endl;


	return 0;
}