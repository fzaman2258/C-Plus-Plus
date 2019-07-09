#include "FZ_W5_Q1.h"
#include "FZ_W5_Q2.h"
#include <iostream>



int main()
{
	cout << "===== pt1" << endl;
	Point pt1;
	pt1.Print();

	cout << "===== pt2" << endl;
	Point pt2(5,10);
	pt2.Print();

	cout << "===== pt1" << endl;
	pt1.SetX(3);
	pt1.SetY(5);
	cout << "(" << pt1.GetX() << ", " << pt1.GetY() << ")" << endl;

	cout << "===== pt2" << endl;
	cout << pt2.Quadrant() << endl;
	
	cout << "===== pt3" << endl;
	Point pt3;
	pt3 = pt1 + pt2;
	pt3.Print();

	cout << "===== pt3" << endl;
	pt3 = pt1 - pt2;
	pt3.Print();

	cout << "===== pt4" << endl;
	Point pt4;
	cout << "Enter X and Y" << endl;
	cin >> pt4;
	cout << pt4;

	cout << endl << endl << "LINE" << endl;

	cout << "===== ln1" << endl;
	Line ln1;
	ln1.print();

	cout << "===== ln2" << endl;
	Line ln2(pt1, pt2);
	ln2.print();

	cout << "ln1 || ln2: " << ln1.parallel(ln2) << endl;

	cout << "===== ln1" << endl;
	ln1.Setp1(pt3);
	ln1.print();

	cout << "ln1 || ln2: " << ln1.parallel(ln2) << endl;

	cout << "===== ln1" << endl;
	ln1.Setp2(pt4);
	ln1.print();

	cout << "ln1 || ln2: " << ln1.parallel(ln2) << endl;

	cout << "ln1 < ln2: " << (ln1 < ln2) << endl;
	cout << "ln1 > ln2: " << (ln1 > ln2) << endl;



	return 0;
}