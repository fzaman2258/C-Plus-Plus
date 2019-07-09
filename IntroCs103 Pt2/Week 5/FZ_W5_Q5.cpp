#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


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

vector<int> mergesort(vector<int> v1, vector<int> v2)
{
	vector<int> v3;
	sort(v1);
	sort(v2);
	int i=0, j=0;

	while(i<v1.size()&& j<v2.size())
	{
		if(v1[i]>v2[j])
		{
			v3.push_back(v2[j]);
			j++;
		}
		else
		{
			v3.push_back(v1[i]);
			i++;
		}
	}
	while(i<v1.size())
	{
		v3.push_back(v1[i]);
		i++;
	}
	while(j<v2.size())
	{
		v3.push_back(v2[j]);
		j++;
	}


	return v3;
}

vector<int> divide(vector<int> v)
{
	vector<int> result;
	if(v.size()<=1)
	{
		return v;
	}
	int mid=floor(v.size()/2);
	vector<int> v1, v2;
	for(int i=0; i<mid;i++)
	{
		v1.push_back(v[i]);
		v2.push_back(v[mid+i]);
	}
	v1=divide(v1);
	v2=divide(v2);
	result= mergesort(v1,v2);
	return result;
}

int main()
{
	vector<int> v;
	int store;
	cout<<"Enter a power of 2 number of integers into vector and 100 to stop \n";
	while(store!=100)
	{
		cin>>store;
		v.push_back(store);
	}
	
	v.pop_back();
	vector<int> v4;
	v4=divide(v);
	for(int i=0; i<v4.size();i++)
	{
		cout<<v4[i]<<endl;
	}
	return 0;
}