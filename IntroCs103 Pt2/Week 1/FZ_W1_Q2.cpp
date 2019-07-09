#include <iostream>
using namespace std;
int main()
{
	string firstName ;
	char lastNameInitial;
	bool alive;
	int age, zipcode;
	double bodyTemp;

    cout <<"What is your first name? \n";
    cin >>firstName;
    cout <<"What is your last name initial? \n";
    cin >>lastNameInitial;
    cout <<"What is your age? \n";
    cin >>age;
    cout <<"What is your  body temperature? \n";
    cin >>bodyTemp;
    cout <<"Enter 0 for dead or 1 for alive \n";
    cin >> alive;
    cout << "What is your zipcode? \n";
    cin >> zipcode;








	cout<<"First name: "<< firstName <<endl;
	cout<<"Last name initial: "<< lastNameInitial <<endl;
	cout<<"Age: "<< age <<endl;
	cout<<"Body temperature: "<< bodyTemp <<endl;
	cout<<"Alive: "<< alive <<endl;
	cout<<"Zipcode: "<< zipcode <<endl;

return 0;

}