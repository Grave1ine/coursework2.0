#ifndef MENU_H
#define MENU_H

#include "GameState.h"

struct Menu
{
    enum MenuKey
    {
        UP,
        DOWN,
        ENTER
    };

    enum MenuPoint                     //перечисление полей меню
    {
        STAET_GAME,
        TABLE_RECORD,
        EXIT,
/**********************/
        COUNT,                         //счетчик перечислений
        FirstPoint = 13,               //начало отсчета для курсора(START_GAME)
        LastPoint = 15                 //конец отсчета для курсора(EXIT)
    };
    int currentPoint;

    const char * menuString[COUNT];    //массив указателей
    GameSize gameSize;
};

Menu * BuildingMenu(GameSize gameSize);//Функция возвращающая указатель типа Menu
void PrintMenu(Menu * menu);           //функция запуска меню принимает переменную menu типа указатель
void DestroyMenu(Menu * menu);         //функция удаления меню принимает переменную menu типа указатель

//принимает нажатую клавишу
//по тому как клавиша нажата должна модифицировать меню
//возвращать новое значение

GameState RunMenu(Menu * menu, Menu::MenuKey key); //key это перечисление типа MenuKey

#endif // MENU_H
