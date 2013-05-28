#include <iostream>
#include <cstdlib>
#include <ctime>
#include "poker.h"
#include "game.h"

using namespace std;

int main()
{
    srand(time(NULL));
    rules();
    Combinations pl1, pl2;
    pl1=initialization(pl1);
    pl2=initialization(pl2);
    int *player1=NULL;
    player1=new int[5];
    int *player2=NULL;
    player2=new int[5];
    int *temp=NULL;
    temp=new int [5];
    int move=0;
   /* while(move!=12)
    {
        cout<<"\033[31m\033[47m"<<"Игрок 1"<<endl;
        cout<<"\033[0m"<<"Ход №"<<move+1<<endl;
        pl1=play(pl1, player1, temp);
        results(pl1,pl2);
        cout<<"\033[35m\033[47m"<<"Игрок 2"<<endl;
        cout<<"\033[0m"<<"Ход №"<<move+1<<endl;
        pl2=play(pl2, player2, temp);
        results(pl1,pl2);
        ++move;
    }*/
    cout<<"\033[31m\033[47m"<<"Игрок 1 набрал "<<points(pl1)<<" очков."<<endl;
    cout<<"\033[35m\033[47m"<<"Игрок 2 набрал "<<points(pl2)<<" очков."<<endl;
    points(pl1)>points(pl2)?cout<<"zu":cout<<"xu";

    delete [] player1;
    delete [] player2;
    delete [] temp;

    return 0;
}




