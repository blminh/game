#include "Menu.h"
#include "key_event.h"
#include "move_position.h"
#include <iostream>

int Menu() {
    int select;
    // VeChu('a', 1); VeChu('i', 1); VeChu('l', 1); VeChu('a', 2); VeChu('t', 1); VeChu('r', 1); 
    // VeChu('i', 2); VeChu('e', 1); VeChu('u', 1); VeChu('p', 1); VeChu('h', 1); VeChu('u', 2);
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
        select = 1;
    else if (coor.y == 14)
        select = 2;
    else if (coor.y == 16)
        select = 3;
    else if (coor.y == 18)
        select = 4;
    return select;
}