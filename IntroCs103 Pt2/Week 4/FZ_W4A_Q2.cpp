#include <iostream>
using namespace std;

int sum(unsigned int x)
{
	int store=0;
	while(x!=0)
	{
		store+=x%10;
		x/=10;

	}
	return store;
}





int main()
{
	int x;
	cout<<"Enter an unsigned integer \n";
	cin>>x;
	int answer=sum(x);
	cout<<"The sum of the digits is "<<answer<<endl;



	return 0;
}