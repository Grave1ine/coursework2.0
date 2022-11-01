#ifndef PEARSON_H
#define PEARSON_H

#include "GameState.h"

struct Pearson
{
    struct Point         //размер персонажа?
    {
        int x;
        int y;
    };

    enum Direction       //движение
    {
        UP,
        DOWN,
        STAY
    };

    Point bodyBase = {15, 20};
    Point body[4][4] =     {
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
        {{2, 0}, {2, 1}, {2, 2}, {2, 3}},
        {{3, 0}, {3, 1}, {3, 2}, {3, 3}},
    };      //персонаж

    //int PearsonSize;
    Direction direction; //переменная типа
};

Pearson * BuildingPearson();                    //Функция возвращающая указатель типа Pearson
void PrintPearson(Pearson * pearson);           //функция запуска Pearson принимает переменную pearson типа указатель
void DestroyPearson(Pearson * pearson);         //функция удаления   принимает переменную   типа указатель

GameState RunPearson(Pearson * pearson, Pearson::Direction direction); //direction это перечисление типа Direction

bool MovePerson(Pearson * pearson);

#endif // PEARSON_H
