#ifndef __MAP_H__
#define __MAP_H__
#include "mines.h"


class Map
{
	private:

		int length;
		int width;
		bool** enterMap;
		char** currMap;
		char** solMap;
	  	 
	
	public:
		Map();
		Map(int input1, int input2);
		~Map();
		int getLength();
		int getWidth();
		void genEnterMap();
		void genCurrMap();
		void genSolMap();
		void printEnterMap();
		void printCurrMap();
		void printSolMap();
		bool checkEntries(Point point);
		bool checkEmpMines(Point point);
		void calSol(Mines* mines,int numMines);
		int convert(char input);
		void reveal(int x, int y);	
		void setSolMap(char** tempmap);	
		char** getSolMap();
		

};


#endif
