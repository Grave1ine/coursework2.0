#ifndef BOARD_H
#define BOARD_H

#include "GameState.h"

struct GameBoard                         //структура игрового пространства
{
    enum BoardKey
    {
        ESC,
    };

    GameSize gameSize;
};

GameBoard * BuildBoard(GameSize gameSize);        //функция возвращающая указатель типа GameBoard
void DestroyBoard(GameBoard * board);    //функция удаления поля принимает указатель board типа GameBoard
void PrintBoard(GameBoard * board);      //функция вывода поля принимает указатель board типа GameBoard

GameState RunBoard(GameBoard * board, GameBoard::BoardKey key);

#endif // BOARD_H
