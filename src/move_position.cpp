#include "move_position.h"
#include "key_event.h"
#include <iostream>

using namespace std;

coordinates Selection(coordinates &coor) {
	int director = 2;
    int select;
    noCursorType();
    gotoXY(48, 12);
    cout << char(16);
    while (coor.y >= 12 && coor.y <= 18)
    {
        if (_kbhit())
        {
            int key = InputKey();
            if (key == 13)
            {
                select = 5;
                break;
            }
            if (key == 's' || key == 'S' || key == KEY_DOWN)
                director = 2;
            else if (key == 'w' || key == 'W' || key == KEY_UP)
                director = 1;
            switch (director)
            {
            case 1:
                coor.y = coor.y - 2;
                break;
            case 2:
                coor.y = coor.y + 2;
                break;
            }
            gotoXY(48, coor.y - 2);
            cout << " ";
            gotoXY(48, coor.y + 2);
            cout << " ";
            if (coor.y >= 12 && coor.y <= 18)
            {
                gotoXY(48, coor.y);
                cout << char(16);
            }
            if (coor.y < 12)
            {
                coor.y = 18;
                gotoXY(48, 10);
                cout << " ";
                gotoXY(48, coor.y);
                cout << char(16);
            }
            if (coor.y > 18)
            {
                coor.y = 12;
                gotoXY(48, 20);
                cout << " ";
                gotoXY(48, coor.y);
                cout << char(16);
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