#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{
	for (int i=0; i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	for(int j=v.size()-1; j>=0; j--)
	{
		cout<<v[j]<<endl;
	}
}

int sum(vector<int> v)
{
	int total=0;
	for(int i=0; i<v.size(); i++)
	{
		total+=v[i];
	}
	cout<<"The sum of the integers is "<<total<<endl;
}

int mean(vector<int>v)
{
	double total=0;
	for(int i=0; i<v.size(); i++)
	{
		total+=v[i];
	}
	double average=(total/v.size());
	cout<<"The average of the integers is "<<average<<endl;
}

void max(vector<int> v)
{
	int max=v[0];
	int min=v[0];
	for(int i=1; i<v.size();i++)
	{
		if(max<v[i])
		{
			max=v[i];
		}
		if(min>v[i])
		{
			min=v[i];
		}
	}
	cout<<"The max of the numbers is "<<max<<endl<<"The min of the numbers is "<<min<<endl;
}






 int main ()
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
 	print(v);
 	sum(v);
 	mean(v);
 	max(v);



 	return 0;
 }