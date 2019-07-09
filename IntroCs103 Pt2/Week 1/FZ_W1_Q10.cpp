#include<iostream>
using namespace std;

int main()
{
	cout<<"Enter a number 1-4 to select an option \n"
		<<"1) Calculate the area for a circle \n"
		<<"2) Calculate the area for a triangle \n"
		<<"3) Calculate the area for a square \n"
		<<"4) Calculate the area for a rectangle \n" ;
int x;
cin>>x;

	if (x==1)
	{
		cout<<"Enter radius \n";
		double r;
		cin>>r;
		double A=(r*r*3.14);
		cout<<A<<endl;
		
	}

	else if(x==2)
	{
		cout<<"Enter base and height \n";
		double b,h;
		cin>>b>>h;
		cout<<b*h/2<<endl;
	}

	else if(x==3)
	{
		cout<<"Enter base \n";
		double b;
		cin>>b;
		cout<<b*b<<endl;
	}

	else if(x==4)
	{
		cout<<"Enter base and height \n";
		double b,h;
		cin>>b>>h;
		cout<<b*h<<endl;
	}
	else
	{
		cout<<"Invalid choice. \n";
	}

	return 0;
}