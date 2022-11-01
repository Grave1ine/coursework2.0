#ifndef LET_H
#define LET_H

struct Let
{
    struct Point         //размер препядствия?
    {
        int x;
        int y;
    };

    Point LetBase = {15, 50};
    Point LetMass[4][2] =     {
        {{0, 0}, {0, 1}},
        {{1, 0}, {1, 1}},
        {{2, 0}, {2, 1}},
        {{3, 0}, {3, 1}},
    };                  //препядствие

};

Let * BuildingLet();                //Функция возвращающая указатель типа
void PrintLet(Let * let);           //функция запуска Pearson принимает переменную pearson типа указатель
void DestroyLet(Let * let);         //функция удаления   принимает переменную   типа указатель

//GameState RunPearson(Pearson * pearson, Pearson::Direction direction); //direction это перечисление типа Direction

//bool MovePerson(Pearson * pearson);

#endif // LET_H


