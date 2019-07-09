#include <iostream>
using namespace std;
/*
void swap (int &x, int &y)
{
	int temp=x;
	x=y;
	y=temp;
}


int main()
{
	int maxsize=50, size=0, temp;
	int ar[maxsize];
	do{
		cin>>temp;
		ar[size]=temp;
		size++;
	}while(temp!=0);
	size=size-1;

	for (int i=1;i<size;i++)
	{
		for(int j=i-1; j>=0;j--)
		{
			if (ar[j]>ar[j+1])
			{
				swap(ar[j],ar[j+1]);
			}
		}
	}
	for(int i=0; i<size; i++)
	{
		cout<<ar[i]<<endl;
	}



	return 0;
}
*/

int main()
{

int a=0,b=1;
int &c=a;
c=2;
cout<<a<<"\t"<<b<<"\t"<<c<<endl;
int *d=&b;
cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<*d<<"\t"<<&b<<endl;
b=3;
cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<*d<<"\t"<<&b<<endl;
*d=10;
cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<*d<<"\t"<<&b<<endl;

return 0;
}