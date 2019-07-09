#include "Zaman_Farhan_HW2.h"
#include <iostream>
using namespace std;

int main()
{

/*
	char Ar[50];
	int size=0;
	enterarray(Ar,size);
	size-=1;
	for(int i=0; i<size; i++)
	{
		cout<<Ar[i]<<endl;
	}

	if(size==0)
	{
		cout<<"the array is empty \n";
	}
	else
	{
		char highestoccurences=occurences(Ar,size);
		cout<<"this is the most frquent letter= "<<highestoccurences<<endl;
	}

	shift(Ar,size);

	
	for(int i=0; i<size; i++)
	{
		cout<<Ar[i]<<endl;
	}

	char Ar2[50];
	int size2=0;
	enterarray(Ar2,size2);
	size2-=1;
	char * combined=combine(Ar,size,Ar2,size2);


	for(int i=0; i<size+size2; i++)
	{
		cout<<combined[i]<<endl;
	}

*/
	char** Ard=new char*[50];
	for(int i=0; i<50; i++)
	{
		Ard[i]= new char [50];
	}

	int m=0, n=0;

	entermatrix(Ard,m,n);

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<Ard[i][j];
		}
		cout<<endl;
	}
	/*
	rotate90(Ard,m,n);
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<Ard[i][j];
		}
		cout<<endl;
	}
	
	*/
	enlarge(Ard,m,n);


	
	return 0;
}