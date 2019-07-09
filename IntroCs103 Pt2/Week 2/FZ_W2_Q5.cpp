#include<iostream>
#include <climits>
using namespace std;

int main()
{



	int small,large,now;
	small= INT_MAX;
	large=INT_MIN;
	cout<<"Enter a series of any integer numbers \n";
	
	
	do
	{
		cin>>now;	
		if(now==99)
		{
			cout<<"The smallest number is "<<small<<endl;
			cout<<"The largest number is "<<large<<endl;
			return 0;
		}
		
	
		if(now<small)
		{
			small=now;
		}

		if(now>large)
		{
			large=now;
		}
		
	}
	while (now!=99);
	


	return 0;
}



