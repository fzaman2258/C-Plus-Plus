#include <iostream>
#include <vector>
#include<string>
using namespace std;


struct info
{

	string firstName ;
	char lastNameInitial;
	bool alive;
	int age ;
	int zipcode;
	double bodyTemp;
};


void getinfostuff(int people, vector<info> &v)
{
	info stuff;
	for(int i=0; i<people; i++)
	{
		
		cout <<"What is your first name? \n";
   		cin >>stuff.firstName;

   		cout <<"What is your last name initial? \n";
    	cin >>stuff.lastNameInitial;
    	
   		cout <<"What is your age? \n";
    	cin >>stuff.age;
    	
    	cout <<"What is your  body temperature? \n";
    	cin >>stuff.bodyTemp;
    	
  	 	cout <<"Enter 0 for dead or 1 for alive \n";
    	cin >>stuff.alive;
    	
   		cout << "What is your zipcode? \n";
  		cin >>stuff.zipcode;

  		v.push_back(stuff);
  	}
}

void printinfo(vector<info> &v, int people)
{
	info stuff;
	for(int i=0; i<people;i++)
	{
		cout<<"First name: "<< v[i].firstName<<endl;
		cout<<"Last name initial: "<<v[i].lastNameInitial<<endl;
		cout<<"Age: "<< v[i].age<<endl;
		cout<<"Body temperature: "<< v[i].bodyTemp<<endl;
		cout<<"Alive: "<< v[i].alive<<endl;
		cout<<"Zipcode: "<<v[i].zipcode<<endl;
	}
}

int main()
{
	
	vector<info> v;
	int people;
	
	cout<<"How many people's informaiton do you want to store? \n";
	cin>>people;

	getinfostuff(people,v);
	printinfo(v,people);

	

	return 0;
}