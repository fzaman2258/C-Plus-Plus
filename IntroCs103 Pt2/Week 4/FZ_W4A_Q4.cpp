#include <iostream>
using namespace std;

int search(int Ar[], int size, int sv)
{
	for(int i=0; i<size; i++)
	{
		if (Ar[i]==sv)
		{
			return i;
		}
	}
	return -1;
}



int main()
{
	int MaxSize=50, size=0, sv, temp;

	int Ar[MaxSize];
	cout<<"Enter integers into this array and 10 to stop \n";
	do{
		cin>>temp;
		Ar[size]=temp;
		size++;

	}while(temp!=10);

	cout<<"What value do you want to search for? \n";
	cin>>sv;
	int truth=search(Ar,size,sv);
	cout<<"The result of the search is "<<truth<<endl;



	return 0;
}