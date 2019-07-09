#ifndef __ZAMAN_FARHAN_HW2_CPP__
#define __ZAMAN_FARHAN_HW2_CPP__
#include "Zaman_Farhan_HW2.h"

int Maxsize=50;
string str="abcdefghijklmnopqrstuvwxyz";

void enterarray(char Ar[], int &size)
{
	char input;
	cout<<" Enter lowercase letters up to 50 and to stop type a number \n";
	do{
		cin>>input;
		Ar[size]=input;
		size++;

	}while(isalpha(input)!=0 && size<=Maxsize);		
}



char occurences(char Ar[],int size)
{
	int count[26];
	for(int i=0; i<26; i++)
	{
		count[i]=0;
	}
	
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<26; j++)
		{
			if(Ar[i]==str[j])
			{
				count[j]++;

			}
			else
			{
				continue;
			}
		}
	}

	int max=count[0];
	int maxindex=0;
	for(int i=1; i<26; i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			maxindex=i;
		}
	}
	
	return str[maxindex];

}

void swap(char x, char y)
{
	char temp;
	temp=x;
	x=y;
	y=temp;
}

void shift(char Ar[], int size)
{
	cout<<"How many shifts do you want, pos for shifting right, negative for shifting left \n";
	int rotate;
	cin>>rotate;
	if(rotate>0)
	{	
		for(int j=0; j<rotate; j++)
		{
			char temp=Ar[size-1];
			for(int i=size-1; i>0; i--)
			{
				Ar[i]=Ar[i-1];
			}
				Ar[0]=temp;
		}
	}

	if(rotate<0)
	{
		rotate*=-1;
		for(int j=0; j<rotate; j++)
		{
			char temp=Ar[0];
			for(int i=0; i<size-1; i++)
			{
				Ar[i]=Ar[i+1];
			}
				Ar[size-1]=temp;
		}
	}

	
}

char* combine(char Ar1[],int sizen1, char Ar2[],int sizen2)
{
	char *combine= new char[sizen1+sizen2];
	int i=0, j=0, z=0;
	while(i<sizen1 && j<sizen2)
	{
		if(Ar1[i]<Ar2[j])
		{
			combine[z]=Ar1[i];
			i++;
			z++;
		}
		else
		{
			combine[z]=Ar2[j];
			j++;
			z++;
		}
	}

	while(j<sizen2)
		{
			combine[z]=Ar2[j];
			j++;
			z++;
		
		}
	
	while(i<sizen1)
		{
			combine[z]=Ar1[i];
			i++;
			z++;
		}
	

	return combine;
}

void entermatrix(char** Ar, int &m, int &n)
{
	cout<<"what do you want the mxn dimensions of the array to be? \n";
	int length,width;
	cin>>length>>width;
	m=length;
	n=width;
	char input;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<"enter the input for positon "<<i<<","<<j<<":";
			cin>>input;
			Ar[i][j]=input;
			cout<<endl;
		}
	}
}
	
void rotate90(char** Ar,int m, int n)
{
	assert(m==n);		//make sure square matrix
	cout<<"Enter number of rotations, pos for counter clockwise, neg for clockwise \n";
	int rotate;
	cin>>rotate;
	int store=m;
	int store2=m;
	int x=0, y=1;
	if (rotate>0)
	{
		for(int z=0; z<store/2; z++)		//for the rotations of inner and outter borders
		{
			for(int count=0; count<rotate; count++)		//number of rotations they want corner to corner
			{
				for(int count2=0; count2<store2-1; count2++)	//rotate to the corner for 1 90degree one
				{
					char temp=Ar[x][y-1];		//store one corner as we rotate everything else
					for(int i=x; i<m; i++)
					{
						Ar[x][i]=Ar[x][i+1];    //shift top row by one to the left
					}
					
					for(int i=x; i<m; i++)     //right most column shifted upwads
					{
						Ar[i][m-1]=Ar[i+1][m-1];
					}
					
					for(int i=m-1; i>x; i--)  //shift bottom row to the right
					{
						Ar[m-1][i]=Ar[m-1][i-1];
					}
					
					for(int i=m-1; i>=y; i--) // right most column shifted downards
					{
						Ar[i][x]=Ar[i-1][x];
					}
					Ar[y][x]=temp;  //shift the corner we stored before down
				}
			}
			x++;
			y++;
			m--;
			store2=store2-2;
		}	
	}
	else if(rotate<0)
	{
		rotate=rotate*-1;
		for(int z=0; z<store/2; z++)
		{
			for(int count=0; count<rotate; count++)
			{
				for(int count2=0; count2<store2-1; count2++)
				{
					char temp=Ar[x][y-1];
					for(int i=x; i<m; i++)
					{
						Ar[i][x]=Ar[i+1][x];
					}

					for(int i=x; i<m; i++)
					{
						Ar[m-1][i]=Ar[m-1][i+1];
					}

					for(int i=m-1; i>x; i--)
					{
						Ar[i][m-1]=Ar[i-1][m-1];
					}

					for(int i=m-1; i>=y; i--)
					{
						Ar[x][i]=Ar[x][i-1];
					}
					Ar[x][y]=temp;
				}
			}
		}
		x++;
		y++;
		m--;
		store2=store2-2;
	}
}

void enlarge(char** Ar,int m, int n)
{
	int size;
	cout<<"What factor do you want to enlarge the matrix \n";
	cin>>size;
	//assert(size>1);
	int bign=n*size;
	int bigm=m*size;
	char** big=new char*[bigm];
	for(int i=0; i<bigm; i++)
	{
		big[i]= new char [bign];
	}
	int bigc=0,bigr=0;

	for(int smallr=0; smallr<m; smallr++)
	{
		bigc=0;
		for(int smallc=0; smallc<n; smallc++)
	 	{
	 		for(int countofsmallsize=0; countofsmallsize<size; countofsmallsize++)
	 		{
	 			for(int countofbigsize=0; countofbigsize<size; countofbigsize++)
	 			{
	 				big[bigr][bigc]=Ar[smallr][smallc];
	 				bigc++;
	 			}
 			bigc-=size;
 			bigr++;
 			}
 		bigr-=size;
 		bigc+=size;
 		}
	bigr+=size;
	}

	for(int a=0; a<bigm; a++)
	{
		for(int b=0; b<bign; b++)
		{
			cout<<big[a][b];
		}
	cout<<endl;
	}	
}
	

#endif

