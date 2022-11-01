#include "let.h"
#include "palette.h"
#include "Game.h"

#include <curses.h>

Let * BuildingLet()
{
    Let * let = new Let;       //выделение динамической памяти
    return let;
}

void PrintLet(Let * let)
{
    if (!let)
    {
        return;
    }
    attron(COLOR_PAIR(Let_palett));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            move(let->LetBase.y + let->LetMass[i][j].y,
                 let->LetBase.x + let->LetMass[i][j].x);
            addch('*');
        }
    }
}

void DestroyLet(Let * let)
{
    delete let;
}
