#ifndef POKER_INCLUDED
#define POKER_INCLUDED

struct Combinations //хранение очков за разные комбинации
{
    int comb1;
    int comb2;
    int comb3;
    int comb4;
    int comb5;
    int comb6;
    int quads;
    int fhouse;
    int smstr;
    int lgstr;
    int pok;
    int chan;
};

int combination(int *player, int number); //посчитать количество очков за комбинации 1-6
int quads(int *player); //каре
int fullhouse(int *player); //фул хаус
int small_straight(int *player); //короткий стрит
int large_straight(int *player); //длинный стрит
int poker(int *player); //покер
int chance(int *player); //любая

#endif // POKER_INCLUDED

