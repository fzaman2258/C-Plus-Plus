#include <iostream>
using namespace std;

void sort(int &a, int &b, int &c)
{

	
	if (b<a && c<a)
	{
		int temp=c;
		c=a;
		a=temp;
		
	}
	if(a<b && c<b)
	{
		int temp=c;
		c=b;
		b=temp;
	}
	if(b<a)
	{
		int temp=b;
		b=a;
		a=temp;

	}



}

int main()
{

 int a,b,c;
 cout<<"Enter 3 numbers \n";
 cin>>a>>b>>c;
 sort(a,b,c);
 cout<<a<<"\t"<<b<<"\t"<<c<<endl;



	return 0;
}