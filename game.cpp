//функции, осуществляющие игровой процесс
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <termios.h>

using namespace std;

void throwing(int *player, int beg, int end)
{
    for(int i=beg; i<end; ++i)
        player[i]=rand()%6+1;
}

void throw_over (int *player, int *temp, int n)
{
    bool check;
    do
    {
        check=false;
        int dice;
        cin>>dice;
        int i=0, j=0;

        while(i<=n)
        {
            if(player[i]==dice)
            {
                check=true;
                ++i;
                dice=0;
            }
            temp[j]=player[i];
            ++i;
            ++j;
        }
    }
    while(!check);
}

void show(int *player, int beg, int end)
{

    for(int i=beg; i<end; ++i)
        cout<<player[i]<<' ';
}

int getch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

Combinations play(Combinations pl, int *player, int *temp) //ход одного игрока
{

    cout<<"Бросок №1"<<endl;
    throwing(player,0, 5);
    show(player,0, 5);
    cout<<endl<<endl;
    for(int attempt=0; attempt<2; ++attempt)
    {
        cout<<"сколько костей перебросить?"<<endl;
        int number;
        do cin>>number;
        while(number<0 || number>5);
        cout<<"какие кости перебросить?"<<endl;
        for(int i=0; i<number; ++i)
        {
            throw_over(player, temp, 5-i);
            for(int j=0; j<5; ++j)
            {
                player[j]=temp[j];
                temp[j]=0;
            }
        }
        cout<<"оставшиеся кости: ";
        show(player, 0, 5-number);
        cout<<endl<<endl<<"Бросок №"<<attempt+2<<endl;
        throwing(player, 5-number, 5);
        show(player, 0, 5);
        cout<<endl<<endl;
    }
    cout<<"выберите комбинацию для записи в таблицу:"<<endl;
    choose(pl,player);
    pl=assign(pl,player);
    system("clear");
    return pl;
}

void click()
{
    char game;
    game=getch();
    switch(game)
    {
    default:
        break;
    }
}

void rules()
{
    char rule;
    ifstream in("rules");
    while (!in.eof())
    {
        in.get(rule);
        cout<<rule;
    }
    in.close();
    cout<<endl<<"\tНажмите любую клавишу, чтобы продолжить";
    click();
    system("clear");
}

void choose(Combinations pl, int *player)
{
    if(pl.comb1==-1)
        cout<<"1. единицы         "<<combination(player, 1)<<endl;
    if(pl.comb2==-1)
        cout<<"2. двойки          "<<combination(player, 2)<<endl;
    if(pl.comb3==-1)
        cout<<"3. тройки          "<<combination(player, 3)<<endl;
    if(pl.comb4==-1)
        cout<<"4. четверки        "<<combination(player, 4)<<endl;
    if(pl.comb5==-1)
        cout<<"5. пятерки         "<<combination(player, 5)<<endl;
    if(pl.comb6==-1)
        cout<<"6. шестерки        "<<combination(player, 6)<<endl;
    if(pl.quads==-1)
        cout<<"7. каре            "<<quads(player)<<endl;
    if(pl.fhouse==-1)
        cout<<"8. фул хаус        "<<fullhouse(player)<<endl;
    if(pl.smstr==-1)
        cout<<"9. короткий стрит  "<<small_straight(player)<<endl;
    if(pl.lgstr==-1)
        cout<<"10. длинный стрит  "<<large_straight	(player)<<endl;
    if(pl.pok==-1)
        cout<<"11. покер          "<<poker(player)<<endl;
    if(pl.chan==-1)
        cout<<"12. любая          "<<chance(player)<<endl;

}

void results(Combinations pl1,Combinations pl2)
{

    cout<<"Комбинация       Игрок 1   Игрок 2"<<endl;
    cout<<"1. единицы         ";
    if(pl1.comb1>=0) cout<<pl1.comb1;
    if(pl2.comb1>=0) cout<<"        "<<pl2.comb1;
    cout<<endl;
    cout<<"2. двойки          ";
    if(pl1.comb2>=0) cout<<pl1.comb2;
    if(pl2.comb2>=0) cout<<"        "<<pl2.comb2;
    cout<<endl;
    cout<<"3. тройки          ";
    if(pl1.comb3>=0) cout<<pl1.comb3;
    if(pl2.comb3>=0) cout<<"        "<<pl2.comb3;
    cout<<endl;
    cout<<"4. четверки        ";
    if(pl1.comb4>=0) cout<<pl1.comb4;
    if(pl2.comb4>=0) cout<<"        "<<pl2.comb4;
    cout<<endl;
    cout<<"5. пятерки         ";
    if(pl1.comb5>=0) cout<<pl1.comb5;
    if(pl2.comb5>=0) cout<<"        "<<pl2.comb5;
    cout<<endl;
    cout<<"6. шестерки        ";
    if(pl1.comb6>=0) cout<<pl1.comb6;
    if(pl2.comb6>=0) cout<<"        "<<pl2.comb6;
    cout<<endl;
    cout<<"7. каре            ";
    if(pl1.quads>=0) cout<<pl1.quads;
    if(pl2.quads>=0) cout<<"        "<<pl2.quads;
    cout<<endl;
    cout<<"8. фул хаус        ";
    if(pl1.fhouse>=0) cout<<pl1.fhouse;
    if(pl2.fhouse>=0) cout<<"        "<<pl2.fhouse;
    cout<<endl;
    cout<<"9. короткий стрит  ";
    if(pl1.smstr>=0) cout<<pl1.smstr;
    if(pl2.smstr>=0) cout<<"        "<<pl2.smstr;
    cout<<endl;
    cout<<"10. длинный стрит  ";
    if(pl1.lgstr>=0) cout<<pl1.lgstr;
    if(pl2.lgstr>=0) cout<<"        "<<pl2.lgstr;
    cout<<endl;
    cout<<"11. покер          ";
    if(pl1.pok>=0) cout<<pl1.pok;
    if(pl2.pok>=0) cout<<"        "<<pl2.pok;
    cout<<endl;
    cout<<"12. любая          ";
    if(pl1.chan>=0) cout<<pl1.chan;
    if(pl2.chan>=0) cout<<"        "<<pl2.chan;
    cout<<endl<<endl;
}

Combinations assign(Combinations pl, int *player)
{
    int comb;
    bool condition;

    do
    {
        condition=0;
        cin>>comb;
        switch(comb)
        {
        case 1:
            if(pl.comb1==-1)
                pl.comb1=combination(player, 1);
            else condition=true;
            break;
        case 2:
            if(pl.comb2==-1)
                pl.comb2=combination(player, 2);
            else condition=true;
            break;
        case 3:
            if(pl.comb3==-1)
                pl.comb3=combination(player, 3);
            else condition=true;
            break;
        case 4:
            if(pl.comb4==-1)
                pl.comb4=combination(player, 4);
            else condition=true;
            break;
        case 5:
            if(pl.comb5==-1)
                pl.comb5=combination(player, 5);
            else condition=true;
            break;
        case 6:
            if(pl.comb6==-1)
                pl.comb6=combination(player, 6);
            else condition=true;
            break;
        case 7:
            if(pl.quads==-1)
                pl.quads=quads(player);
            else condition=true;
            break;
        case 8:
            if(pl.fhouse==-1)
                pl.fhouse=fullhouse(player);
            else condition=true;
            break;
        case 9:
            if(pl.smstr==-1)
                pl.smstr=small_straight(player);
            else condition=true;
            break;
        case 10:
            if(pl.lgstr==-1)
                pl.lgstr=large_straight(player);
            else condition=true;
            break;
        case 11:
            if(pl.pok==-1)
                pl.pok=poker(player);
            else condition=true;
            break;
        case 12:
            if(pl.chan==-1)
                pl.chan=chance(player);
            else condition=true;
            break;
        default:
            condition=true;
            break;
        }
    }
    while(condition);
    return pl;
}

int points(Combinations pl)
{
    return pl.comb1+pl.comb2+pl.comb3+pl.comb4+pl.comb5+pl.comb6+pl.quads+pl.fhouse+pl.smstr+pl.lgstr+pl.pok+pl.chan;
}

Combinations initialization(Combinations pl)
{
    pl.comb1=-1, pl.comb2=-1, pl.comb3=-1, pl.comb4=-1, pl.comb5=-1, pl.comb6=-1,
                                       pl.quads=-1, pl.fhouse=-1,pl.smstr=-1,  pl.lgstr=-1, pl.pok=-1, pl.chan=-1;
    return pl;
}




