#include <iostream>
using namespace std;

int recursive(int n)
{
	if(n==1)
	{
		return n;
	}

	return recursive(n-1)+n;
}

int iterative(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=i;
	}
	return sum;
}



int main()
{
	int answer,sum,n;
	cout<<"What is the nth triangle number you want to find? \n";
	cin>>n;
	sum=recursive(n);
	answer=iterative(n);
	cout<<"Using recursive function is "<<sum<<endl<<"Using the iterative function "<<answer<<endl;
	


	return 0;
}