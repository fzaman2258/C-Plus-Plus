#ifndef __MAP_CPP__
#define __MAP_CPP__
#include <string>
#include "map.h"

Map::Map()							// we wont ever use
{
	length=0;
	width=0;
	enterMap;
	currMap;
	solMap;
}

Map::Map(int input1, int input2)
{
	length=input1+2;						//make it bigger for neightborcount later
	width=input2+2;
	enterMap=new bool* [length];
	for (int i=0; i<length; i++)			// generate the dynamic 2d arrays
	{
		enterMap[i]=new bool[width];
	}
	

	currMap=new char* [length];
	for (int i=0; i<length; i++)
	{
		currMap[i]=new char[width];
	}

	solMap=new char* [length];
	for (int i=0; i<length; i++)
	{
		solMap[i]=new char[width];
	}
	genSolMap();
	
}

Map::~Map()
{

}

int Map::getLength()
{
	return length;
}
int Map::getWidth()
{
	return width;
}
void Map:: genEnterMap()			//check to see if input was already inputted
{

	for(int i=0; i<length; i++)	
	{
		for(int j=0; j<width; j++)		
		{
			enterMap[i][j]=false;	//nothing has been inputted yet so start off false
		}
	}

}

void Map::genCurrMap()
{
	string label="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";	//label our grid

	for(int i=0; i<length; i++)
	{
		for(int j=0; j<width; j++)
		{
			currMap[i][j]=' ';					//nothing is revealed yet
		}
	}

	for(int i=1; i<length-1; i++)
	{
		currMap[i][0]=label[i-1];		//for our rows 
	}
	for(int j=1; j<width-1; j++)
	{
		currMap[0][j]=label[j-1];		//for our columns
	}



}

void Map::genSolMap()
{

	for(int i=0; i<length; i++)
	{
		for(int j=0; j<width; j++)
		{
			solMap[i][j]='0';			//no mines place so start with 0
		}
		
	}
}

void Map::printEnterMap()
{
	cout<<"this is enter map \n";
	for(int i=1; i<length-1; i++)	//print only the valid places to input
	{
		for(int j=1; j<width-1; j++)
		{
			cout<<enterMap[i][j];			
		}
		cout<<endl;
	}


}
void Map::printCurrMap()
{
	cout<<"this is curr map \n";
	for(int i=0; i<length-1; i++)		// print the borders that has labels
	{
		for(int j=0; j<width-1; j++)
		{
			cout<<currMap[i][j];
		}
		cout<<endl;
	}

}
void Map::printSolMap()
{
	cout<<"this is sol map \n";
	for(int i=1; i<length-1; i++)		//print only the playable map
	{
		for(int j=1; j<width-1; j++)
		{
			cout<<solMap[i][j];
		}
		cout<<endl;
	}

}
bool Map::checkEntries(Point point)
{


	int x=convert(point.GetX());		//they inputted characters
	int y=convert(point.GetY());
	
	if (enterMap[x][y]==true)			//was it inputted or not

	{
		return true;
	}
	else
	{
		return false;
	}	
	


}
bool Map::checkEmpMines(Point point)
{
	int x=convert(point.GetX());			// point is in char make it int
	int y=convert(point.GetY());

	if (solMap[x][y]=='M')					// is it a mine
	{
		return true;
	}
	else 									// is it empty
	{
		return false;
	}	

}
	
void Map::calSol(Mines* mines,int numMines)
{
	for(int i=0; i<numMines; i++)				//this places mines
	{
	Point temp=mines[i].getPoint();
	int x=convert(temp.GetX());
	int y=convert(temp.GetY());
	solMap[x+1][y+1]='M';
	}



	for(int i=1; i<length-1; i++)			//these 2 for loops check the playable grid
	{
		for(int j=1; j<width-1; j++)		//and makes sure it isnt a mine
		{
			if(solMap[i][j]!='M')
			{
				for(int a=i-1; a<=i+1; a++)	// this checks the 8 around the grid and counts
				{
					for(int b=j-1; b<=j+1; b++)
					{
						if(solMap[a][b]=='M')
						{
							solMap[i][j]++;
						}
					}
				}
			}
		}
	}

}

int Map::convert(char input)
{

	string label="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


	for(int i=0; i<36; i++)			//only 36 labels
	{
		if(label[i]==input)			
		{
			return i;				//return index for compiler to know what they meant
		}
	}

}

void Map::reveal(int x, int y)
	{
	if(x<1||x>=length||y<1||y>=width)		// is the input a legal move
	{
		
		return;

	}

	if(solMap[x][y]!='0')				//if its a 0 in sol map,reveal the 0 in curr map
	{
		currMap[x][y]=solMap[x][y];
		enterMap[x][y]=true;
		return;

		
	}


		reveal(x-1,y-1);				// recursively show all the 0's that may by touching
		reveal(x-1,y);
		reveal(x-1,y+1);
		reveal(x,y-1);
		reveal(x,y+1);
		reveal(x+1,y-1);
		reveal(x+1,y);
		reveal(x+1,y+1);
}

void Map::setSolMap(char** tempmap)
	{
	solMap=tempmap;
	}

char** Map::getSolMap()
	{
	return solMap;
	}

		
	
#endif
