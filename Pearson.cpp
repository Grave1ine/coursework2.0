#include "Pearson.h"
#include "palette.h"
#include "Game.h"
#include <curses.h>

Pearson * BuildingPearson()
{
    Pearson * pearson = new Pearson;       //выделение динамической памяти
    //pearson->PearsonSize = 1;
    pearson->direction = Pearson::STAY;
    return pearson;
}

void PrintPearson(Pearson * pearson)
{
    if (!pearson)
    {
        return;
    }

    attron(COLOR_PAIR(Pearson_palett));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            move(pearson->bodyBase.y + pearson->body[i][j].y,
                 pearson->bodyBase.x + pearson->body[i][j].x);
            addch('0');
        }
    }
}

void DestroyPearson(Pearson * pearson)
{
    delete pearson;
}

GameState RunPearson(Pearson * pearson, Pearson::Direction direction) //direction это перечисление типа Direction
{
    if (!pearson)
    {
        return GameState::BOARD;
    }
    pearson->direction = direction;
    if(!MovePerson(pearson))
    {
        return GameState::EXIT;
    }
    return GameState::BOARD;
}

bool MovePerson(Pearson * pearson)
{
    if (!pearson)
    {
        return false;
    }
    switch (pearson->direction)
    {
    case Pearson::UP:
        if (pearson->bodyBase.y > 10)    //высота
        {
            --pearson->bodyBase.y;
        } else {
            pearson->direction = Pearson::DOWN;
        }
        break;
    case Pearson::DOWN:
        if (pearson->bodyBase.y <= 19)   //позиция на которую вернется
        {
            ++pearson->bodyBase.y;
        } else {
            pearson->direction = Pearson::STAY;
        }
        break;
    default:
        break;
    }
    return true;
}


