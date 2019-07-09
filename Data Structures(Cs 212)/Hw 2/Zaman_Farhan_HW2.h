#ifndef __ZAMAN_FARHAN_HW2_H__
#define __ZAMAN_FARHAN_HW2_H__

#include <iostream>
#include <cctype>
#include <cassert>
using namespace std;


void enterarray(char Ar[],int &size);
char occurences(char Ar[],int size);
void swap(char x, char y);
void shift(char Ar[], int size);
char* combine(char Ar1[],int sizen1, char Ar2[],int sizen2);
void entermatrix(char** Ar, int &m, int &n);
void rotate90(char** Ar,int m, int n);
void enlarge(char** Ar,int m, int n);

#endif