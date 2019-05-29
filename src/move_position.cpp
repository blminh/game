#include "move_position.h"
#include "key_event.h"
#include <iostream>

coordinates Selection(coordinates &coor) {
    DIRECTOR_OPT director = DOWN;
    int select;

    noCursorType();
    gotoXY(48, 12);
    std::cout << char(16);

    while (coor.y >= 12 && coor.y <= 18) {
        if (_kbhit()) {
            int key = InputKey();

            if (key == 13) {
                select = 5;
                break;
            }

            if (key == 's' || key == 'S' || key == KEY_DOWN)
                director = DOWN;
            else if (key == 'w' || key == 'W' || key == KEY_UP)
                director = UP;

            switch (director) {
                case UP:
                    coor.y = coor.y - 2;
                    break;
                case DOWN:
                    coor.y = coor.y + 2;
                    break;
            }

            gotoXY(48, coor.y - 2);
            std::cout << " ";
            gotoXY(48, coor.y + 2);
            std::cout << " ";

            if (coor.y >= 12 && coor.y <= 18) {
                gotoXY(48, coor.y);
                std::cout << char(16);
            }
            if (coor.y < 12) {
                coor.y = 18;
                gotoXY(48, 10);
                std::cout << " ";
                gotoXY(48, coor.y);
                std::cout << char(16);
            }
            if (coor.y > 18) {
                coor.y = 12;
                gotoXY(48, 20);
                std::cout << " ";
                gotoXY(48, coor.y);
                std::cout << char(16);
            }
        }
    }

    if (coor.y == 12 && select == 5)
        coor.y = 12;
    else if (coor.y == 14 && select == 5)
        coor.y = 14;
    else if (coor.y == 16 && select == 5)
        coor.y = 16;
    else if (coor.y == 18 && select == 5)
        coor.y = 18;

    return coor;
}