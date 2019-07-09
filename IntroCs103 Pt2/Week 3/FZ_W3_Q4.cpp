#include <iostream>
using namespace std;

void negrotate(char Ar[][2])
{
	
	char store=Ar[0][0];
	Ar[0][0]=Ar[1][0];
	Ar[1][0]=Ar[1][1];
	Ar[1][1]=Ar[0][1];
	Ar[0][1]=store;
}



void posrotate(char Ar[][2])
{
	
	char store=Ar[0][0];
	Ar[0][0]=Ar[0][1];
	Ar[0][1]=Ar[1][1];
	Ar[1][1]=Ar[1][0];
	Ar[1][0]=store;
}



int main()
{
	int size=2, rotation;
	char Ar[2][2];
	char temp;
	cout<<"Enter characters \n";
	cin>>temp;
	Ar[0][0]=temp;
	cin>>temp;
	Ar[0][1]=temp;
	cin>>temp;
	Ar[1][0]=temp;
	cin>>temp;
	Ar[1][1]=temp;
	cout<<"Enter the number of rotations \n";
	cin>>rotation;

	if (rotation>0)
	{
		for(int i=0; i<rotation; i++)
		{
			posrotate(Ar);
		}
		for(int x=0; x<size; x++)
		{
			for(int y=0; y<size;y++)
			{
				cout<<x<<","<<y<<"\t"<<Ar[x][y];
				cout<<endl;
			}
		}
	}

	else if(rotation<0)
	{	rotation=rotation *-1;
		for(int i=0; i<rotation; i++)
		{
			negrotate(Ar);
		}
		for(int x=0; x<size; x++)
		{
			for(int y=0; y<size;y++)
			{
				cout<<x<<","<<y<<"\t"<<Ar[x][y];
				cout<<endl;
			}
		}
	}


	return 0;
}