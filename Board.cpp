#include "palette.h"
#include "Board.h"

#include <curses.h>

GameBoard * BuildBoard(GameSize gameSize)                  //функция возвращающая указатель типа GameBoard
{
    GameBoard * board = new GameBoard;      //выделение динамической памяти под GameBoard и определение на нее указателя *board
    board -> gameSize = gameSize;
    //board -> height = 110;                //ширина игрового поля
    //board -> width = 30;                  //высота игрового поля
    return board;
}

void DestroyBoard(GameBoard * board)      //функция удаления поля принимает указатель board типа GameBoard
{
    delete board;                         //удаление структуры GameBoard из динамической памяти УТОЧНИТЬ!!!!
}

int i = 0;
void PrintBoard(GameBoard * board)        //функция вывода поля принимает указатель board типа GameBoard
{

    if(!board)                            //проверка на nullptr
    {
        return;
    }

    attron(COLOR_PAIR(Board_pol));
    for (int i = 0; i < board -> gameSize.height; ++ i)     //указатель на выстоу игр. поля
    {
        for (int j = 0; j < board -> gameSize.width; ++ j)  //указатель на ширину игр. поля
        {
            move(i, j);                                     //заполнение поля?
            addch(' ');                                     //заполнение поля (функционал из библиотеки)
        }
    }


    if (i == 0)
    {
    mvprintw(24, 0, "///   //////   /////////////   ////////////    //////   //////   ///////   ///////   ////////   ////////   ///");
    ++ i;
    }
    else if (i == 1)
    {
    mvprintw(24, 0, "   ////   ////////   /////////   //////   /////   //////   ///////   //////   ///   ////    ////////  ///    ");
    i = 0;
    }
}

GameState RunBoard(GameBoard * gameBoard, GameBoard::BoardKey key)
{
    (void) gameBoard;
    switch (key)
    {
        case GameBoard::ESC:          //выхрд из игры
        return MENU;
    }
    return BOARD;
}
