#include <iostream>

using namespace std;

int main() {
	int b;
	int& a = b;
	a = 10;
	cout << "a=" << a << " b=" << b << endl;

	b = 100;
	cout << "a=" << a << " b=" << b << endl;
	cout << "&a=" << &a << " &b=" << &b << endl;


	int d;
	int *c = &d;
	*c = 15;
	cout << "c=" << c << " d=" << d << endl;
	cout << "*c=" << *c << " d=" << d << endl;


	d = 100;
	cout << "c=" << c << " d=" << d << endl;
	cout << "*c=" << *c << " d=" << d << endl;
	cout << "&c=" << &c << " &d=" << &d << endl;
	

	return 0;
}