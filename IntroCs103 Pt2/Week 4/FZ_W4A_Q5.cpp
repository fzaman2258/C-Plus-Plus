#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	int temp=x;
	x=y;
	y=temp;

}

void sort(int Ar[], int size)
{
	for (int i=1; i<size; i++)
	{
		for(int j=i-1; j>=0;j--)
		{
			if(Ar[j]>Ar[j+1])
			{
				swap(Ar[j],Ar[j+1]);
			}
		}
	}	

}


int main()
{
	int MaxSize=50, size=0, temp;
	int Ar[MaxSize];
	cout<<"Enter integers into the array, and 111 to stop \n";
	do{
		cin>>temp;
		Ar[size]=temp;
		size++;
	}while(temp!=111);

	sort(Ar,size);

	for(int i=0; i<size; i++)
	{
		cout<<Ar[i]<<endl;
	}

	return 0;
}