#include <iostream>
using namespace std;

int pow2(int b, int n)
{


	int product=1;

	for (int y=0;y<n;y++)
	{
			product=product*b;

	}

		return product;
}






int main()
{

	unsigned int b,n;
	cout<<"Enter a base and an exponent \n";
	cin>>b>>n;

	int answer=pow2(b,n);
	cout<<answer<<endl;


	return 0;
}