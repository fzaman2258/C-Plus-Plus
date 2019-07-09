#include <iostream>
using namespace std;

void print(int Ar[], int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<Ar[i]<<endl;
	}
	for(int j=size-1;j>=0;j--)
	{
		cout<<Ar[j]<<endl;
	}
}

int sum(int Ar[], int size)
{
	int sum=0;
	for(int i=0;i<size;i++)
	{
		sum+=Ar[i];
	}
	cout<<sum<<endl;
}

int mean(int Ar[], int size)
{
	double sum=0;
	for(int i=0;i<size;i++)
	{
		sum+=Ar[i];
	}

	double average=(sum/size);
	cout<<average<<endl;
}

void max(int Ar[],int size)
{
	int max=Ar[0];
	int min=Ar[0];
	for(int i=0;i<size;i++)
	{
		
		if (max<Ar[i])
		{
			max=Ar[i];
		}
		if(Ar[i]<min)
		{
			min=Ar[i];
		}
	}
	cout<<max<<endl<<min<<endl;
}





int main()
{
	int MaxSize=50,size=0;
	int Ar[MaxSize];
	int temp;
	cout<<"Enter integers \n";
	do{

		cin>>temp;
		Ar[size]=temp;
		size++;
		

	}while(size<MaxSize && Ar[size-1]!=0);

	size=size-1;


	print(Ar,size);
	
	sum(Ar,size);
	mean(Ar,size);
	max(Ar,size);

		return 0;
}