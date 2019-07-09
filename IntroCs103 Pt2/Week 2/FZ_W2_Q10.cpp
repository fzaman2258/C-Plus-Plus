#include <iostream>
using namespace std;

void change(int dollars, int &hundreds, int &fifties, int &twenties, int&tens, int &fives, int&ones)
{
	int z=dollars;
	int count=0;
	int place=1;
	int y;
	int a=dollars;


 	for(int i=99;i>0;i--)
 {		

 		if(dollars>=100)
 		{
 			hundreds=a/100;
 			//cout<<a<<endl;
 			dollars=dollars-(100*hundreds);
 			//cout<<dollars<<endl;
 			a=dollars;
 			//cout<<a<<endl;
 			
 		}
 		else if(dollars>=50)
 		{
 			fifties=a/50;
 			dollars=dollars-(50*fifties);
 			a=dollars;
 		}
 		else if(dollars>=20)
 		{
 			twenties=a/20;
 			dollars=dollars-(20*twenties);
 			a=dollars;
 		}
 		else if(dollars>=10)
 		{
 			tens=a/10;
 			dollars=dollars-(10*tens);
 			a=dollars;
 		}
 		else if(dollars>=5)
 		{
 			fives=a/5;
 			dollars=dollars-(5*fives);
 			a=dollars;
 		}
 		else if (dollars>=1)
 		{
 			ones=dollars;
 		}

}
}
int main()
{
	int dollars, hundreds=0, fifties=0, twenties=0, tens=0, fives=0, ones=0;
	cout<<"Enter the amount of dollars \n";
	cin>>dollars;

	change(dollars, hundreds, fifties, twenties, tens, fives, ones);
	cout<<hundreds<<" hundreds"<<endl
		<<fifties<<" fifties"<<endl
		<<twenties<<" twenties"<<endl
		<<tens<<" tens"<<endl
		<<fives<<" fives"<<endl
		<<ones<<" ones"<<endl;



	return 0;
}