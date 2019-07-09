#include <iostream>
using namespace std;

int main()
{
   for(int i=0;i<101;i++)
   {
   	cout<<i;

   	if(i%3==0)
   	{
   		cout<<"Fizz";
   	}
   	if(i%5==0)
   	{
   		cout<<"Buzz";
   	}

   	cout<<endl;

   }





	return 0;
}