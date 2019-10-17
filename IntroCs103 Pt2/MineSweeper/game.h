#ifndef __GAME_H__
#define __GAME_H__
#include "map.h"

class Game
{

private:

	Map map;
	Mines* mine;
	int wins;
	int hp;
	int numMines;

public:


	Game();
	Game(Map map1, Mines* mine1,int numMines1);
	~Game();
	void newGame();
	void resetGame();
	void genMines();
	bool winOrLose();
	char reverseConvert(int input);
	int getNumMines();
};


#endif
