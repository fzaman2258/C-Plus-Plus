#include<iostream>
using namespace std;

int endindex( char Ar[],int size)
{
	//size=size-1;
	char temp=Ar[0];
	int maxcount=0, count=1,eindex=0;
	for(int i=1; i<size; i++)
	{
		if(temp==Ar[i])
		{
			count++;
		}
		else
		{
			temp=Ar[i];
			if(count>maxcount)
			{
				
				maxcount=count;
				eindex=i-1;

			}
			count=1;
		}
	}
	return eindex;
}
/*
int startindex(char Ar[],int size)
{
	char temp=Ar[0];
	int maxcount=0, count=1;
	for(int i=1; i<size; i++)
	{
		if(temp==Ar[i])
		{
			count++;
		}
		else
		{
			temp=Ar[i];
			if(count>maxcount)
			{
				
				maxcount=count;
			}
			count=1;
		}
	}
}
*/

int length(char Ar[], int size)
{
	char temp=Ar[0];
	int maxcount=0, count=1;
	for(int i=1; i<size; i++)
	{
		if(temp==Ar[i])
		{
			count++;
		}
		else
		{
			temp=Ar[i];
			if(count>maxcount)
			{
				
				maxcount=count;
			}
			count=1;
		}
	}
	return maxcount;
}




int main()
{
	int MaxSize=50, size=0;
	char Ar[MaxSize];
	
	char temp;
	cout<<"Enter letters, entering # stops it \n";

	do{
		cin>>temp;
		Ar[size]=temp;
		size++;

	}while(temp!='#');
	int length1=length(Ar,size);
	cout<<"The max run is "<<length1<<endl;
	int end=endindex(Ar,size);
	cout<<"The start index of max run is "<<end-length1+1<<endl;
	cout<<"The end index of max run is "<<end<<endl;

	



	return 0;
}