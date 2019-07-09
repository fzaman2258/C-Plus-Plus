#include <iostream>
using namespace std;

int main()
{
	unsigned int b,n;
	cout<<"Enter a base and an exponent \n";
	cin>>b>>n;
	int product=1;
	if(n==0)
	{
		cout<<1<<endl;
	}

	else
	{
	for (int y=0;y<n;y++)
	{
			product*=b;

	}

		cout<<product<<endl;
	}





	return 0;
}