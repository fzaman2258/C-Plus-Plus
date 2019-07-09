#include <iostream>
using namespace std;


void posrotate(char Ar[][50],int size)
{
	int store=size;
	
	int x=0,y=1;
	for (int z=0; z<store/2; z++)
	{
		


		char temp=Ar[x][y-1];
		for (int i=x; i<size;i++)
		{
			Ar[x][i]=Ar[x][i+1];
		}
		for(int i=x;i<size;i++)
		{
			Ar[i][size-1]=Ar[i+1][size-1];
		}
		for(int i=size-1;i>=x;i--)
		{
			Ar[size-1][i]=Ar[size-1][i-1];
		}
		for(int i=size-1;i>=y;i--)
		{
			Ar[i][x]=Ar[i-1][x];
		}
		Ar[y][x]=temp;

		x++;
		y++;
		size--;


	}

}



void negrotate(char Ar[][50],int size)
{
	
	int store=size;
	
	int x=0,y=1;
	for (int z=0; z<store/2; z++)
	{
		


		char temp=Ar[x][y-1];

		for(int i=x;i<size;i++)
		{
			Ar[i][x]=Ar[i+1][x];
		}
		for(int i=x;i<size;i++)
		{
			Ar[size-1][i]=Ar[size-1][i+1];
		}
		for(int i=size-1;i>=x;i--)
		{
			Ar[i][size-1]=Ar[i-1][size-1];
		}
		

		for (int i=size-1;i>=y;i--)
		{
			Ar[x][i]=Ar[x][i-1];
		}
		
		
		Ar[x][y]=temp;

		x++;
		y++;
		size--;


	}

}





int main()
{
	const int Maxsize=50 ;
	int rotation,size=0;
	char Ar[Maxsize][Maxsize];
	char temp;
	cout<<"Enter size of NxN matrix \n";
	cin>>size;
	cout<<"Enter characters \n";
	
	
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			cin>>temp;
			Ar[i][j]=temp;
			
			
		}
		
	}

	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)	//Make sure we are starting off with the correct matrix
		{ 
			cout<<Ar[i][j];
		}
		cout<<endl;
	}

	cout<<"Enter the number of rotations \n";
	cin>>rotation;


	if (rotation>0)
	{
		for(int i=0; i<rotation; i++)
		{
			posrotate(Ar,size);
		}
		for(int x=0; x<size; x++)
		{
			for(int y=0; y<size;y++)
			{
				cout<<Ar[x][y];
				
			}
			cout<<endl;
		}
	}

	else if(rotation<0)
	{	rotation=rotation *-1;
		for(int i=0; i<rotation; i++)
		{
			negrotate(Ar,size);
		}
		for(int x=0; x<size; x++)
		{
			for(int y=0; y<size;y++)
			{
				cout<<Ar[x][y];	
			}
			cout<<endl;
		}
	}
	


	return 0;
}