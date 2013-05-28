#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "poker.h"

void throwing(int *player, int beg, int end); //бросок костей
void throw_over (int *player, int *temp, int n); //отбрасывание кости
void show(int *player, int beg, int end); //показать набор костей
Combinations play(Combinations pl, int *player, int *temp);
void click();
void rules();
void choose(Combinations pl, int *player); //показать комбинации, которые можно записать
void results(Combinations pl1, Combinations pl2); //показать результаты
Combinations assign(Combinations pl, int *player);  //выбор комбинации для записи
int points(Combinations pl); //подсчет итоговых очков
Combinations initialization(Combinations pl); //присваивание начальных значений

#endif // GAME_H_INCLUDED
