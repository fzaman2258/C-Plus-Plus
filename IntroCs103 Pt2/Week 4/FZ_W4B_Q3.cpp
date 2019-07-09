#include<iostream>
#include<vector>

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







int main()
{

 	int maxsize=0,size=0, store=1, count=0, count2=0;
 	vector<int> v1, v2;
 	cout<<"How many integers will you input for vector1? \n";
 	cin>>maxsize;
 	cout<<"Enter integers \n";
 	while(count<maxsize)
 	{
 		cin>>store;
 		v1.push_back(store);
 		count++;
 	}

	cout<<"How many integers will you input for vector2? \n";
 	cin>>size;
 	cout<<"Enter integers \n";
 	while(count2<size)
 	{
 		cin>>store;
 		v2.push_back(store);
 		count2++;
 	}

 	vector<int> sorted=mergesort(v1,v2);

 	for(int i=0;i<sorted.size();i++)
 	{
 		cout<<sorted[i]<<endl;
 	}




	return 0;
}