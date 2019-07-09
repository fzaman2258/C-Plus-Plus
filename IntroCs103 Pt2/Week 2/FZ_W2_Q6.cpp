#include <iostream>
using namespace std;

int main()
{

 int x,count=0;
 cout<<"Enter an integer \n";
 cin>>x;
 double y;
 int z=x;
 int product=1;

 do
 {

 	 y=z/10;								//Count the number of places
 	 z=y;
 	 count++;


 } while (z>=1 || z<=-1);
// cout<<count<<endl;  Check if we were counting the number properly


for (int q=0;q<count-1;q++)
	{
			product=product*10;				//Get a number to acces every element

	}
	//cout<<product<<endl;



 for(int i=count;i>0;i--)
 {
 //	for (int a=0;a<count;a++)
//	{		
			if(x<0)
			{
				cout<<"- \n";				// Get rid of negative numbers
				x=x*-1;
			}



			if(product!=0)
			{
				cout<<x/product<<endl;	//Start by accesign the leftmost number which we figured out before
				x=x%product;
				product=product/10;
			}
			
			else
				return 0;
//	}
//	cout << product << endl;  why isn't product working
	
}
 	
 
	return 0;
}