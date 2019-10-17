#ifndef __GAME_CPP__
#define __GAME_CPP__
#include "game.h"
#include <cmath>


Game::Game()
{
	map;
	numMines=0;
	mine;
	wins=0;
	hp=100;
}
Game::Game(Map map1, Mines* mine1,int numMines1)
{
	numMines=numMines1;
	map=map1;
	mine=mine1;
	wins=0;
	hp=100;
}
Game:: ~Game()
{

}
void Game::newGame()
{
	hp=100;
	map.genEnterMap();
	map.genCurrMap();
	map.genSolMap();
	genMines();
	char** tempmap=map.getSolMap();

	for(int i=0;i<numMines;i++)
	{


		Mines temp=mine[i];					//take out each individual mine from array
		Point temp2=temp.getPoint();		//get the point out
		char tempx;		
		char tempy;
		tempx=temp2.GetX();					//extract the char
		tempy=temp2.GetY();
		int temp4=map.convert(tempx);		// convert to int
		int temp5=map.convert(tempy);
		tempmap[temp4][temp5]='M';			//place onto tempmap

	}
	map.setSolMap(tempmap);					//solmap=tempmap
	map.calSol(mine, numMines);				//calculate
		
	map.printCurrMap();
	
	map.printSolMap();
	

}
void Game::resetGame()
{
	hp=100;
	map.genCurrMap();
	map.genEnterMap();
	
	map.printCurrMap();
	map.printSolMap();
	
}
void Game::genMines()
{
	
	for(int i=0;i<numMines;i++)
	{
		Point mx;	
		int temp2=rand()%map.getLength()+1;	
		char temp= reverseConvert(temp2);
		int temp4=rand()%map.getWidth()+1;
		char temp1= reverseConvert(temp4);
		mx.SetX(temp);
		mx.SetY(temp1);
		Mines x(mx, rand()%10+1);
		mine[i]=x;
	}
	

}
bool Game::winOrLose()
{
	if(hp<=0)
	{
		return false;	
	}
	else
	{
		return true;
	}
}

char Game::reverseConvert(int input)
{
	string label="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	return label[input];

}

int Game::getNumMines()
{
	return numMines;
}



#endif
