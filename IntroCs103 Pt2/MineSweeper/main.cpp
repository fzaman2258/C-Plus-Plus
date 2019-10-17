#include  "game.h"

int main()
{
	
	cout<<"1. Start a New Game"<<endl;
	cout<<"2. Load an Existing Game"<<endl;
	cout<<"3. Help"<<endl;
	cout<<"4. Quit"<<endl;
	
	int input;
	cin>>input;	

	if(input==1)
	{
		cout<<"What do you want to be the size of the map? 1 for Small, 2 for medium,3 for expert or 4 custom? \n";
		int size;
		cin>>size;
		if(size==1)
		{
			Map play(8,8);
			Mines *m;
			Game newgame(play, m,10);
			
		}
		else if(size==2)
		{
			Map play(16,16);
			Mines *m;
			Game newgame(play, m,40);
		
		}
		else if(size==3)
		{
			Map play(30,16);
			Mines *m;
			Game newgame(play, m,99);
		
		}
		else if (size==4)
		{
			cout<<"What is the length and width of the map? \n";
			int x,y;
			cin>>x>>y;
			if(x>36 || y>36)
			{
				cout<<"Please enter lengths and widths less than 36!  \n";
			}
				cin>>x>>y;
				Map play(x,y);
				Mines *m;
				cout<<"How many mines do you want? \n";
				int z;
				cin>>z;
				Game newgame(play, m,z);
		}
	}
	else if(input==2)
	{
		if (true)
		{
		
		}
		else 
		{
			cout<<"No saved game"<<endl;
		}
	}
	else if(input==3)
	{
		cout<<"To play mine sweeper, first select a size. You can choose small (8x8), medium (16x16), large (30x16) or a custom size. The goal of the game is to try to uncover all squares except the ones that are mines without losing your all of your health points. You have one hundred health points to begin with. Each time you click on a mine, you will lose some health points. If your hp goes to zero or below zero, you lose the game. However, if you uncover all the none mine squares with hp remaining, you win the game. \n";
	}
	else if(input==4)
	{
		return 0;
	}





		cout<<"1. Play"<<endl;
		cout<<"2. Print {map || score}"<<endl;
		cout<<"3. Save"<<endl;
		cout<<"4. Start Over"<<endl;
		cout<<"5. Start a New Game"<<endl;
		cout<<"6. Help"<<endl;
		cout<<"7. Quit"<<endl;
	
		int input2;
		cin>>input2;

		
		



		if(input2==1)
		{

			cout<<"Enter a position \n";
			char a ,b;
			cin>>a>>b;
			Point p(a,b);
			cout<<"Enter r to reveal or m to mark as a mine! \n";
			char move;
			cin>>move;
			if(move=='r' || move=='R')
			{
				int pos1=play.convert(a);
				int pos2=play.convert(b);
				play.reveal(pos1,pos2);
				play.checkEntries(p)=true;

			}
			else if(move=='m' || move=='M')
			{
				int pos1=play.convert(a);
				int pos2=play.convert(b);
				play.currMap[pos1][pos2]='m';
			}
			else
			{
				cout<<"Enter again! \n";
			}

		}
		else if(input2==2)
		{
			play.printCurrMap();
		}
		else if(input2==3)
		{
			cout<<"Your game has been saved! \n";
		}
		else if(input2==4)
		{
			newgame.resetGame();
		}
		else if(input2==5)
		{
			newgame.newGame();
		}
		else if(input2==6)
		{
			cout<<"To play mine sweeper, first select a size. You can choose small (8x8), medium (16x16), large (30x16) or a custom size. The goal of the game is to try to uncover all squares except the ones that are mines without losing your all of your health points. You have one hundred health points to begin with. Each time you click on a mine, you will lose some health points. If your hp goes to zero or below zero, you lose the game. However, if you uncover all the none mine squares with hp remaining, you win the game. \n";
		}
		else if(input2==7)
		{
			return 0;
		}
	







/*
	//check point.h/cpp
	Point pt1,pt2;
	cout<<"enter point \n";
	cin>>pt1;
	cout<<"enter 2nd ppint \n";
	cin>>pt2;
	if(pt1==pt2)						
	{
		cout<<"very good \n";
	}
	else cout<<"very bad \n";

	//check mines.h/cpp
	Mines m1;
	Point pt3;
	double intense;
	cout<<"Enter point for m1 which goes into array later and intensity \n";
	cin>>pt3;
	cin>>intense;
	m1.setPoint(pt3);
	m1.setStrength(intense);
	m1.print();

	Point pt7;
	cout<<"enter 2nd point for m2 which array \n";
	cin>>pt7;

	Mines m2(pt7,intense);
	cout<<m2.getPoint();
	double s;
	s=m2.getStrength();
	cout<<s<<endl;

	//check map.h/cpp
	Map newMap(36,36);
	newMap.genSolMap();
	newMap.printSolMap();
	newMap.genEnterMap();
	newMap.printEnterMap();
	newMap.genCurrMap();
	newMap.printCurrMap();
	cout<<newMap.getLength()<<endl;
	cout<<newMap.getWidth()<<endl;


	
	Point pt5;
	cout<<"enter point \n";
	cin>>pt5;
	cout<<"check if entered before ="<<newMap.checkEntries(pt5)<<endl;
	cout<<"is there a mine? "<<newMap.checkEmpMines(pt5)<<endl;
	
	cout<<"enter character \n";
	char z;
	cin>>z;

	cout<<newMap.convert(z)<<endl;
	cout<<"enter x  \n";

	int x;
	cin>>x;

	//newMap.reveal(x,y);
	Mines* m3=new Mines [x];
	m3[0]=m1;
	m3[1]=m2;

	//newMap.calSol(m3,2);
	//newMap.printSolMap(); 



	cout<<"here is new game \n";
	Game all(newMap, m3, 4);
	all.newGame();
	cout<<"win or lose = "<<all.winOrLose()<<endl;
	all.resetGame();
	cout<<"win or lose 2= "<<all.winOrLose()<<endl;
	cout<<"num mines "<<all.getNumMines();



*/






	return 0;
}
