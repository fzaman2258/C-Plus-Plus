#include <iostream>
#include <string>
#include <stack>
using namespace std;

void printvert(int x)
{
	if(x<10)
	{
		cout<<x<<endl;
		return;
	}
	printvert(x/10);
	cout<<x%10<<endl;
}

bool prime(int x, int factor)
{
	if(factor==x)
		return true;
	if(x%factor==0)
		return false;

	prime(x,factor+1);
}

bool palindrome(string str,int start,int end)
{
	
	if(str[start]!=str[end])
	{
		return false;
	}
	if(start>=str.size()/2)
	{
		return true;
	}
	 return palindrome(str,++start,--end);
}

bool balancedpar(string str)
{
	stack<char> input;

	for(int i=0; i<str.length(); i++)
	{
		if(input.empty()==true && str[i]==')')
		{
			return false;
		}

		if(str[i]=='(')
		{
			input.push(str[i]);
		}
		else if(str[i]==')')
		{
			input.pop();
		}

	}
	if(input.empty()==true)
	{
		return true;
	}

}

int main()
{
	//int x;
	//cout<<"Enter input \n";
	//cin>>x;
	//bool temp=prime(x,2);
	//cout<<"this number is prime ? ans="<<temp<<endl;

	//string str;
	//cout<<"enter palindrome check \n";
	//cin>>str;
	//bool temp2=palindrome(str,0,str.length()-1);
	//cout<<"this string is palindrome ? ans="<<temp2<<endl;
	string str;
	cout<<"enter a string to see if balanced paranthesis \n";
	cin>>str;
	bool temp=balancedpar(str);
	cout<<"was this balanced? ans= "<<temp<<endl;

	return 0;
}