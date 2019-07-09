#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int A[7];
    int i;
    for (i=0; i<7 ; i++)
    {
        A[i]=i*i;
    }
    cout << A[i-1] << endl;
    cout << *A << endl;
    int* p = &A[5];
    cout << *p << endl;
    p = p-1 ;
    cout << *p << endl;
    *p = 99 ;
    cout << *(++p) << endl;
    *p = 99 ;
    for(i=0; i<7; i++)
    {
        cout<< "A[" << i << "] =" << A[i] << endl;
    }

    return 0;








}