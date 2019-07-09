#include <iostream>
using namespace std;

void shiftneg(string Ar[],int size)
{
	string temp=Ar[0];
	for (int i=1; i<size;i++)
	{
		Ar[i-1]=Ar[i];
		
	}
	Ar[size-1]=temp;
	
	

}

void shiftpos(string Ar[], int size)
{
	string temp=Ar[size-1];
	

	for(int i=size-1;i>0;i--)
	{
		Ar[i]=Ar[i-1]; 
		
	}
	Ar[0]=temp;
	

}


int main()
{
	int MaxSize=50, size=0, spaces;
	string Ar[MaxSize];
	char temp;
	cout<<"Enter characters \n";
	do
	{
		cin>>temp;
		Ar[size]=temp;
		size++;
	}while(temp!='#');
	size=size-1;
	cout<<"Enter how many spaces to shift \n";
	cin>>spaces;

	if(spaces>0)
	{
		for(int i=0; i<spaces; i++)
		{
			shiftpos(Ar,size);
		}
		for(int i=0;i<size;i++)
		{
			cout<<Ar[i];
			cout<<endl;
		}
		
	}
	else if (spaces<0)
	{
		spaces=spaces*-1;
		for(int i=0; i<spaces; i++)
		{
			shiftneg(Ar,size);
		}
		for(int i=0;i<size;i++)
		{
			cout<<Ar[i];
			cout<<endl;
		}

	}
		
	
	return 0;
}