#include<iostream>
#include<vector>

using namespace std;

void swap(int &x, int &y)
{
	int temp=x;
	x=y;
	y=temp;
}

void sort(vector<int> &v)
{
	for(int i=0; i<v.size();i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(v[j]>v[j+1])
			{
				swap(v[j],v[j+1]);
			}
		}
	}
}


int main()
{

	int maxsize=0, store=1, count=0;
 	vector<int> v;
 	cout<<"How many integers will you input? \n";
 	cin>>maxsize;
 	cout<<"Enter integers \n";
 	while(count<maxsize)
 	{
 		cin>>store;
 		v.push_back(store);
 		count++;
 	}

 	sort(v);
 	for(int i=0;i<v.size();i++)
 	{
 		cout<<v[i]<<endl;
 	}

	return 0;
}