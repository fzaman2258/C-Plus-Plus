

/*

 * CSc103 Project 3: Game of Life
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:

 * #hours: 50ish
 */

#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using namespace std;
static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Text-based version of Conway's game of life.\n\n"
"   --seed,-s     FILE     read start state from FILE.\n"
"   --world,-w    FILE     store current world in FILE.\n"
"   --fast-fw,-f  NUM      evolve system for NUM generations and quit.\n"
"   --help,-h              show this message and exit.\n";

size_t max_gen = 0; /* if > 0, fast forward to this generation. */
string wfilename =  "/tmp/gol-world-current"; /* write state here */
FILE* fworld = 0; /* handle to file wfilename. */
string initfilename = "/tmp/gol-world-current"; /* read initial state from here. */

/* see the hints section of the readme: to get the basics working,
 * uncomment this next line, and you'll have a suitable test vector
 * to which you can apply the rules. */
// #define WARMUP 1

#ifdef WARMUP
vector<vector<bool> > world = {
#include "res/bglider-small"
};
#endif

/* NOTE: you don't have to write these functions -- this is just how
 * I chose to organize my code. */
size_t nbrCount(size_t i, size_t j, const vector<vector<bool> > board)  //application of the rules
{
    size_t nr,pr,nc,pc,lives=0 ;
    nr=i+1;
    nc=j+1;
    pr=i-1;
    pc=j-1;
lives=0;
//for all points on the border
    if (i==0 )
    {
        pr=board.size()-1;
    }
    if(i==board.size()-1)
    {
        nr=0;
    }
    if (j==0)
    {
     pc=board[i].size()-1    ;
    }
    if(j==board[i].size()-1)
    {
        nc=0;
    }


/* for all points on the board, they can be generalized to have 1-2 of these characteristics */
    if(board[i][nc] =='O')
    {
        lives++;
    }
    if(board[i][pc]=='O')
    {
        lives++;
    }
    if(board[nr][j]=='O')
    {
        lives++;
    }
    if(board[pr][j]=='O')
    {
        lives++;
    }
    if(board[nr][nc]=='O')
    {
        lives++;
    }
    if(board[nr][pc]=='O')
    {
        lives++;
    }
    if(board[pr][nc]=='O')
    {
        lives++;
    }
    if(board[pr][pc]=='O')
    {
        lives++;
    }


    return lives;


    }

vector<vector<bool> > update(vector<vector<bool> > board)
{
vector<vector<bool> > grid2;
    grid2=board;
    int life;
 for (int i=0; i<board.size();i++)
    { for(int j=0; j<board[i].size(); j++)
        {
          life=nbrCount(i,j,board);

            if (life<2 || life>3)
            {
                grid2[i][j]=false;
            }
            else if (life==3)
            {
                grid2[i][j]=true;
            }

        }
    }
    return grid2;

}

void mainLoop();

vector<vector<bool> > initFromFile(const string& fname) //initial state
{
    vector<vector<bool> > grid;        //make grid
   FILE* f = stdout;  // read file
    grid.push_back(vector<bool>());
    size_t rows = 0;
    char c;
    while (fread(&c,1,1,f))             //character, 1 byte
    {
         if (c == '\n')
         {
              rows++;
                grid.push_back(vector<bool>());
         }
         else if (c == '.')
         {
             grid[rows].push_back(false);
         }
         else
         {
             grid[rows].push_back(true);
         }
    }
fclose(f);
    //Print
    /* for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j])
            {
                cout<<"O";
            }
            else
            {
                cout<<".";
            }
        }
        cout<<"\n";

    } */
    return grid;
}



/* read initial state into vectors. */

void dumpState(const string& fname,vector<vector<bool> > &grid)
{


    char dead = '.';
    char alive ='O';
    char newline = '\n';

    FILE* f =stdin;


    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
            if(grid[i][j])
            {
                fwrite(&alive,1,1,f);
            }
            else
            {
                fwrite(&dead,1,1,f);
            }
        }
        fwrite(&newline,1,1,f);

    }


    fclose(f);





}

/* NOTE: you can use a *boolean* as an index into the following array
 * to translate from bool to the right characters: */
char text[3] = ".O";

int main(int argc, char *argv[]) {
    // define long options
    static struct option long_opts[] = {
        {"seed",    required_argument, 0, 's'},
        {"world",   required_argument, 0, 'w'},
        {"fast-fw", required_argument, 0, 'f'},
        {"help",    no_argument,       0, 'h'},
        {0,0,0,0}
    };
    // process options:
    char c;
    int opt_index = 0;
    while ((c = getopt_long(argc, argv, "hs:w:f:", long_opts, &opt_index)) != -1) {
        switch (c) {
            case 'h':
                printf(usage,argv[0]);
                return 0;
            case 's':
                initfilename = optarg;
                break;
            case 'w':
                wfilename = optarg;
                break;
            case 'f':
                max_gen = atoi(optarg);
                break;
            case '?':
                printf(usage,argv[0]);
                return 1;
        }
    }

    /* NOTE: at this point wfilename initfilename and max_gen
     * are all set according to the command line. */
    /* If you wrote the initFromFile function, call it here: */
    vector<vector<bool> > grid=initFromFile(initfilename);
dumpState(wfilename,grid);
    mainLoop();
    return 0;
}

void mainLoop() {
    /* TODO: write this */
    /* update, write, sleep */
      vector<vector<bool> > temp;
      temp = initFromFile(initfilename);
       for(int i=0; i<temp.size(); i++)
    {
        for(int j=0; j<temp[i].size(); j++)
        {
            if(temp[i][j])
            {
                cout<<"0";
            }
            else
            {
                cout<<".";
            }
        }
        cout<<"\n";
    }


    if (max_gen == 0)
    { while(true)
        {
            temp = update(temp);
            dumpState(wfilename,temp);
            sleep(1);
        }

        /* make one generation update per second */
    }
    else

{
    while(max_gen>0)
        {
            temp= update(temp);
            max_gen--;
        }
        for(int i=0;i<temp.size(); i++)
        {
            for(int j=0; j<temp[i].size(); j++)
            {
                if(temp[i][j])
                {
                    cout<<"O";
                }
                else
                {
                    cout<<".";
                }
            }
            cout<<"\n";
        }
            dumpState(wfilename,temp);
        }
}