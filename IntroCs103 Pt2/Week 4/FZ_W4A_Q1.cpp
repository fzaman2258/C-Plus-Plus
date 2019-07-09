#include <iostream>
using namespace std;
char vowel(char Ar[], int size)
{
	int count[5]={0,0,0,0,0};
	for(int i=0; i<size; i++)
	{
		if (Ar[i]=='a')
		{
			count[0]++;
		}
		if (Ar[i]=='e')
		{
			count[1]++;
		}
		if (Ar[i]=='i')
		{
			count[2]++;
		}
		if(Ar[i]=='o')
		{
			count[3]++;
		}
		if(Ar[i]=='u')
		{
			count[4]++;
		}
	}

	int maxcount=count[0];
	int maxindex=0;
	for(int i=1;i<5;i++)
	{
		if(maxcount<count[i])
		{
			maxcount=count[i];
			maxindex=i;
		}
	}

	if(maxindex==0)
	{
		return 'a';
	}
	if(maxindex==1)
	{
		return 'e';
	}
	if(maxindex==2)
	{
		return 'i';
	}
	if(maxindex==3)
	{
		return 'o';
	}
	if(maxindex==4)
	{
		return 'u';
	}
}



int main()
{
	int MaxSize=50, size=0;
	char temp;
	char Ar[MaxSize];
	cout<<"Enter vowels and type 1 to stop \n";
	do{
		cin>>temp;
		Ar[size]=temp;
		size++;

	}while(temp!='1');
	char answer=vowel(Ar,size);
	cout<<"The most reoccuring vowel is "<<answer<<endl;



	return 0;
}