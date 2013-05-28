//функции сортировки
#include "sort.h"

int partition(int *player, int l, int r)
{
    int i,j;
    int temp;
    i=l;
    while(player[i]<player[r]) ++i;
    for(j=i; j<r; ++j)
    {
        if(player[j]<player[r])
        {
            temp=player[j];
            player[j]=player[i];
            player[i]=temp;
            ++i;
        }
    }
    temp=player[i];
    player[i]=player[r];
    player[r]=temp;
    return i;
}

void sort(int *player, int l, int r)
{
    int m;
    if(l<r)
    {
        m=partition(player,l,r);
        sort(player,l,m-1);
        sort(player,m+1,r);
    }
}
