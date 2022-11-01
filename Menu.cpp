#include "Menu.h"
#include "palette.h"
#include <curses.h>

Menu * BuildingMenu(GameSize gameSize)                  //
{
    Menu * menu = new Menu;
    menu -> gameSize = gameSize;
    menu -> menuString[Menu::STAET_GAME] = "START";          //обращение через расширенную область видимости к полю перечисления в структуре
    menu -> menuString[Menu::TABLE_RECORD] = "TABLE RECORDS";// массив?
    menu -> menuString[Menu::EXIT] = "EXIT";
    menu -> currentPoint = Menu::FirstPoint;                       //местоположение курсора
    return menu;
}

void DestroyMenu(Menu * menu)          //
{
    delete menu;
}

void PrintMenu(Menu * menu)            //
{
    if (!menu)
        {
            return;
        }

    attron(COLOR_PAIR(Menu_palett));                      //включение атрибутов?

    for (int i = 0; i < menu ->gameSize.height; ++ i)     //указатель на выстоу игр. поля
    {
        for (int j = 0; j < menu -> gameSize.width; ++ j) //указатель на ширину игр. поля
        {
            move(i, j);                                   //заполнение поля?
            addch(' ');                                   //заполнение поля (функционал из библиотеки)
        }
    }

    for (int i = 0; i < Menu::COUNT; ++ i)
    {
        mvprintw(13 + i, 55, "%s", menu -> menuString[i]);     //вывыодит строку на экран
    }
    move(menu -> currentPoint, 54);                            //выравнивание по ширине
    addch('>');

    attroff(COLOR_PAIR(Menu_palett));                          //отключение атрибутов?
}

GameState RunMenu(Menu * menu, Menu::MenuKey key)
{
    switch (key)
    {
    case Menu::UP:
        if(menu -> currentPoint != Menu::FirstPoint)
            {
             -- menu -> currentPoint;
            }
    return MENU;
    case Menu::DOWN:
        if(menu -> currentPoint != Menu::LastPoint)
            {
             ++ menu -> currentPoint;
            }
    return MENU;
    case Menu::ENTER:
    {
        switch (menu -> currentPoint)
            {
            case Menu::FirstPoint:
            return BOARD;
            case Menu::TABLE_RECORD:
            return MENU;
            case 15:
            return EXIT;
            default :
            break;
            }
    }
    }
    return MENU;
}
