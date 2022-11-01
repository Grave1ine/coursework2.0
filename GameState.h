#ifndef GAMESTATE_H
#define GAMESTATE_H

enum GameState                 //перечисление сосостояния
{
    MENU,
    BOARD,
    EXIT
};

struct GameSize
{
    int width;
    int height;
};

#endif // GAMESTATE_H
