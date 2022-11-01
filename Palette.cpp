#include "palette.h"
#include <curses.h>

void InitPalette()
{
    start_color();                                             //инициализация цветов
    init_pair(Board_pol, COLOR_RED, COLOR_BLUE);               //инициализация палитры (имя из перечисления, цвет символов, цвет фона)
    init_pair(Menu_palett, COLOR_WHITE, COLOR_BLUE);           //цвет шрифта, цвет фона под буквами
    init_pair(Pearson_palett, COLOR_RED, COLOR_YELLOW);        //персонаж
    init_pair(Screen_palett, COLOR_BLUE, COLOR_WHITE);         //заставка
    init_pair(TEXT, COLOR_RED, COLOR_WHITE);                   //цвет шрифта на заставке
    init_pair(Let_palett, COLOR_GREEN, COLOR_YELLOW);                 //препядствие
}
