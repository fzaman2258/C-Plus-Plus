#include <iostream>
#include <string>
using namespace std;

bool palindrome(string str, int start, int end)
{
	if (start>=end)
	{
		return true;
	}
	if(str[start]!=str[end])
	{
		return false;
	}

	return palindrome(str,++start,--end);

}


int main()
{
	string str;
	cout<<"Enter a word to determine if it is a palindrome \n";
	cin>>str;
	int end=str.size()-1;
	bool answer=palindrome(str,0,end);
	if(answer)
		cout<<"This is a palindrome! \n";
	else
		cout<<"This is not a palindrome! \n";


	return 0;
}