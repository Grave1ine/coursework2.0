#include "Game.h"
#include "palette.h"
#include <stdlib.h>

#include <curses.h>

void BuildingGameSubModels(Game * game)
{
    if (!game)                         //проверка на nullptr (можно if(game == nullptr))
        {
            return;
        }

    switch (game -> state)             //выбор между меню и игрой
        {
        case MENU:
            PrintMenu(game -> menu);
        break;
        case BOARD:
            PrintBoard(game -> board);
            PrintPearson(game -> pearson);
        break;
        case EXIT:
        return;
        }
}

GameState StartGameSubModels(Game * game)
{
    if (!game)                         //проверка на nullptr (можно if(game == nullptr))
        {
            return MENU;
        }

    int ch = getch();                  //нажатие клавиши

    switch (game -> state)             //выбор между меню и игрой
        {
            case MENU:
            Menu::MenuKey menuKay;     //переназвали клавишу???
            switch (ch)
                {
                    case KEY_UP:
                    menuKay = Menu::UP;
                    break;
                    case KEY_DOWN:
                    menuKay = Menu::DOWN;
                    break;
                    case 10:               //ENTER
                    menuKay = Menu::ENTER;
                    break;
                    default:
                    return game -> state;
                    }
                    return RunMenu(game -> menu, menuKay);
                    case BOARD:

                switch (ch)
                {
                    case 27:
                    return RunBoard(game -> board, GameBoard::ESC);
                    case 32: //spase
                    return RunPearson(game -> pearson, Pearson::UP);       //прописывается пробел
                    case -1:
                    return RunPearson(game -> pearson, game->pearson->direction);
                    default:
                    return game -> state;
                }
            case EXIT:
            exit(0);
        }
}

Game * BuildingGame()                      //Функция возвращающая указатель типа Game
    {
        initscr();                         //включение графической библиотеки
        keypad(stdscr, TRUE);              //обработка командных клавиш (стрелки)
        curs_set(0);                       //убирает мигающий курсор в консоли
        InitPalette();
        noecho();
        halfdelay(1);                      //если клавиша не нажата, значит нажата предыдущая


        Game * game = new Game;            //выделение динамической памяти под Game и определение указателя *game, структура динамическая у нее нет имени
        game -> state = MENU;              //обращение к перечислению state к полю MENU
        game -> gameSize = {110, 30};      //размер игровой доски
        game -> board = BuildBoard(game -> gameSize);      //присваивает значение BuildBoard в указатель board который лежит в динамической памяти структуры Game
        game -> menu = BuildingMenu(game -> gameSize);     //создается меню
        game -> pearson = BuildingPearson();
        game -> let = BuildingLet();
        return game;                       //возвращает адрес структуры Game
    }

void DestroyGame(Game * game)          //функция удаления игры принимает переменную game типа указатель
{
    if (!game)                         //проверка на nullptr (если не ссылается на ноль то)
        {
            return;
        }
    DestroyLet(game -> let);
    DestroyPearson(game -> pearson);
    DestroyMenu(game -> menu);         //удаление меню
    DestroyBoard(game -> board);       //функция DestroyBoard принимает значение
    delete game;                       //удаление игры
    endwin();                          //отключение графической библиотеки
}

void RunGame(Game * game)              //функция запуска игры принимает переменную game типа указатель
{
    while (game -> state != EXIT)      //если не EXIT то
        {
            BuildingGameSubModels(game);                //отрисовка текущего состояния
            game -> state = StartGameSubModels(game);
        }
}


