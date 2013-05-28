//функции, связанные с подсчетом очков за комбинации
#include "poker.h"
#include "sort.h"

int combination(int *player, int number)
{
    int sum=0;
    for(int i=0; i<5; ++i)
        if(player[i]==number)
            sum+=player[i];
    return sum;
}

int quads(int *player)
{
    sort(player, 0, 4);
    int sum=0, count=0;
    for(int i=0; i<3; i++)
    {
        if(player[i]==player[i+1])
            ++count;
    }
    if(count==3)
    {
        for(int i=0; i<5; i++)
            sum+=player[i];
        return sum;
    }
    else
    {
        count=0;
        for(int i=4; i>1; i--)
        {
            if(player[i]==player[i-1])
                ++count;
        }
        if(count==3)
        {
            for(int i=0; i<5; i++)
                sum+=player[i];
            return sum;
        }
    }
    return sum;
}

int fullhouse(int *player)
{
    sort(player, 0, 4);
    int sum=0;
    int count=0;
    if(player[0]==player[1])
        for(int i=2; i<4; ++i)
            if(player[i]==player[i+1])
                ++count;
    if(count!=2)
    {
        count=0;
        if(player[3]==player[4])
            for(int i=0; i<2; ++i)
                if(player[i]==player[i+1])
                    ++count;
    }
    if(count==2)
        for(int i=0; i<5; i++)
            sum+=player[i];
    return sum;
}

int small_straight(int *player)
{
    int count=0, sum=0;
    sort(player, 0, 4);
    for(int i=0; i<4; i++)
    {
        if(player[i]==player[i+1]-1)
            ++count;
        else if (i+1!=4 && player[i]!=player[i+1])
            count=0;
    }

    if(count>=3)
    {
        sum=25;
    }
    return sum;
}

int large_straight(int *player)
{
    int count=0, sum=0;
    sort(player, 0, 4);
    for(int i=0; i<4; ++i)
        if(player[i]==player[i+1]-1)
            ++count;
    if(count==4)
        sum=30;
    return sum;
}

int poker(int *player)
{
    int count=0, sum=0;
    for(int i=0; i<4; ++i)
        if(player[i]==player[i+1])
            ++count;
    if(count==4)
        sum=50;
    return sum;
}

int chance(int *player)
{
    int sum=0;
    for(int i=0; i<5; ++i)
        sum+=player[i];
    return sum;
}

