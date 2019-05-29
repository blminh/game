#include "Menu.h"
#include "key_event.h"
#include "move_position.h"
#include <iostream>

MENU_OPT Menu() {
    MENU_OPT select = UNDEFINE;

    gotoXY(50, 12);
    std::cout << "VAO GAME";
    gotoXY(50, 14);
    std::cout << "DIEM CAO NHAT";
    gotoXY(50, 16);
    std::cout << "HUONG DAN";
    gotoXY(50, 18);
    std::cout << "THOAT";

    coordinates coor;
    coor.x = 48;
    coor.y = 12;
    Selection(coor);

    if (coor.y == 12)
        select = VAO_GAME;
    else if (coor.y == 14)
        select = DIEM_CAO_NHAT;
    else if (coor.y == 16)
        select = HUONG_DAN;
    else if (coor.y == 18)
        select = THOAT;

    return select;
}