#include<iostream>
using namespace std;

int main()
{
	double x,z;
	

	for (x=1;x<6;x++)
	{
		for(z=2;z<7;z++)
		{
			if(x==z)
			{
				cout<<"Does Not Exist \n";
			}	
			else
			{
				double y=(x*z)/(x-z);
				cout<<"y="<<y<<endl;
			}	
		}
	}





	return 0;
}