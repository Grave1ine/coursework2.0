#ifndef GAME_H
#define GAME_H

#include "Control.h"
#include "Board.h"
#include "GameState.h"
#include "Menu.h"
#include "Pearson.h"
#include "let.h"
//#include "Screen.h"

struct Game                            //
{
    GameState state;                   //инициализация переменной state типа перечисления GameState?
    GameSize gameSize;
    GameBoard * board;                 //переменная board типа указатель структуры GameBoard
    Menu * menu;
    Pearson * pearson;
    Let * let;
    //Screen * screen;
};

Game * BuildingGame();                 //Функция возвращающая указатель типа Game
void RunGame(Game * game);             //функция запуска игры принимает переменную game типа указатель
void DestroyGame(Game * game);         //функция удаления игры принимает переменную game типа указатель

#endif // GAME_H
