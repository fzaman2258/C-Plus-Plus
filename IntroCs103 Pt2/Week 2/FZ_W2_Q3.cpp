#include<iostream>
using namespace std;

int main()
{
	unsigned int n;
	cout<<"Input an exponent with a base of 2 \n";
	cin>>n;
	int product=1;
	if(n==0)
	{
		cout<<1<<endl;
	}

	else
	{
	for (int y=0;y<n;y++)
	{
			product=product*2;

	}

		cout<<product<<endl;
	}

	return 0;
}