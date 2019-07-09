#include<iostream>
using namespace std;

int* unionk(int ar1[], int n1, int ar2[], int n2)
{
	int* combine=new int[n1+n2];
	for(int i=0;i<n1;i++)
	{
		combine[i]=ar1[i];
	}
	for(int i=0; i<n2;i++)
	{
		combine[n1+i]=ar2[i];
	}
	return combine;
}


int main()
{
	int MaxSize=50, n1=0, n2=0, temp,temp2;
	int ar1[MaxSize], ar2[MaxSize];
	
	cout<<"Enter numbers for the 1st array and 10 to stop \n";

	do{
		cin>>temp;
		ar1[n1]=temp;
		n1++;

	}while(temp!=10);
	n1=n1-1;

	cout<<"Enter numbers for the 2nd array and 10 to stop \n";

	do{
		cin>>temp2;
		ar2[n2]=temp2;
		n2++;

	}while(temp2!=10);
	n2=n2-1;

	unionk(ar1,n1,ar2,n2,combine);

	for (int i=0; i<n1+n2; i++)
	{
		cout<< combine[i]<<endl;
	}



	return 0;
}
