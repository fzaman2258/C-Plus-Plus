#include <iostream>
#include <string>
using namespace std;



string tensplace(int place)
{
	switch(place)
	{
		case 9:
			return"Ninety"; 
			break;
		case 8:
			return"Eighty"; 
			break;
		case 7:
			return"Seventy";
			break;
		case 6:
			return"Sixty";
			break;
		case 5:
			return"Fifty";
			break;
		case 4:
			return"Fourty";
			break;
		case 3:
			return"Thirty";
			break;
		case 2:
			return"Twenty";
			break;
		case 1:
			return"";
			break;
		case 0:
			return"";
			break;


	}
}

string onesplace(int place)
{
	switch(place)
	{
		case 9:
			return "-nine";
			break;
		case 8:
			return "-eight";
			break;
		case 7:
			return "-seven";
			break;
		case 6:
			return"-six";
			break;
		case 5:
			return"-five";
			break;
		case 4:
			return"-four";
			break;
		case 3:
			return"-three";
			break;
		case 2:
			return"-two";
			break;
		case 1:
			return"-one";
			break;
		case 0:
			return"";
			break;
	}
}
string teens(int place)
{
	switch (place)
	{
		case 19:
			return"Nineteen";
			break;
		case 18:
			return"Eighteen";
			break;
		case 17:
			return"Seventeen";
			break;
		case 16:
			return"Sixteen";
			break;
		case 15:
			return"Fifteen";
			break;
		case 14:
			return"Fourteen";
			break;
		case 13:
			return"Thirteen";
			break;
		case 12:
			return"Twelve";
			break;
		case 11:
			return"Eleven";
			break;
		case 10:
			return"Ten";
			break;
	}
}
string ones(int place)
{
	switch(place)
	{
		case 9:
			return "Nine";
			break;
		case 8:
			return "Eight";
			break;
		case 7:
			return "Seven";
			break;
		case 6:
			return"Six";
			break;
		case 5:
			return"Five";
			break;
		case 4:
			return"Four";
			break;
		case 3:
			return"Three";
			break;
		case 2:
			return"Two";
			break;
		case 1:
			return"One";
			break;
		case 0:
			return"";
			break;
	}
}


int main()
{
	int onesdigit,tensdigit,teeens,twos;
	
	for(int i=99;i>=20;i--)
	{
		onesdigit= i%10;
		tensdigit=i/10;
		cout<<tensplace(tensdigit)<<onesplace(onesdigit)<<" bottles of beer on the wall. \n";
		cout<<tensplace(tensdigit)<<onesplace(onesdigit)<<" bottles of beer, \n"<<"Take one down, pass it around, \n";
	}

	for(int i=19;i>=10;i--)
	{
		teeens=i;
		cout<<teens(teeens)<<" bottles of beer on the wall. \n";
		cout<<teens(teeens)<<" bottles of beer, \n"<<"Take one down, pass it around, \n";
	}
	for(int i=9;i>=0;i--)
	{
			if (i==0)
		{
			cout<<"Zero bottles of beer on the wall. \n";
		}

			else if(i==1)
		{
			cout<<"One bottle of beer on the wall. \n"
				<<"One bottle of beer, \n"
				<<"Take one down, pass it around, \n";
		}

			else 
		{
			twos=i;
			cout<<ones(twos)<<" bottles of beer on the wall, \n";
			cout<<ones(twos)<<" bottles of beer, \n"<<"Take one down, pass it around, \n";
		}	
	}

	


	return 0;
}

